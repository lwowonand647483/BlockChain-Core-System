#ifndef WALLET_CORE_H
#define WALLET_CORE_H

#include "CryptoEd25519.h"
#include <string>

class Wallet {
public:
    Wallet();
    explicit Wallet(const std::string& priv_key);
    std::string get_address();
    std::string sign_transaction(const std::string& tx_data);
    double get_balance();
    void set_balance(double bal);

private:
    Ed25519Crypto crypto;
    Ed25519Crypto::KeyPair keys;
    double balance;
    std::string address_from_pubkey(const std::string& pub);
};

#endif
