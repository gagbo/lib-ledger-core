// AUTOGENERATED FILE - DO NOT MODIFY!
// This file generated by Djinni from wallet.djinni

#ifndef DJINNI_GENERATED_COSMOSCONFIGURATIONDEFAULTS_HPP
#define DJINNI_GENERATED_COSMOSCONFIGURATIONDEFAULTS_HPP

#include <string>
#ifndef LIBCORE_EXPORT
    #if defined(_MSC_VER)
       #include <libcore_export.h>
    #else
       #define LIBCORE_EXPORT
    #endif
#endif

namespace ledger { namespace core { namespace api {

class LIBCORE_EXPORT CosmosConfigurationDefaults {
public:
    virtual ~CosmosConfigurationDefaults() {}

    static std::string const COSMOS_DEFAULT_API_ENDPOINT;

    static std::string const COSMOS_DEFAULT_STARGATE_API_ENDPOINT;

    static std::string const COSMOS_OBSERVER_WS_ENDPOINT;
};

} } }  // namespace ledger::core::api
#endif //DJINNI_GENERATED_COSMOSCONFIGURATIONDEFAULTS_HPP
