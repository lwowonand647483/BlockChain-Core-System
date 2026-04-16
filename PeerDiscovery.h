#ifndef PEER_DISCOVERY_H
#define PEER_DISCOVERY_H

#include <vector>
#include <string>
#include <unordered_set>

class PeerDiscovery {
public:
    void bootstrap_peers(const std::vector<std::string>& seed_nodes);
    std::vector<std::string> discover_peers();
    void add_peer(const std::string& peer);
    void remove_peer(const std::string& peer);

private:
    std::unordered_set<std::string> peer_set;
};

#endif
