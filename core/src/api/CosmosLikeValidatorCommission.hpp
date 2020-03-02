// AUTOGENERATED FILE - DO NOT MODIFY!
// This file generated by Djinni from messages.djinni

#ifndef DJINNI_GENERATED_COSMOSLIKEVALIDATORCOMMISSION_HPP
#define DJINNI_GENERATED_COSMOSLIKEVALIDATORCOMMISSION_HPP

#include "CosmosLikeCommissionRates.hpp"
#include <chrono>
#include <iostream>
#include <utility>

namespace ledger { namespace core { namespace api {

struct CosmosLikeValidatorCommission final {
    CosmosLikeCommissionRates rates;
    std::chrono::system_clock::time_point updateTime;

    CosmosLikeValidatorCommission(CosmosLikeCommissionRates rates_,
                                  std::chrono::system_clock::time_point updateTime_)
    : rates(std::move(rates_))
    , updateTime(std::move(updateTime_))
    {}

    CosmosLikeValidatorCommission(const CosmosLikeValidatorCommission& cpy) {
       this->rates = cpy.rates;
       this->updateTime = cpy.updateTime;
    }

    CosmosLikeValidatorCommission() = default;


    CosmosLikeValidatorCommission& operator=(const CosmosLikeValidatorCommission& cpy) {
       this->rates = cpy.rates;
       this->updateTime = cpy.updateTime;
       return *this;
    }

    template <class Archive>
    void load(Archive& archive) {
        archive(rates, updateTime);
    }

    template <class Archive>
    void save(Archive& archive) const {
        archive(rates, updateTime);
    }
};

} } }  // namespace ledger::core::api
#endif //DJINNI_GENERATED_COSMOSLIKEVALIDATORCOMMISSION_HPP
