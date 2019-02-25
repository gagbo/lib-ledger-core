/*
 *
 * Bech32Parameters
 *
 * Created by El Khalil Bellakrid on 14/02/2019.
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


#ifndef LEDGER_CORE_BECH32PARAMETERS_H
#define LEDGER_CORE_BECH32PARAMETERS_H

#ifndef LIBCORE_EXPORT
    #if defined(_MSC_VER) && _MSC_VER
        #include <libcore_export.h>
    #else
        #define LIBCORE_EXPORT
    #endif
#endif

#include <string>
#include <vector>
namespace ledger {
    namespace core {
        namespace Bech32Parameters {

            struct Bech32Struct {
                std::string hrp;
                std::string separator;
                size_t checksumSize;
                std::vector<unsigned long long> generator;
                std::vector<uint8_t> P2WPKHVersion;
                std::vector<uint8_t> P2WSHVersion;

                Bech32Struct() = default;
                Bech32Struct(const std::string &_hrp,
                             const std::string &_separator,
                             size_t _checksumSize,
                             const std::vector<unsigned long long> &_generator) : hrp(_hrp),
                                                                                  separator(_separator),
                                                                                  checksumSize(_checksumSize),
                                                                                  generator(_generator)
                {};

            };
            extern LIBCORE_EXPORT const Bech32Struct getBech32Params(const std::string &networkIdentifier);
        }
    }
}
#endif //LEDGER_CORE_BECH32PARAMETERS_H
