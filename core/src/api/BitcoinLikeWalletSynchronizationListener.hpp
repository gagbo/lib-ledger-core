// AUTOGENERATED FILE - DO NOT MODIFY!
// This file generated by Djinni from bitcoin_like_wallet.djinni

#ifndef DJINNI_GENERATED_BITCOINLIKEWALLETSYNCHRONIZATIONLISTENER_HPP
#define DJINNI_GENERATED_BITCOINLIKEWALLETSYNCHRONIZATIONLISTENER_HPP

namespace ledger { namespace core { namespace api {

class BitcoinLikeWalletSynchronizationListener {
public:
    virtual ~BitcoinLikeWalletSynchronizationListener() {}

    virtual void onProgress() = 0;
};

} } }  // namespace ledger::core::api
#endif //DJINNI_GENERATED_BITCOINLIKEWALLETSYNCHRONIZATIONLISTENER_HPP
