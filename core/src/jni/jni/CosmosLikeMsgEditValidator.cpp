// AUTOGENERATED FILE - DO NOT MODIFY!
// This file generated by Djinni from messages.djinni

#include "CosmosLikeMsgEditValidator.hpp"  // my header
#include "CosmosLikeValidatorDescription.hpp"
#include "Marshal.hpp"

namespace djinni_generated {

CosmosLikeMsgEditValidator::CosmosLikeMsgEditValidator() = default;

CosmosLikeMsgEditValidator::~CosmosLikeMsgEditValidator() = default;

auto CosmosLikeMsgEditValidator::fromCpp(JNIEnv* jniEnv, const CppType& c) -> ::djinni::LocalRef<JniType> {
    const auto& data = ::djinni::JniClass<CosmosLikeMsgEditValidator>::get();
    auto r = ::djinni::LocalRef<JniType>{jniEnv->NewObject(data.clazz.get(), data.jconstructor,
                                                           ::djinni::get(::djinni::Optional<std::experimental::optional, ::djinni_generated::CosmosLikeValidatorDescription>::fromCpp(jniEnv, c.description)),
                                                           ::djinni::get(::djinni::String::fromCpp(jniEnv, c.validatorAddress)),
                                                           ::djinni::get(::djinni::Optional<std::experimental::optional, ::djinni::String>::fromCpp(jniEnv, c.commissionRate)),
                                                           ::djinni::get(::djinni::Optional<std::experimental::optional, ::djinni::String>::fromCpp(jniEnv, c.minSelfDelegation)))};
    ::djinni::jniExceptionCheck(jniEnv);
    return r;
}

auto CosmosLikeMsgEditValidator::toCpp(JNIEnv* jniEnv, JniType j) -> CppType {
    ::djinni::JniLocalScope jscope(jniEnv, 5);
    assert(j != nullptr);
    const auto& data = ::djinni::JniClass<CosmosLikeMsgEditValidator>::get();
    return {::djinni::Optional<std::experimental::optional, ::djinni_generated::CosmosLikeValidatorDescription>::toCpp(jniEnv, jniEnv->GetObjectField(j, data.field_description)),
            ::djinni::String::toCpp(jniEnv, (jstring)jniEnv->GetObjectField(j, data.field_validatorAddress)),
            ::djinni::Optional<std::experimental::optional, ::djinni::String>::toCpp(jniEnv, (jstring)jniEnv->GetObjectField(j, data.field_commissionRate)),
            ::djinni::Optional<std::experimental::optional, ::djinni::String>::toCpp(jniEnv, (jstring)jniEnv->GetObjectField(j, data.field_minSelfDelegation))};
}

}  // namespace djinni_generated
