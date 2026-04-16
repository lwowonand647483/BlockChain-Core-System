#ifndef API_SERVER_H
#define API_SERVER_H

#include <string>
#include <functional>
#include <unordered_map>

class ApiHttpServer {
public:
    explicit ApiHttpServer(uint16_t port);
    bool start_server();
    void stop_server();
    void register_route(const std::string& path, std::function<std::string()> handler);

private:
    uint16_t port;
    bool running;
    std::unordered_map<std::string, std::function<std::string()>> routes;
    void run_server();
};

#endif
