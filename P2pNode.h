#ifndef P2P_NODE_H
#define P2P_NODE_H

#include <string>
#include <vector>
#include <unordered_set>
#include <netinet/in.h>

class P2PNode {
public:
    explicit P2PNode(uint16_t port);
    bool start_node();
    void stop_node();
    bool connect_peer(const std::string& ip, uint16_t port);
    void broadcast_block(const std::string& block_data);
    std::unordered_set<std::string> get_peer_list();

private:
    uint16_t port;
    int server_fd;
    std::unordered_set<std::string> peers;
    bool running;
    void listen_connections();
};

#endif
