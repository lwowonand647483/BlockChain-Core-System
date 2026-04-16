#include "WalletCore.h"

Wallet::Wallet() : balance(0) {
    keys = crypto.generate_key_pair();
}

Wallet::Wallet(const std::string& priv_key) : balance(0) {
    keys.private_key = priv_key;
    keys.public_key = crypto.bytes_to_hex(crypto.hex_to_bytes(priv_key));
}

std::string Wallet::address_from_pubkey(const std::string& pub) {
    return "0x" + pub.substr(0, 40);
}

std::string Wallet::get_address() {
    return address_from_pubkey(keys.public_key);
}

std::string Wallet::sign_transaction(const std::string& tx_data) {
    return crypto.sign_message(tx_data, keys.private_key);
}

double Wallet::get_balance() {
    return balance;
}

void Wallet::set_balance(double bal) {
    balance = bal;
}
