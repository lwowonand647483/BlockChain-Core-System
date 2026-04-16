#ifndef CRYPTO_ED25519_H
#define CRYPTO_ED25519_H

#include <string>
#include <vector>

class Ed25519Crypto {
public:
    struct KeyPair {
        std::string public_key;
        std::string private_key;
    };

    KeyPair generate_key_pair();
    std::string sign_message(const std::string& msg, const std::string& priv_key);
    bool verify_signature(const std::string& msg, const std::string& sig, const std::string& pub_key);
    std::vector<uint8_t> hex_to_bytes(const std::string& hex);
    std::string bytes_to_hex(const std::vector<uint8_t>& bytes);
};

#endif
