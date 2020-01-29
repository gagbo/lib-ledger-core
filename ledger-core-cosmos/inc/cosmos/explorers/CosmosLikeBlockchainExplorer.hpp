/*
 *
 * CosmosLikeBlockchainExplorer
 *
 * Created by El Khalil Bellakrid on 14/06/2019.
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


#ifndef LEDGER_CORE_COSMOSLIKEBLOCKCHAINEXPLORER_H
#define LEDGER_CORE_COSMOSLIKEBLOCKCHAINEXPLORER_H


#include <string>

#include <core/api/DynamicObject.hpp>
#include <core/api/ExecutionContext.hpp>
#include <core/async/DedicatedContext.hpp>
#include <core/collections/DynamicObject.hpp>
#include <core/math/BigInt.hpp>
#include <core/net/HttpClient.hpp>
#include <core/utils/ConfigurationMatchable.hpp>
#include <core/utils/Option.hpp>
#include <core/wallet/Block.hpp>

#include <cosmos/keychains/CosmosLikeKeychain.hpp>
#include <cosmos/cosmos.hpp>
#include <cosmos/api/CosmosLikeNetworkParameters.hpp>
#include <cosmos/api/CosmosLikeTransaction.hpp>

namespace ledger {
    namespace core {

        class CosmosLikeBlockchainExplorer : public ConfigurationMatchable {
        public:
            typedef ledger::core::Block Block;
            typedef std::string TransactionFilter;

            using TransactionList = std::list<std::shared_ptr<cosmos::Transaction>>;

            CosmosLikeBlockchainExplorer(
                const std::shared_ptr<ledger::core::api::DynamicObject>
                    &configuration,
                const std::vector<std::string> &matchableKeys);


            virtual const std::vector<TransactionFilter>& getTransactionFilters() = 0;
            virtual FuturePtr<cosmos::Block> getBlock(uint64_t& blockHeight) = 0;
            virtual FuturePtr<cosmos::Account> getAccount(const std::string& account) = 0;
            virtual FuturePtr<cosmos::Block> getCurrentBlock() = 0;
			virtual Future<cosmos::TransactionList> getTransactions(
			        const std::string& address, TransactionFilter& filter,
			        int page, int limit) = 0;
        };
    }
}


#endif //LEDGER_CORE_COSMOSLIKEBLOCKCHAINEXPLORER_H