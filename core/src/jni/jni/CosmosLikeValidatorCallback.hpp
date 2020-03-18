// AUTOGENERATED FILE - DO NOT MODIFY!
// This file generated by Djinni from callback.djinni

#ifndef DJINNI_GENERATED_COSMOSLIKEVALIDATORCALLBACK_HPP_JNI_
#define DJINNI_GENERATED_COSMOSLIKEVALIDATORCALLBACK_HPP_JNI_

#include "../../api/CosmosLikeValidatorCallback.hpp"
#include "djinni_support.hpp"

namespace djinni_generated {

class CosmosLikeValidatorCallback final : ::djinni::JniInterface<::ledger::core::api::CosmosLikeValidatorCallback, CosmosLikeValidatorCallback> {
public:
    using CppType = std::shared_ptr<::ledger::core::api::CosmosLikeValidatorCallback>;
    using CppOptType = std::shared_ptr<::ledger::core::api::CosmosLikeValidatorCallback>;
    using JniType = jobject;

    using Boxed = CosmosLikeValidatorCallback;

    ~CosmosLikeValidatorCallback();

    static CppType toCpp(JNIEnv* jniEnv, JniType j) { return ::djinni::JniClass<CosmosLikeValidatorCallback>::get()._fromJava(jniEnv, j); }
    static ::djinni::LocalRef<JniType> fromCppOpt(JNIEnv* jniEnv, const CppOptType& c) { return {jniEnv, ::djinni::JniClass<CosmosLikeValidatorCallback>::get()._toJava(jniEnv, c)}; }
    static ::djinni::LocalRef<JniType> fromCpp(JNIEnv* jniEnv, const CppType& c) { return fromCppOpt(jniEnv, c); }

private:
    CosmosLikeValidatorCallback();
    friend ::djinni::JniClass<CosmosLikeValidatorCallback>;
    friend ::djinni::JniInterface<::ledger::core::api::CosmosLikeValidatorCallback, CosmosLikeValidatorCallback>;

    class JavaProxy final : ::djinni::JavaProxyHandle<JavaProxy>, public ::ledger::core::api::CosmosLikeValidatorCallback
    {
    public:
        JavaProxy(JniType j);
        ~JavaProxy();

        void onCallback(const std::experimental::optional<::ledger::core::api::CosmosLikeValidator> & result, const std::experimental::optional<::ledger::core::api::Error> & error) override;

    private:
        friend ::djinni::JniInterface<::ledger::core::api::CosmosLikeValidatorCallback, ::djinni_generated::CosmosLikeValidatorCallback>;
    };

    const ::djinni::GlobalRef<jclass> clazz { ::djinni::jniFindClass("co/ledger/core/CosmosLikeValidatorCallback") };
    const jmethodID method_onCallback { ::djinni::jniGetMethodID(clazz.get(), "onCallback", "(Lco/ledger/core/CosmosLikeValidator;Lco/ledger/core/Error;)V") };
};

}  // namespace djinni_generated
#endif //DJINNI_GENERATED_COSMOSLIKEVALIDATORCALLBACK_HPP_JNI_
