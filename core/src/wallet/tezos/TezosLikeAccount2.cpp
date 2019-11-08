/*
 *
 * TezosLikeAccount
 *
 * Created by El Khalil Bellakrid on 27/04/2019.
 *
 * The MIT License (MIT)
 *
 * Copyright (c) 2019 Ledger
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in all
 * copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 * SOFTWARE.
 *
 */


#include "TezosLikeAccount.h"
#include "TezosLikeWallet.h"
#include <soci.h>
#include <database/soci-number.h>
#include <database/soci-date.h>
#include <database/soci-option.h>
#include <api/TezosLikeAddress.hpp>
#include <api/TezosOperationTag.hpp>
#include <async/Future.hpp>
#include <wallet/common/database/OperationDatabaseHelper.h>
#include <wallet/common/database/BlockDatabaseHelper.h>
#include <wallet/common/synchronizers/AbstractBlockchainExplorerAccountSynchronizer.h>
#include <wallet/pool/database/CurrenciesDatabaseHelper.hpp>
#include <wallet/tezos/api_impl/TezosLikeTransactionApi.h>
#include <wallet/tezos/database/TezosLikeAccountDatabaseHelper.h>
#include <wallet/tezos/database/TezosLikeTransactionDatabaseHelper.h>
#include <wallet/tezos/explorers/TezosLikeBlockchainExplorer.h>
#include <wallet/tezos/transaction_builders/TezosLikeTransactionBuilder.h>
#include <wallet/tezos/delegation/TezosLikeOriginatedAccount.h>
#include <events/Event.hpp>
#include <math/Base58.hpp>
#include <utils/Option.hpp>
#include <utils/DateUtils.hpp>
#include <collections/vector.hpp>
#include <database/query/ConditionQueryFilter.h>
#include <api/TezosConfiguration.hpp>
#include <api/TezosConfigurationDefaults.hpp>
#include <api/TezosLikeTransaction.hpp>

using namespace soci;

namespace ledger {
    namespace core {


        Future<api::ErrorCode> TezosLikeAccount::eraseDataSince(const std::chrono::system_clock::time_point &date) {
            auto log = logger();
            log->debug(" Start erasing data of account : {}", getAccountUid());
            soci::session sql(getWallet()->getDatabase()->getPool());
            //Update account's internal preferences (for synchronization)
            auto savedState = getInternalPreferences()->getSubPreferences("BlockchainExplorerAccountSynchronizer")->getObject<BlockchainExplorerAccountSynchronizationSavedState>("state");
            if (savedState.nonEmpty()) {
                //Reset batches to blocks mined before given date
                auto previousBlock = BlockDatabaseHelper::getPreviousBlockInDatabase(sql,
                                                                                     getWallet()->getCurrency().name,
                                                                                     date);
                for (auto &batch : savedState.getValue().batches) {
                    if (previousBlock.nonEmpty() && batch.blockHeight > previousBlock.getValue().height) {
                        batch.blockHeight = (uint32_t) previousBlock.getValue().height;
                        batch.blockHash = previousBlock.getValue().blockHash;
                    } else if (!previousBlock.nonEmpty()) {//if no previous block, sync should go back from genesis block
                        batch.blockHeight = 0;
                        batch.blockHash = "";
                    }
                }
                getInternalPreferences()->getSubPreferences("BlockchainExplorerAccountSynchronizer")->editor()->putObject<BlockchainExplorerAccountSynchronizationSavedState>("state", savedState.getValue())->commit();
            }
            auto accountUid = getAccountUid();
            sql << "DELETE FROM operations WHERE account_uid = :account_uid AND date >= :date ", soci::use(
                    accountUid), soci::use(date);
            log->debug(" Finish erasing data of account : {}", accountUid);
            return Future<api::ErrorCode>::successful(api::ErrorCode::FUTURE_WAS_SUCCESSFULL);

        }

        bool TezosLikeAccount::isSynchronizing() {
            std::lock_guard<std::mutex> lock(_synchronizationLock);
            return _currentSyncEventBus != nullptr;
        }

