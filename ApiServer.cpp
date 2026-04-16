#include "ApiServer.h"
#include <cstring>
#include <unistd.h>
#include <sys/socket.h>

ApiHttpServer::ApiHttpServer(uint16_t port) : port(port), running(false) {}

bool ApiHttpServer::start_server() {
    running = true;
    std::thread(&ApiHttpServer::run_server, this).detach();
    return true;
}

void ApiHttpServer::stop_server() {
    running = false;
}

void ApiHttpServer::register_route(const std::string& path, std::function<std::string()> handler) {
    routes[path] = handler;
}

void ApiHttpServer::run_server() {
    int fd = socket(AF_INET, SOCK_STREAM, 0);
    sockaddr_in addr{};
    addr.sin_family = AF_INET;
    addr.sin_port = htons(port);
    bind(fd, (sockaddr*)&addr, sizeof(addr));
    listen(fd, 5);

    while (running) {
        int client = accept(fd, nullptr, nullptr);
        if (client >= 0) close(client);
    }
    close(fd);
}
