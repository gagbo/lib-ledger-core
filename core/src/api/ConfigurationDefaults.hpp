// AUTOGENERATED FILE - DO NOT MODIFY!
// This file generated by Djinni from configuration.djinni

#ifndef DJINNI_GENERATED_CONFIGURATIONDEFAULTS_HPP
#define DJINNI_GENERATED_CONFIGURATIONDEFAULTS_HPP

#include <cstdint>
#include <string>
#ifndef LIBCORE_EXPORT
    #if defined(_MSC_VER)
       #include <libcore_export.h>
    #else
       #define LIBCORE_EXPORT
    #endif
#endif

namespace ledger { namespace core { namespace api {

/** Default values you might want to use if you don’t know what values you should use. */
class LIBCORE_EXPORT ConfigurationDefaults {
public:
    virtual ~ConfigurationDefaults() {}

    /** The default Ledger API endpoint for the explorers. */
    static std::string const BLOCKCHAIN_DEFAULT_API_ENDPOINT;

    /** The default Ledger API endpoint for the observers. */
    static std::string const BLOCKCHAIN_OBSERVER_WS_ENDPOINT;

    /** The default derivation scheme for BIP44 derivation. */
    static std::string const BIP44_DERIVATION_SCHEME;

    /** Default keychain policy. */
    static std::string const DEFAULT_KEYCHAIN;

    /** Default trust limit (block height). */
    static int32_t const DEFAULT_TRUST_LIMIT;

    /** Default observable range for HD keychains */
    static int32_t const KEYCHAIN_DEFAULT_OBSERVABLE_RANGE;
};

} } }  // namespace ledger::core::api
#endif //DJINNI_GENERATED_CONFIGURATIONDEFAULTS_HPP
