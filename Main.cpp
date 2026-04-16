#include <iostream>
#include "LedgerChain.h"
#include "MinerManager.h"
#include "WalletCore.h"
#include "ApiServer.h"

int main() {
    std::cout << "BlockChain Core System Starting..." << std::endl;

    // 初始化账本
    auto& ledger = BlockchainLedger::get_instance();
    std::cout << "Genesis block created. Chain height: " << ledger.get_chain_height() << std::endl;

    // 创建钱包
    Wallet wallet;
    std::cout << "Wallet Address: " << wallet.get_address() << std::endl;

    // 启动矿工
    MinerManager miner;
    miner.set_miner_address(wallet.get_address());
    miner.start_mining();
    std::cout << "Mining started..." << std::endl;

    // 启动API服务
    ApiHttpServer api(8080);
    api.register_route("/height", [&]() {
        return std::to_string(ledger.get_chain_height());
    });
    api.start_server();

    // 保持运行
    while (true) {
        std::this_thread::sleep_for(std::chrono::seconds(1));
    }

    return 0;
}
