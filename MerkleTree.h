#ifndef MERKLE_TREE_H
#define MERKLE_TREE_H

#include <vector>
#include <string>

class MerkleTree {
public:
    explicit MerkleTree(const std::vector<std::string>& leaves);
    std::string get_root();
    std::vector<std::string> get_proof(size_t index);
    bool verify_proof(const std::string& leaf, const std::vector<std::string>& proof, const std::string& root);

private:
    std::vector<std::string> nodes;
    std::string hash_pair(const std::string& a, const std::string& b);
    void build_tree(const std::vector<std::string>& leaves);
};

#endif
