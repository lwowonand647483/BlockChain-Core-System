#include "PeerDiscovery.h"

void PeerDiscovery::bootstrap_peers(const std::vector<std::string>& seed_nodes) {
    for (const auto& s : seed_nodes) peer_set.insert(s);
}

void PeerDiscovery::add_peer(const std::string& peer) {
    peer_set.insert(peer);
}

void PeerDiscovery::remove_peer(const std::string& peer) {
    peer_set.erase(peer);
}

std::vector<std::string> PeerDiscovery::discover_peers() {
    return std::vector<std::string>(peer_set.begin(), peer_set.end());
}
