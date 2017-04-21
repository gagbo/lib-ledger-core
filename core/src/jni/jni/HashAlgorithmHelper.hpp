// AUTOGENERATED FILE - DO NOT MODIFY!
// This file generated by Djinni from crypto.djinni

#ifndef DJINNI_GENERATED_HASHALGORITHMHELPER_HPP
#define DJINNI_GENERATED_HASHALGORITHMHELPER_HPP

#include "../../api/HashAlgorithmHelper.hpp"
#include "djinni_support.hpp"

namespace djinni_generated {

class HashAlgorithmHelper final : ::djinni::JniInterface<::ledger::core::api::HashAlgorithmHelper, HashAlgorithmHelper> {
public:
    using CppType = std::shared_ptr<::ledger::core::api::HashAlgorithmHelper>;
    using CppOptType = std::shared_ptr<::ledger::core::api::HashAlgorithmHelper>;
    using JniType = jobject;

    using Boxed = HashAlgorithmHelper;

    ~HashAlgorithmHelper();

    static CppType toCpp(JNIEnv* jniEnv, JniType j) { return ::djinni::JniClass<HashAlgorithmHelper>::get()._fromJava(jniEnv, j); }
    static ::djinni::LocalRef<JniType> fromCppOpt(JNIEnv* jniEnv, const CppOptType& c) { return {jniEnv, ::djinni::JniClass<HashAlgorithmHelper>::get()._toJava(jniEnv, c)}; }
    static ::djinni::LocalRef<JniType> fromCpp(JNIEnv* jniEnv, const CppType& c) { return fromCppOpt(jniEnv, c); }

private:
    HashAlgorithmHelper();
    friend ::djinni::JniClass<HashAlgorithmHelper>;
    friend ::djinni::JniInterface<::ledger::core::api::HashAlgorithmHelper, HashAlgorithmHelper>;

    class JavaProxy final : ::djinni::JavaProxyHandle<JavaProxy>, public ::ledger::core::api::HashAlgorithmHelper
    {
    public:
        JavaProxy(JniType j);
        ~JavaProxy();

        std::vector<uint8_t> ripemd160(const std::vector<uint8_t> & data) override;
        std::vector<uint8_t> sha256(const std::vector<uint8_t> & data) override;
        std::vector<uint8_t> keccak256(const std::vector<uint8_t> & data) override;

    private:
        friend ::djinni::JniInterface<::ledger::core::api::HashAlgorithmHelper, ::djinni_generated::HashAlgorithmHelper>;
    };

    const ::djinni::GlobalRef<jclass> clazz { ::djinni::jniFindClass("co/ledger/core/HashAlgorithmHelper") };
    const jmethodID method_ripemd160 { ::djinni::jniGetMethodID(clazz.get(), "ripemd160", "([B)[B") };
    const jmethodID method_sha256 { ::djinni::jniGetMethodID(clazz.get(), "sha256", "([B)[B") };
    const jmethodID method_keccak256 { ::djinni::jniGetMethodID(clazz.get(), "keccak256", "([B)[B") };
};

}  // namespace djinni_generated
#endif //DJINNI_GENERATED_HASHALGORITHMHELPER_HPP