        std::shared_ptr<api::EventBus> TezosLikeAccount::synchronize() {
            std::lock_guard<std::mutex> lock(_synchronizationLock);
            if (_currentSyncEventBus)
                return _currentSyncEventBus;
            auto eventPublisher = std::make_shared<EventPublisher>(getContext());

            _currentSyncEventBus = eventPublisher->getEventBus();
            auto self = std::static_pointer_cast<TezosLikeAccount>(shared_from_this());
            auto future = _synchronizer->synchronize(self)->getFuture();

            //Update current block height (needed to compute trust level)
            _explorer->getCurrentBlock().onComplete(getContext(),
                                                    [](const TryPtr<TezosLikeBlockchainExplorer::Block> &block) mutable {
                                                        if (block.isSuccess()) {
                                                            //TODO
                                                        }
                                                    });

            auto startTime = DateUtils::now();
            eventPublisher->postSticky(std::make_shared<Event>(api::EventCode::SYNCHRONIZATION_STARTED, api::DynamicObject::newInstance()), 0);
            future.flatMap<Unit>(getContext(), [self] (const Try<Unit> &result) {
                        // Synchronize originated accounts ...
                        // Notes: We should rid of this part by implementing support for fetching
                        // txs for multiple addresses
                        // Hint: we could add originated accounts to keychain as
                        // managedAccounts and getAllObservableAddresses will return them as well
                        if (self->_originatedAccounts.empty() || result.isFailure()) {
                            return Future<Unit>::successful(result.getValue());
                        }

                        using TxsBulk = TezosLikeBlockchainExplorer::TransactionsBulk;

                        static std::function<Future<Unit> (std::shared_ptr<TezosLikeAccount>, size_t)> getTxs =
                                [] (const std::shared_ptr<TezosLikeAccount> &account, size_t id) -> Future<Unit> {
                                    std::vector<std::string> addresses{account->_originatedAccounts[id]->getAddress()};
                                    // TODO: Get info of last fetched block
                                    // For the moment we start synchro from the beginning
                                    return account->_explorer->getTransactions(addresses)
                                            .flatMap<Unit>(account->getContext(), [=] (const std::shared_ptr<TxsBulk> &bulk) {
                                                auto uid = TezosLikeAccountDatabaseHelper::createOriginatedAccountUid(account->getAccountUid(), addresses[0]);
                                                {
                                                    soci::session sql(account->getWallet()->getDatabase()->getPool());
                                                    soci::transaction tr(sql);
                                                    for (auto &tx : bulk->transactions) {
                                                        account->putTransaction(sql, tx, uid, addresses[0]);
                                                    }
                                                    tr.commit();
                                                    if (id == account->_originatedAccounts.size() - 1) {
                                                        return Future<Unit>::successful(Unit());
                                                    }
                                                }
                                                return getTxs(account, id + 1);
                                            }).recover(account->getContext(), [] (const Exception& ex) -> Unit {
                                                throw ex;
                                            });
                                };
                        return getTxs(self, 0);
                    })
                    .onComplete(getContext(), [eventPublisher, self, startTime](const Try<Unit> &result) {
                        api::EventCode code;
                        auto payload = std::make_shared<DynamicObject>();
                        auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(
                                DateUtils::now() - startTime).count();
                        payload->putLong(api::Account::EV_SYNC_DURATION_MS, duration);
                        if (result.isSuccess()) {
                            code = api::EventCode::SYNCHRONIZATION_SUCCEED;
                        } else {
                            code = api::EventCode::SYNCHRONIZATION_FAILED;
                            payload->putString(api::Account::EV_SYNC_ERROR_CODE,
                                               api::to_string(result.getFailure().getErrorCode()));
                            payload->putInt(api::Account::EV_SYNC_ERROR_CODE_INT, (int32_t) result.getFailure().getErrorCode());
                            payload->putString(api::Account::EV_SYNC_ERROR_MESSAGE, result.getFailure().getMessage());
                        }
                        eventPublisher->postSticky(std::make_shared<Event>(code, payload), 0);
                        std::lock_guard<std::mutex> lock(self->_synchronizationLock);
                        self->_currentSyncEventBus = nullptr;
                    });
            return eventPublisher->getEventBus();
        }

        std::shared_ptr<TezosLikeAccount> TezosLikeAccount::getSelf() {
            return std::dynamic_pointer_cast<TezosLikeAccount>(shared_from_this());
        }

        void TezosLikeAccount::startBlockchainObservation() {
            _observer->registerAccount(getSelf());
        }

        void TezosLikeAccount::stopBlockchainObservation() {
            _observer->unregisterAccount(getSelf());
        }

        bool TezosLikeAccount::isObservingBlockchain() {
            return _observer->isRegistered(getSelf());
        }

        std::string TezosLikeAccount::getRestoreKey() {
            return _keychain->getRestoreKey();
        }

