// AUTOGENERATED FILE - DO NOT MODIFY!
// This file generated by Djinni from wallet.djinni

#ifndef DJINNI_GENERATED_COSMOSLIKEOPERATION_HPP
#define DJINNI_GENERATED_COSMOSLIKEOPERATION_HPP

#include <memory>
#ifndef LIBCORE_EXPORT
    #if defined(_MSC_VER)
       #include <libcore_export.h>
    #else
       #define LIBCORE_EXPORT
    #endif
#endif

namespace ledger { namespace core { namespace api {

class CosmosLikeMessage;
class CosmosLikeTransaction;

/**Class representing a Cosmos Operation */
class LIBCORE_EXPORT CosmosLikeOperation {
public:
    virtual ~CosmosLikeOperation() {}

    /**
     *Get operation's transaction
     *@return CosmosLikeTransaction object
     */
    virtual std::shared_ptr<CosmosLikeTransaction> getTransaction() = 0;

    /**
     * Get message which created this operation
     * @return CosmosLikeMessage object
     */
    virtual std::shared_ptr<CosmosLikeMessage> getMessage() = 0;
};

} } }  // namespace ledger::core::api
#endif //DJINNI_GENERATED_COSMOSLIKEOPERATION_HPP
