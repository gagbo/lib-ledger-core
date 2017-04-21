// AUTOGENERATED FILE - DO NOT MODIFY!
// This file generated by Djinni from bitcoin_public_key_provider.djinni

#ifndef DJINNI_GENERATED_BITCOINLIKEEXTENDEDPUBLICKEYPROVIDER_HPP
#define DJINNI_GENERATED_BITCOINLIKEEXTENDEDPUBLICKEYPROVIDER_HPP

#include "../../api/BitcoinLikeExtendedPublicKeyProvider.hpp"
#include "djinni_support.hpp"

namespace djinni_generated {

class BitcoinLikeExtendedPublicKeyProvider final : ::djinni::JniInterface<::ledger::core::api::BitcoinLikeExtendedPublicKeyProvider, BitcoinLikeExtendedPublicKeyProvider> {
public:
    using CppType = std::shared_ptr<::ledger::core::api::BitcoinLikeExtendedPublicKeyProvider>;
    using CppOptType = std::shared_ptr<::ledger::core::api::BitcoinLikeExtendedPublicKeyProvider>;
    using JniType = jobject;

    using Boxed = BitcoinLikeExtendedPublicKeyProvider;

    ~BitcoinLikeExtendedPublicKeyProvider();

    static CppType toCpp(JNIEnv* jniEnv, JniType j) { return ::djinni::JniClass<BitcoinLikeExtendedPublicKeyProvider>::get()._fromJava(jniEnv, j); }
    static ::djinni::LocalRef<JniType> fromCppOpt(JNIEnv* jniEnv, const CppOptType& c) { return {jniEnv, ::djinni::JniClass<BitcoinLikeExtendedPublicKeyProvider>::get()._toJava(jniEnv, c)}; }
    static ::djinni::LocalRef<JniType> fromCpp(JNIEnv* jniEnv, const CppType& c) { return fromCppOpt(jniEnv, c); }

private:
    BitcoinLikeExtendedPublicKeyProvider();
    friend ::djinni::JniClass<BitcoinLikeExtendedPublicKeyProvider>;
    friend ::djinni::JniInterface<::ledger::core::api::BitcoinLikeExtendedPublicKeyProvider, BitcoinLikeExtendedPublicKeyProvider>;

};

}  // namespace djinni_generated
#endif //DJINNI_GENERATED_BITCOINLIKEEXTENDEDPUBLICKEYPROVIDER_HPP