        void TezosLikeAccount::broadcastRawTransaction(const std::vector<uint8_t> &transaction,
                                                       const std::shared_ptr<api::StringCallback> &callback) {
            _explorer->pushTransaction(transaction)
                    .map<std::string>(getContext(),
                                      [](const String &seq) -> std::string {
                                          //TODO: optimistic update
                                          return seq.str();
                                      })
                    .recoverWith(getContext(), [] (const Exception &e) {
                        // Avoid fmt error because of JSON string
                        const auto error = "Failed to broadcast raw transaction, reason " + e.getMessage();
                        return Future<std::string>::failure(
                                Exception(api::ErrorCode::INCOMPLETE_TRANSACTION, error)
                        );
                    })
                    .callback(getContext(), callback);
        }

        void TezosLikeAccount::broadcastTransaction(const std::shared_ptr<api::TezosLikeTransaction> &transaction,
                                                    const std::shared_ptr<api::StringCallback> &callback) {
            broadcastRawTransaction(transaction->serialize(), callback);
        }

        std::shared_ptr<api::TezosLikeTransactionBuilder> TezosLikeAccount::buildTransaction() {
            return buildTransaction(std::dynamic_pointer_cast<TezosLikeAddress>(getKeychain()->getAddress())->toString());
        }

        std::shared_ptr<api::TezosLikeTransactionBuilder> TezosLikeAccount::buildTransaction(const std::string &senderAddress) {
            auto self = std::dynamic_pointer_cast<TezosLikeAccount>(shared_from_this());
            auto buildFunction = [self, senderAddress](const TezosLikeTransactionBuildRequest &request,
                                                       const std::shared_ptr<TezosLikeBlockchainExplorer> &explorer) {
                // Check if balance is sufficient
                auto currency = self->getWallet()->getCurrency();
                auto accountAddress = TezosLikeAddress::fromBase58(senderAddress, currency);
                return explorer->getBalance(std::vector<std::shared_ptr<TezosLikeAddress>>{accountAddress}).flatMapPtr<api::TezosLikeTransaction>(
                        self->getContext(),
                        [self, request, explorer, accountAddress, currency, senderAddress](const std::shared_ptr<BigInt> &balance) {
                            // Check if all needed values are set
                            if (!request.gasLimit || !request.storageLimit || !request.fees
                                || (!request.value && !request.wipe)) {
                                throw make_exception(api::ErrorCode::INVALID_ARGUMENT,
                                                     "Missing mandatory informations (e.g. gasLimit, gasPrice or value).");
                            }

                            // Check if recepient is revealed or not
                            // because if not we have to add additional fees equal to storage_limit (in mXTZ)
                            auto getRevealFee = [self, explorer, request]() -> Future<BigInt> {
                               if (request.type != api::TezosOperationTag::OPERATION_TAG_TRANSACTION) {
                                   return Future<BigInt>::successful(BigInt::ZERO);
                               }
                                return explorer->getManagerKey(request.toAddress).map<BigInt>(self->getContext(), [request] (const std::string &managerKey) -> BigInt {
                                    // Base unit is uXTZ
                                    return !managerKey.empty() ? BigInt::ZERO : *request.storageLimit * BigInt("1000");
                                });
                            };

                            return getRevealFee()
                                    .flatMapPtr<api::TezosLikeTransaction>(self->getContext(), [=]
                                            (const BigInt &burned) {
                                        auto managerAddress = self->getKeychain()->getAddress()->toString();
                                        auto protocolUpdate = self->getWallet()
                                                ->getConfiguration()
                                                ->getString(api::TezosConfiguration::TEZOS_PROTOCOL_UPDATE)
                                                .value_or("");

                                        auto tx = std::make_shared<TezosLikeTransactionApi>(currency, protocolUpdate);
                                        // Balance is used only for origination which is always performed from implicit accounts
                                        // In that case senderAddress == self->_keychain->getAddress() so safe to do so
                                        tx->setBalance(*balance);

                                        // Check whether we need a reveal operation
                                        // Note: we can't rely on DB + sent transactions, because
                                        // it is possible to have deleted accounts that hit 0 balance
                                        // during Babylon update (arf ...)
                                        return explorer->getManagerKey(senderAddress).flatMapPtr<api::TezosLikeTransaction>(self->getContext(), [=] (const std::string &managerKey) {
                                            tx->reveal(managerKey.empty());

                                            // Check for balance
                                            // Multiply by 2 fees, since in case of reveal op, we input same fees as the ones used
                                            // for transaction op
                                            auto fees = burned +
                                                        (tx->toReveal() ? *request.fees * BigInt(static_cast<unsigned long long>(2)) : *request.fees);
                                            auto maxPossibleAmountToSend = *balance - fees;
                                            auto amountToSend = request.wipe ? BigInt::ZERO : *request.value;
                                            if (maxPossibleAmountToSend < amountToSend) {
                                                throw make_exception(api::ErrorCode::NOT_ENOUGH_FUNDS, "Cannot gather enough funds.");
                                            }

                                            tx->setValue(request.wipe ? std::make_shared<BigInt>(maxPossibleAmountToSend) : request.value);
                                            // Burned XTZs are not part of the fees
                                            // And if we have a reveal operation, it will be doubled automatically
                                            // since we serialize 2 ops with same fees
                                            tx->setFees(request.fees);
                                            tx->setGasLimit(request.gasLimit);
                                            tx->setStorage(request.storageLimit);

                                            tx->setSender(accountAddress);
                                            tx->setReceiver(TezosLikeAddress::fromBase58(request.toAddress, currency));
                                            tx->setSigningPubKey(self->getKeychain()->getPublicKey().getValue());
                                            tx->setManagerAddress(managerAddress);
                                            tx->setType(request.type);
                                            const auto counterAddress = protocolUpdate == api::TezosConfigurationDefaults::TEZOS_PROTOCOL_UPDATE_BABYLON ?
                                                                        managerAddress : senderAddress;
                                            return explorer->getCounter(counterAddress).flatMapPtr<Block>(self->getContext(), [self, tx, explorer] (const std::shared_ptr<BigInt> &counter) {
                                                if (!counter) {
                                                    throw make_exception(api::ErrorCode::RUNTIME_ERROR, "Failed to retrieve counter from network.");
                                                }
                                                // We should increment current counter
                                                tx->setCounter(std::make_shared<BigInt>(++(*counter)));
                                                return explorer->getCurrentBlock();
                                            }).flatMapPtr<api::TezosLikeTransaction>(self->getContext(), [self, explorer, tx, senderAddress] (const std::shared_ptr<Block> &block) {
                                                tx->setBlockHash(block->hash);
                                                if (senderAddress.find("KT1") == 0) {
                                                    // HACK: KT Operation we use forge endpoint
                                                    return explorer->forgeKTOperation(tx).mapPtr<api::TezosLikeTransaction>(self->getContext(), [tx] (const std::vector<uint8_t> &rawTx) {
                                                        tx->setRawTx(rawTx);
                                                        return tx;
                                                    });
                                                }
                                                return FuturePtr<api::TezosLikeTransaction>::successful(tx);
                                            });
                                        });
                                    });
                        });
            };
            return std::make_shared<TezosLikeTransactionBuilder>(senderAddress,
                                                                 getContext(),
                                                                 getWallet()->getCurrency(),
                                                                 _explorer,
                                                                 logger(),
                                                                 buildFunction,
                                                                 getWallet()
                                                                         ->getConfiguration()
                                                                         ->getString(api::TezosConfiguration::TEZOS_PROTOCOL_UPDATE).value_or("")
            );
        }

