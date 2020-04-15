// AUTOGENERATED FILE - DO NOT MODIFY!
// This file generated by Djinni from addresses.djinni

#include "CosmosLikeExtendedPublicKey.hpp"  // my header
#include "CosmosLikeAddress.hpp"
#include "Marshal.hpp"

namespace djinni_generated {

CosmosLikeExtendedPublicKey::CosmosLikeExtendedPublicKey() : ::djinni::JniInterface<::ledger::core::api::CosmosLikeExtendedPublicKey, CosmosLikeExtendedPublicKey>("co/ledger/core/CosmosLikeExtendedPublicKey$CppProxy") {}

CosmosLikeExtendedPublicKey::~CosmosLikeExtendedPublicKey() = default;


CJNIEXPORT void JNICALL Java_co_ledger_core_CosmosLikeExtendedPublicKey_00024CppProxy_nativeDestroy(JNIEnv* jniEnv, jobject /*this*/, jlong nativeRef)
{
    try {
        DJINNI_FUNCTION_PROLOGUE1(jniEnv, nativeRef);
        delete reinterpret_cast<::djinni::CppProxyHandle<::ledger::core::api::CosmosLikeExtendedPublicKey>*>(nativeRef);
    } JNI_TRANSLATE_EXCEPTIONS_RETURN(jniEnv, )
}

CJNIEXPORT jobject JNICALL Java_co_ledger_core_CosmosLikeExtendedPublicKey_00024CppProxy_native_1derive(JNIEnv* jniEnv, jobject /*this*/, jlong nativeRef, jstring j_path)
{
    try {
        DJINNI_FUNCTION_PROLOGUE1(jniEnv, nativeRef);
        const auto& ref = ::djinni::objectFromHandleAddress<::ledger::core::api::CosmosLikeExtendedPublicKey>(nativeRef);
        auto r = ref->derive(::djinni::String::toCpp(jniEnv, j_path));
        return ::djinni::release(::djinni_generated::CosmosLikeAddress::fromCpp(jniEnv, r));
    } JNI_TRANSLATE_EXCEPTIONS_RETURN(jniEnv, 0 /* value doesn't matter */)
}

CJNIEXPORT jbyteArray JNICALL Java_co_ledger_core_CosmosLikeExtendedPublicKey_00024CppProxy_native_1derivePublicKey(JNIEnv* jniEnv, jobject /*this*/, jlong nativeRef, jstring j_path)
{
    try {
        DJINNI_FUNCTION_PROLOGUE1(jniEnv, nativeRef);
        const auto& ref = ::djinni::objectFromHandleAddress<::ledger::core::api::CosmosLikeExtendedPublicKey>(nativeRef);
        auto r = ref->derivePublicKey(::djinni::String::toCpp(jniEnv, j_path));
        return ::djinni::release(::djinni::Binary::fromCpp(jniEnv, r));
    } JNI_TRANSLATE_EXCEPTIONS_RETURN(jniEnv, 0 /* value doesn't matter */)
}

CJNIEXPORT jbyteArray JNICALL Java_co_ledger_core_CosmosLikeExtendedPublicKey_00024CppProxy_native_1deriveHash160(JNIEnv* jniEnv, jobject /*this*/, jlong nativeRef, jstring j_path)
{
    try {
        DJINNI_FUNCTION_PROLOGUE1(jniEnv, nativeRef);
        const auto& ref = ::djinni::objectFromHandleAddress<::ledger::core::api::CosmosLikeExtendedPublicKey>(nativeRef);
        auto r = ref->deriveHash160(::djinni::String::toCpp(jniEnv, j_path));
        return ::djinni::release(::djinni::Binary::fromCpp(jniEnv, r));
    } JNI_TRANSLATE_EXCEPTIONS_RETURN(jniEnv, 0 /* value doesn't matter */)
}

CJNIEXPORT jstring JNICALL Java_co_ledger_core_CosmosLikeExtendedPublicKey_00024CppProxy_native_1toBech32(JNIEnv* jniEnv, jobject /*this*/, jlong nativeRef)
{
    try {
        DJINNI_FUNCTION_PROLOGUE1(jniEnv, nativeRef);
        const auto& ref = ::djinni::objectFromHandleAddress<::ledger::core::api::CosmosLikeExtendedPublicKey>(nativeRef);
        auto r = ref->toBech32();
        return ::djinni::release(::djinni::String::fromCpp(jniEnv, r));
    } JNI_TRANSLATE_EXCEPTIONS_RETURN(jniEnv, 0 /* value doesn't matter */)
}

CJNIEXPORT jstring JNICALL Java_co_ledger_core_CosmosLikeExtendedPublicKey_00024CppProxy_native_1toBase58(JNIEnv* jniEnv, jobject /*this*/, jlong nativeRef)
{
    try {
        DJINNI_FUNCTION_PROLOGUE1(jniEnv, nativeRef);
        const auto& ref = ::djinni::objectFromHandleAddress<::ledger::core::api::CosmosLikeExtendedPublicKey>(nativeRef);
        auto r = ref->toBase58();
        return ::djinni::release(::djinni::String::fromCpp(jniEnv, r));
    } JNI_TRANSLATE_EXCEPTIONS_RETURN(jniEnv, 0 /* value doesn't matter */)
}

CJNIEXPORT jstring JNICALL Java_co_ledger_core_CosmosLikeExtendedPublicKey_00024CppProxy_native_1getRootPath(JNIEnv* jniEnv, jobject /*this*/, jlong nativeRef)
{
    try {
        DJINNI_FUNCTION_PROLOGUE1(jniEnv, nativeRef);
        const auto& ref = ::djinni::objectFromHandleAddress<::ledger::core::api::CosmosLikeExtendedPublicKey>(nativeRef);
        auto r = ref->getRootPath();
        return ::djinni::release(::djinni::String::fromCpp(jniEnv, r));
    } JNI_TRANSLATE_EXCEPTIONS_RETURN(jniEnv, 0 /* value doesn't matter */)
}

}  // namespace djinni_generated
