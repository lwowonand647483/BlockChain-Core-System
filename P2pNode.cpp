#include "P2pNode.h"
#include <cstring>
#include <unistd.h>
#include <arpa/inet.h>

P2PNode::P2PNode(uint16_t port) : port(port), server_fd(-1), running(false) {}

bool P2PNode::start_node() {
    server_fd = socket(AF_INET, SOCK_STREAM, 0);
    if (server_fd == -1) return false;

    sockaddr_in addr{};
    addr.sin_family = AF_INET;
    addr.sin_port = htons(port);
    addr.sin_addr.s_addr = INADDR_ANY;

    if (bind(server_fd, (sockaddr*)&addr, sizeof(addr)) < 0) return false;
    listen(server_fd, 10);
    running = true;
    std::thread(&P2PNode::listen_connections, this).detach();
    return true;
}

void P2PNode::stop_node() {
    running = false;
    close(server_fd);
}

bool P2PNode::connect_peer(const std::string& ip, uint16_t port) {
    peers.insert(ip + ":" + std::to_string(port));
    return true;
}

void P2PNode::broadcast_block(const std::string& block_data) {
    for (const auto& peer : peers) {
        // 模拟广播逻辑
    }
}

std::unordered_set<std::string> P2PNode::get_peer_list() {
    return peers;
}

void P2PNode::listen_connections() {
    while (running) {
        sockaddr_in client_addr{};
        socklen_t len = sizeof(client_addr);
        int client = accept(server_fd, (sockaddr*)&client_addr, &len);
        if (client >= 0) close(client);
    }
}
