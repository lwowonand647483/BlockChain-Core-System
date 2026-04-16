#include "MerkleTree.h"
#include <sha256.h>

MerkleTree::MerkleTree(const std::vector<std::string>& leaves) {
    build_tree(leaves);
}

std::string MerkleTree::hash_pair(const std::string& a, const std::string& b) {
    return sha256(a + b);
}

void MerkleTree::build_tree(const std::vector<std::string>& leaves) {
    nodes = leaves;
    while (nodes.size() > 1) {
        std::vector<std::string> level;
        for (size_t i = 0; i < nodes.size(); i += 2) {
            if (i + 1 < nodes.size()) level.push_back(hash_pair(nodes[i], nodes[i+1]));
            else level.push_back(nodes[i]);
        }
        nodes = level;
    }
}

std::string MerkleTree::get_root() {
    return nodes.empty() ? "" : nodes[0];
}

std::vector<std::string> MerkleTree::get_proof(size_t index) {
    std::vector<std::string> proof;
    // 简化实现
    return proof;
}

bool MerkleTree::verify_proof(const std::string& leaf, const std::vector<std::string>& proof, const std::string& root) {
    std::string current = leaf;
    for (const auto& p : proof) current = hash_pair(current, p);
    return current == root;
}
