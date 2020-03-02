// AUTOGENERATED FILE - DO NOT MODIFY!
// This file generated by Djinni from messages.djinni

#ifndef DJINNI_GENERATED_COSMOSLIKEMSGREDELEGATE_HPP
#define DJINNI_GENERATED_COSMOSLIKEMSGREDELEGATE_HPP

#include "CosmosLikeAmount.hpp"
#include <iostream>
#include <string>
#include <utility>

namespace ledger { namespace core { namespace api {

struct CosmosLikeMsgRedelegate final {
    std::string delegatorAddress;
    std::string validatorSourceAddress;
    std::string validatorDestinationAddress;
    CosmosLikeAmount amount;

    CosmosLikeMsgRedelegate(std::string delegatorAddress_,
                            std::string validatorSourceAddress_,
                            std::string validatorDestinationAddress_,
                            CosmosLikeAmount amount_)
    : delegatorAddress(std::move(delegatorAddress_))
    , validatorSourceAddress(std::move(validatorSourceAddress_))
    , validatorDestinationAddress(std::move(validatorDestinationAddress_))
    , amount(std::move(amount_))
    {}

    CosmosLikeMsgRedelegate(const CosmosLikeMsgRedelegate& cpy) {
       this->delegatorAddress = cpy.delegatorAddress;
       this->validatorSourceAddress = cpy.validatorSourceAddress;
       this->validatorDestinationAddress = cpy.validatorDestinationAddress;
       this->amount = cpy.amount;
    }

    CosmosLikeMsgRedelegate() = default;


    CosmosLikeMsgRedelegate& operator=(const CosmosLikeMsgRedelegate& cpy) {
       this->delegatorAddress = cpy.delegatorAddress;
       this->validatorSourceAddress = cpy.validatorSourceAddress;
       this->validatorDestinationAddress = cpy.validatorDestinationAddress;
       this->amount = cpy.amount;
       return *this;
    }

    template <class Archive>
    void load(Archive& archive) {
        archive(delegatorAddress, validatorSourceAddress, validatorDestinationAddress, amount);
    }

    template <class Archive>
    void save(Archive& archive) const {
        archive(delegatorAddress, validatorSourceAddress, validatorDestinationAddress, amount);
    }
};

} } }  // namespace ledger::core::api
#endif //DJINNI_GENERATED_COSMOSLIKEMSGREDELEGATE_HPP
