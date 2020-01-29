/*
 *
 * cosmos/config/Networks
 * ledger-core
 *
 * Created by Gerry Agbobada on 21/01/2020.
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

#include <cosmos/CosmosNetworks.hpp>
#include <core/api/ErrorCode.hpp>
#include <core/utils/Exception.hpp>

namespace ledger {
        namespace core {
                namespace networks {
                        const api::CosmosLikeNetworkParameters getCosmosLikeNetworkParameters(const std::string& chainID) {
                                if (chainID == "atom") {
                                static const api::CosmosLikeNetworkParameters COSMOSHUB_3(
                                        "ATOM",
                                        "ATOM signed message:\n",
                                        {0x04, 0x88, 0xB2, 0x1E},
                                        {0xEB, 0x5A, 0xE9, 0x87},
                                        {},
                                        "cosmoshub-3",
                                        {}
                                );
                                return COSMOSHUB_3;
                                }
                                if (chainID == "atom-cosmoshub-2") {
                                static const api::CosmosLikeNetworkParameters COSMOSHUB_2(
                                        "ATOM",
                                        "ATOM signed message:\n",
                                        {0x04, 0x88, 0xB2, 0x1E},
                                        {0xEB, 0x5A, 0xE9, 0x87},
                                        {},
                                        "cosmoshub-2",
                                        {}
                                );
                                return COSMOSHUB_2;
                                }
                        throw make_exception(api::ErrorCode::INVALID_ARGUMENT, "No network parameters set for chain {}", chainID);
                        }

            const std::vector<api::CosmosLikeNetworkParameters> ALL_COSMOS
                    ({
                             getCosmosLikeNetworkParameters("atom"),
                             getCosmosLikeNetworkParameters("atom-cosmoshub-2")
                     });
                }
        }
}