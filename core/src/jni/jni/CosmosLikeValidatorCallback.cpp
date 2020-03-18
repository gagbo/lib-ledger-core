// AUTOGENERATED FILE - DO NOT MODIFY!
// This file generated by Djinni from callback.djinni

#include "CosmosLikeValidatorCallback.hpp"  // my header
#include "CosmosLikeValidator.hpp"
#include "Error.hpp"
#include "Marshal.hpp"

namespace djinni_generated {

CosmosLikeValidatorCallback::CosmosLikeValidatorCallback() : ::djinni::JniInterface<::ledger::core::api::CosmosLikeValidatorCallback, CosmosLikeValidatorCallback>() {}

CosmosLikeValidatorCallback::~CosmosLikeValidatorCallback() = default;

CosmosLikeValidatorCallback::JavaProxy::JavaProxy(JniType j) : Handle(::djinni::jniGetThreadEnv(), j) { }

CosmosLikeValidatorCallback::JavaProxy::~JavaProxy() = default;

void CosmosLikeValidatorCallback::JavaProxy::onCallback(const std::experimental::optional<::ledger::core::api::CosmosLikeValidator> & c_result, const std::experimental::optional<::ledger::core::api::Error> & c_error) {
    auto jniEnv = ::djinni::jniGetThreadEnv();
    ::djinni::JniLocalScope jscope(jniEnv, 10);
    const auto& data = ::djinni::JniClass<::djinni_generated::CosmosLikeValidatorCallback>::get();
    jniEnv->CallVoidMethod(Handle::get().get(), data.method_onCallback,
                           ::djinni::get(::djinni::Optional<std::experimental::optional, ::djinni_generated::CosmosLikeValidator>::fromCpp(jniEnv, c_result)),
                           ::djinni::get(::djinni::Optional<std::experimental::optional, ::djinni_generated::Error>::fromCpp(jniEnv, c_error)));
    ::djinni::jniExceptionCheck(jniEnv);
}

}  // namespace djinni_generated
