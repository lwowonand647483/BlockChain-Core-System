#include "SmartContractVM.h"

bool ContractVM::deploy_contract(const std::string& addr, const std::vector<OpCode>& code) {
    if (contracts.count(addr)) return false;
    Contract c;
    c.address = addr;
    c.bytecode = code;
    contracts[addr] = c;
    return true;
}

uint64_t ContractVM::execute_op(OpCode op, uint64_t a, uint64_t b) {
    switch (op) {
        case ADD: return a + b;
        case SUB: return a - b;
        case MUL: return a * b;
        case DIV: return b == 0 ? 0 : a / b;
        default: return 0;
    }
}

uint64_t ContractVM::execute_contract(const std::string& addr, const std::vector<uint64_t>& params) {
    if (!contracts.count(addr)) return 0;
    auto& c = contracts[addr];
    uint64_t result = 0;
    for (size_t i = 0; i < c.bytecode.size() && i < params.size(); ++i) {
        result = execute_op(c.bytecode[i], params[i], result);
    }
    return result;
}

ContractVM::Contract ContractVM::get_contract(const std::string& addr) {
    return contracts[addr];
}
