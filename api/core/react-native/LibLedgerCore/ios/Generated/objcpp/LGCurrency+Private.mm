// AUTOGENERATED FILE - DO NOT MODIFY!
// This file generated by Djinni from currency.djinni

#import "LGCurrency+Private.h"
#import "DJIMarshal+Private.h"
#import "LGBitcoinLikeNetworkParameters+Private.h"
#import "LGCurrencyUnit+Private.h"
#import "LGWalletType+Private.h"
#include <cassert>

namespace djinni_generated {

auto Currency::toCpp(ObjcType obj) -> CppType
{
    assert(obj);
    return {::djinni::Enum<::ledger::core::api::WalletType, LGWalletType>::toCpp(obj.walletType),
            ::djinni::String::toCpp(obj.name),
            ::djinni::I32::toCpp(obj.bip44CoinType),
            ::djinni::String::toCpp(obj.paymentUriScheme),
            ::djinni::List<::djinni_generated::CurrencyUnit>::toCpp(obj.units),
            ::djinni::Optional<std::experimental::optional, ::djinni_generated::BitcoinLikeNetworkParameters>::toCpp(obj.bitcoinLikeNetworkParameters)};
}

auto Currency::fromCpp(const CppType& cpp) -> ObjcType
{
    return [[LGCurrency alloc] initWithWalletType:(::djinni::Enum<::ledger::core::api::WalletType, LGWalletType>::fromCpp(cpp.walletType))
                                             name:(::djinni::String::fromCpp(cpp.name))
                                    bip44CoinType:(::djinni::I32::fromCpp(cpp.bip44CoinType))
                                 paymentUriScheme:(::djinni::String::fromCpp(cpp.paymentUriScheme))
                                            units:(::djinni::List<::djinni_generated::CurrencyUnit>::fromCpp(cpp.units))
                     bitcoinLikeNetworkParameters:(::djinni::Optional<std::experimental::optional, ::djinni_generated::BitcoinLikeNetworkParameters>::fromCpp(cpp.bitcoinLikeNetworkParameters))];
}

}  // namespace djinni_generated
