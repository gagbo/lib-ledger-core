// AUTOGENERATED FILE - DO NOT MODIFY!
// This file generated by Djinni from bitcoin_like_wallet.djinni

#ifndef DJINNI_GENERATED_BITCOINLIKEINPUT_HPP
#define DJINNI_GENERATED_BITCOINLIKEINPUT_HPP

#include "../../api/BitcoinLikeInput.hpp"
#include "djinni_support.hpp"

namespace djinni_generated {

class BitcoinLikeInput final {
public:
    using CppType = ::ledger::core::api::BitcoinLikeInput;
    using JniType = jobject;

    using Boxed = BitcoinLikeInput;

    ~BitcoinLikeInput();

    static CppType toCpp(JNIEnv* jniEnv, JniType j);
    static ::djinni::LocalRef<JniType> fromCpp(JNIEnv* jniEnv, const CppType& c);

private:
    BitcoinLikeInput();
    friend ::djinni::JniClass<BitcoinLikeInput>;

    const ::djinni::GlobalRef<jclass> clazz { ::djinni::jniFindClass("co/ledger/core/BitcoinLikeInput") };
    const jmethodID jconstructor { ::djinni::jniGetMethodID(clazz.get(), "<init>", "(Ljava/lang/String;ZLjava/lang/String;I)V") };
    const jfieldID field_path { ::djinni::jniGetFieldID(clazz.get(), "path", "Ljava/lang/String;") };
    const jfieldID field_isCoinbase { ::djinni::jniGetFieldID(clazz.get(), "isCoinbase", "Z") };
    const jfieldID field_previousTxHash { ::djinni::jniGetFieldID(clazz.get(), "previousTxHash", "Ljava/lang/String;") };
    const jfieldID field_indexInPreviousTx { ::djinni::jniGetFieldID(clazz.get(), "indexInPreviousTx", "I") };
};

}  // namespace djinni_generated
#endif //DJINNI_GENERATED_BITCOINLIKEINPUT_HPP
