// AUTOGENERATED FILE - DO NOT MODIFY!
// This file generated by Djinni from callback.djinni

#ifndef DJINNI_GENERATED_STRINGCOMPLETIONBLOCK_HPP
#define DJINNI_GENERATED_STRINGCOMPLETIONBLOCK_HPP

#include "../../api/StringCompletionBlock.hpp"
#include "djinni_support.hpp"

namespace djinni_generated {

class StringCompletionBlock final : ::djinni::JniInterface<::ledger::core::api::StringCompletionBlock, StringCompletionBlock> {
public:
    using CppType = std::shared_ptr<::ledger::core::api::StringCompletionBlock>;
    using CppOptType = std::shared_ptr<::ledger::core::api::StringCompletionBlock>;
    using JniType = jobject;

    using Boxed = StringCompletionBlock;

    ~StringCompletionBlock();

    static CppType toCpp(JNIEnv* jniEnv, JniType j) { return ::djinni::JniClass<StringCompletionBlock>::get()._fromJava(jniEnv, j); }
    static ::djinni::LocalRef<JniType> fromCppOpt(JNIEnv* jniEnv, const CppOptType& c) { return {jniEnv, ::djinni::JniClass<StringCompletionBlock>::get()._toJava(jniEnv, c)}; }
    static ::djinni::LocalRef<JniType> fromCpp(JNIEnv* jniEnv, const CppType& c) { return fromCppOpt(jniEnv, c); }

private:
    StringCompletionBlock();
    friend ::djinni::JniClass<StringCompletionBlock>;
    friend ::djinni::JniInterface<::ledger::core::api::StringCompletionBlock, StringCompletionBlock>;

};

}  // namespace djinni_generated
#endif //DJINNI_GENERATED_STRINGCOMPLETIONBLOCK_HPP
