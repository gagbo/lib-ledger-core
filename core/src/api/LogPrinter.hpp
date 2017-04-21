// AUTOGENERATED FILE - DO NOT MODIFY!
// This file generated by Djinni from logger.djinni

#ifndef DJINNI_GENERATED_LOGPRINTER_HPP
#define DJINNI_GENERATED_LOGPRINTER_HPP

#include <memory>
#include <string>

namespace ledger { namespace core { namespace api {

class ExecutionContext;

class LogPrinter {
public:
    virtual ~LogPrinter() {}

    virtual void printError(const std::string & message) = 0;

    virtual void printInfo(const std::string & message) = 0;

    virtual void printDebug(const std::string & message) = 0;

    virtual void printWarning(const std::string & message) = 0;

    virtual void printApdu(const std::string & message) = 0;

    virtual void printCriticalError(const std::string & message) = 0;

    virtual std::shared_ptr<ExecutionContext> getContext() = 0;
};

} } }  // namespace ledger::core::api
#endif //DJINNI_GENERATED_LOGPRINTER_HPP
