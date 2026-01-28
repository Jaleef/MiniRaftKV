#pragma once

#include <string>

class KVServer;

class NetServer {
public:
    explicit NetServer(KVServer* kvServer);
    void start(int port);

private:
    int listenFd_;
    KVServer* kv_;

    void handleClient(int clientFd);
};