        void TezosLikeAccount::addOriginatedAccounts(soci::session &sql, const std::vector<TezosLikeOriginatedAccountDatabaseEntry> &originatedEntries) {
            auto self = std::dynamic_pointer_cast<TezosLikeAccount>(shared_from_this());
            for (auto &originatedEntry : originatedEntries) {
                auto newOriginatedAccount = std::make_shared<TezosLikeOriginatedAccount>(originatedEntry.uid,
                                                                                    originatedEntry.address,
                                                                                    self, originatedEntry.spendable,
                                                                                    originatedEntry.delegatable,
                                                                                    originatedEntry.publicKey);
                _originatedAccounts.push_back(newOriginatedAccount);
            }
        }

        void TezosLikeAccount::getFees(const std::shared_ptr<api::BigIntCallback> & callback) {
            getFees().mapPtr<api::BigInt>(getContext(), [] (const std::shared_ptr<BigInt> &fees) -> std::shared_ptr<api::BigInt>
            {
                if (!fees) {
                    throw make_exception(api::ErrorCode::RUNTIME_ERROR, "Failed to retrieve fees from network");
                }
                return std::make_shared<api::BigIntImpl>(*fees);
            }).callback(getContext(), callback);
        }

        FuturePtr<BigInt> TezosLikeAccount::getFees() {
            return _explorer->getFees();
        }

    }
}
