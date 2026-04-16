#ifndef SMART_CONTRACT_VM_H
#define SMART_CONTRACT_VM_H

#include <string>
#include <unordered_map>
#include <vector>

class ContractVM {
public:
    enum OpCode {
        NOP, ADD, SUB, MUL, DIV, STORE, LOAD, JMP, CALL, RET
    };

    struct Contract {
        std::string address;
        std::vector<OpCode> bytecode;
        std::unordered_map<std::string, uint64_t> storage;
    };

    bool deploy_contract(const std::string& addr, const std::vector<OpCode>& code);
    uint64_t execute_contract(const std::string& addr, const std::vector<uint64_t>& params);
    Contract get_contract(const std::string& addr);

private:
    std::unordered_map<std::string, Contract> contracts;
    uint64_t execute_op(OpCode op, uint64_t a, uint64_t b);
};

#endif
