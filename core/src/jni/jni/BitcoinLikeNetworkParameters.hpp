// AUTOGENERATED FILE - DO NOT MODIFY!
// This file generated by Djinni from addresses.djinni

#ifndef DJINNI_GENERATED_BITCOINLIKENETWORKPARAMETERS_HPP
#define DJINNI_GENERATED_BITCOINLIKENETWORKPARAMETERS_HPP

#include "../../api/BitcoinLikeNetworkParameters.hpp"
#include "djinni_support.hpp"

namespace djinni_generated {

class BitcoinLikeNetworkParameters final {
public:
    using CppType = ::ledger::core::api::BitcoinLikeNetworkParameters;
    using JniType = jobject;

    using Boxed = BitcoinLikeNetworkParameters;

    ~BitcoinLikeNetworkParameters();

    static CppType toCpp(JNIEnv* jniEnv, JniType j);
    static ::djinni::LocalRef<JniType> fromCpp(JNIEnv* jniEnv, const CppType& c);

private:
    BitcoinLikeNetworkParameters();
    friend ::djinni::JniClass<BitcoinLikeNetworkParameters>;

    const ::djinni::GlobalRef<jclass> clazz { ::djinni::jniFindClass("co/ledger/core/BitcoinLikeNetworkParameters") };
    const jmethodID jconstructor { ::djinni::jniGetMethodID(clazz.get(), "<init>", "(Ljava/lang/String;[B[B[BLco/ledger/core/BitcoinLikeFeePolicy;JLjava/lang/String;JLjava/lang/String;Z)V") };
    const jfieldID field_Identifier { ::djinni::jniGetFieldID(clazz.get(), "Identifier", "Ljava/lang/String;") };
    const jfieldID field_P2PKHVersion { ::djinni::jniGetFieldID(clazz.get(), "P2PKHVersion", "[B") };
    const jfieldID field_P2SHVersion { ::djinni::jniGetFieldID(clazz.get(), "P2SHVersion", "[B") };
    const jfieldID field_XPUBVersion { ::djinni::jniGetFieldID(clazz.get(), "XPUBVersion", "[B") };
    const jfieldID field_FeePolicy { ::djinni::jniGetFieldID(clazz.get(), "FeePolicy", "Lco/ledger/core/BitcoinLikeFeePolicy;") };
    const jfieldID field_BIP44CoinType { ::djinni::jniGetFieldID(clazz.get(), "BIP44CoinType", "J") };
    const jfieldID field_PaymentUriScheme { ::djinni::jniGetFieldID(clazz.get(), "PaymentUriScheme", "Ljava/lang/String;") };
    const jfieldID field_DustAmount { ::djinni::jniGetFieldID(clazz.get(), "DustAmount", "J") };
    const jfieldID field_MessagePrefix { ::djinni::jniGetFieldID(clazz.get(), "MessagePrefix", "Ljava/lang/String;") };
    const jfieldID field_UsesTimestampedTransaction { ::djinni::jniGetFieldID(clazz.get(), "UsesTimestampedTransaction", "Z") };
};

}  // namespace djinni_generated
#endif //DJINNI_GENERATED_BITCOINLIKENETWORKPARAMETERS_HPP
