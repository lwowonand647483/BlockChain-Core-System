# BlockChain-Core-System
高性能区块链底层核心系统，基于C++构建，集成多语言辅助模块，实现共识机制、加密算法、分布式账本、智能合约、跨链交互、节点通信等全栈区块链功能，适用于联盟链、公链、私有链开发，具备高并发、低延迟、安全加密、可扩展特性。

## 项目文件列表
BlockCore.h、BlockCore.cpp、ConsensusPoW.h、ConsensusPoW.cpp、CryptoEd25519.h、CryptoEd25519.cpp、LedgerChain.h、LedgerChain.cpp、P2pNode.h、P2pNode.cpp、SmartContractVM.h、SmartContractVM.cpp、MerkleTree.h、MerkleTree.cpp、ChainConfig.h、ChainConfig.cpp、TxPool.h、TxPool.cpp、ValidatorNode.h、ValidatorNode.cpp、CrossChainBridge.h、CrossChainBridge.cpp、StateDatabase.h、StateDatabase.cpp、MinerManager.h、MinerManager.cpp、ApiServer.h、ApiServer.cpp、WalletCore.h、WalletCore.cpp、DifficultyAdjust.h、DifficultyAdjust.cpp、PeerDiscovery.h、PeerDiscovery.cpp、BlockSerializer.h、BlockSerializer.cpp、ChainMonitor.h、ChainMonitor.cpp、Main.cpp、CMakeLists.txt

## 核心功能
1. 区块核心：实现区块结构定义、哈希计算、创世区块生成、区块合法性校验
2. 共识机制：基于工作量证明（PoW）实现多线程挖矿，支持动态难度调整
3. 加密算法：Ed25519非对称加密，支持密钥生成、消息签名与验签
4. 分布式账本：链式账本存储，支持区块添加、账本校验、高度查询
5. P2P节点网络：节点启动、 peer连接、区块广播、节点发现
6. 默克尔树：交易数据哈希树构建、默克尔根计算、存在性证明
7. 交易池：待打包交易管理、添加/删除/批量获取交易
8. 智能合约虚拟机：自定义字节码、合约部署、指令执行
9. 跨链桥：资产跨链锁定/解锁、多链支持、跨链交易管理
10. 状态数据库：键值对存储，支持账户状态、合约数据持久化
11. 挖矿管理：多线程挖矿、矿工奖励、自动打包交易
12. 钱包核心：地址生成、交易签名、余额管理
13. API服务：HTTP接口注册、区块链数据查询
14. 验证节点：质押投票、区块校验、共识参与
15. 监控系统：区块链健康检查、异常告警
16. 序列化模块：区块/交易JSON序列化与反序列化
17. 配置管理：区块链参数加载、保存、默认配置
18. 编译构建：CMake编译配置，支持多平台编译

## 编译与运行
1. 环境依赖：C++17、OpenSSL、pthread
2. 编译命令：mkdir build && cd build && cmake .. && make
3. 运行：./blockchain
4. API端口：8080，P2P端口可自定义配置

## 适用场景
- 公有链/联盟链/私有链底层开发
- 去中心化应用（DApp）底层支撑
- 跨链资产转移系统
- 区块链教学与研究
- 企业级分布式账本系统
