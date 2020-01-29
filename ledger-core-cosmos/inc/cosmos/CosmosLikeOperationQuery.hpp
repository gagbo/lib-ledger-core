/*
 *
 * CosmosLikeOperationQuery
 *
 * Created by Gerry Agbobada on 22/01/2020
 *
 * The MIT License (MIT)
 *
 * Copyright (c) 2020 Ledger
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

#pragma once

#include <cosmos/api/CosmosLikeTransaction.hpp>
#include <cosmos/explorers/CosmosLikeBlockchainExplorer.hpp>
#include <cosmos/api_impl/CosmosLikeOperation.hpp>

#include <core/operation/Operation.hpp>
#include <core/operation/OperationQuery.hpp>
#include <core/wallet/AbstractWallet.hpp>

namespace ledger {
        namespace core {

                class CosmosLikeOperationQuery : public OperationQuery<CosmosLikeOperation> {
                        public:
                                CosmosLikeOperationQuery(const std::shared_ptr<api::QueryFilter>& headFilter,
                                                         const std::shared_ptr<DatabaseSessionPool>& pool,
                                                         const std::shared_ptr<api::ExecutionContext>& context,
                                                         const std::shared_ptr<api::ExecutionContext>& mainContext);
                        protected:
                                virtual soci::rowset<soci::row> performExecute(soci::session &sql) override;

                                virtual void inflateCompleteTransaction(
                                        soci::session &sql, const std::string &accountUid, CosmosLikeOperation& operation) override;

                                virtual std::shared_ptr<CosmosLikeOperation> createOperation(
                                        std::shared_ptr<AbstractAccount> &account) override;
                };
        }
}