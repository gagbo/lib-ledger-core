// AUTOGENERATED FILE - DO NOT MODIFY!
// This file generated by Djinni from configuration.djinni

#ifndef DJINNI_GENERATED_SYNCHRONIZATIONENGINES_HPP
#define DJINNI_GENERATED_SYNCHRONIZATIONENGINES_HPP

#include "../../api/SynchronizationEngines.hpp"
#include "djinni_support.hpp"

namespace djinni_generated {

class SynchronizationEngines final : ::djinni::JniInterface<::ledger::core::api::SynchronizationEngines, SynchronizationEngines> {
public:
    using CppType = std::shared_ptr<::ledger::core::api::SynchronizationEngines>;
    using CppOptType = std::shared_ptr<::ledger::core::api::SynchronizationEngines>;
    using JniType = jobject;

    using Boxed = SynchronizationEngines;

    ~SynchronizationEngines();

    static CppType toCpp(JNIEnv* jniEnv, JniType j) { return ::djinni::JniClass<SynchronizationEngines>::get()._fromJava(jniEnv, j); }
    static ::djinni::LocalRef<JniType> fromCppOpt(JNIEnv* jniEnv, const CppOptType& c) { return {jniEnv, ::djinni::JniClass<SynchronizationEngines>::get()._toJava(jniEnv, c)}; }
    static ::djinni::LocalRef<JniType> fromCpp(JNIEnv* jniEnv, const CppType& c) { return fromCppOpt(jniEnv, c); }

private:
    SynchronizationEngines();
    friend ::djinni::JniClass<SynchronizationEngines>;
    friend ::djinni::JniInterface<::ledger::core::api::SynchronizationEngines, SynchronizationEngines>;

};

}  // namespace djinni_generated
#endif //DJINNI_GENERATED_SYNCHRONIZATIONENGINES_HPP
