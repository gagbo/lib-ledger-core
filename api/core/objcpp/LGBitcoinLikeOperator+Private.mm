// AUTOGENERATED FILE - DO NOT MODIFY!
// This file generated by Djinni from bitcoin_script.djinni

#import "LGBitcoinLikeOperator+Private.h"
#import "DJIMarshal+Private.h"
#include <cassert>

namespace djinni_generated {

auto BitcoinLikeOperator::toCpp(ObjcType obj) -> CppType
{
    assert(obj);
    return {::djinni::String::toCpp(obj.name),
            ::djinni::I8::toCpp(obj.value)};
}

auto BitcoinLikeOperator::fromCpp(const CppType& cpp) -> ObjcType
{
    return [[LGBitcoinLikeOperator alloc] initWithName:(::djinni::String::fromCpp(cpp.name))
                                                 value:(::djinni::I8::fromCpp(cpp.value))];
}

}  // namespace djinni_generated
