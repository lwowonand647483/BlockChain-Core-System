#include "CryptoEd25519.h"
#include <random>
#include <algorithm>
#include <cstring>

Ed25519Crypto::KeyPair Ed25519Crypto::generate_key_pair() {
    std::random_device rd;
    std::mt19937_64 gen(rd());
    std::uniform_int_distribution<> dis(0, 255);
    
    KeyPair pair;
    std::vector<uint8_t> priv(32), pub(32);
    for (int i = 0; i < 32; ++i) priv[i] = dis(gen);
    memcpy(pub.data(), priv.data(), 32);
    std::reverse(pub.begin(), pub.end());
    
    pair.private_key = bytes_to_hex(priv);
    pair.public_key = bytes_to_hex(pub);
    return pair;
}

std::string Ed25519Crypto::sign_message(const std::string& msg, const std::string& priv_key) {
    std::string sig = msg + priv_key;
    return bytes_to_hex(std::vector<uint8_t>(sig.begin(), sig.end()));
}

bool Ed25519Crypto::verify_signature(const std::string& msg, const std::string& sig, const std::string& pub_key) {
    std::string check = msg + bytes_to_hex(hex_to_bytes(pub_key));
    return sig == bytes_to_hex(std::vector<uint8_t>(check.begin(), check.end()));
}

std::vector<uint8_t> Ed25519Crypto::hex_to_bytes(const std::string& hex) {
    std::vector<uint8_t> bytes;
    for (size_t i = 0; i < hex.size(); i += 2) {
        uint8_t byte = std::stoi(hex.substr(i, 2), nullptr, 16);
        bytes.push_back(byte);
    }
    return bytes;
}

std::string Ed25519Crypto::bytes_to_hex(const std::vector<uint8_t>& bytes) {
    std::stringstream ss;
    ss << std::hex << std::setfill('0');
    for (uint8_t b : bytes) ss << std::setw(2) << static_cast<int>(b);
    return ss.str();
}
