#pragma once

#include "common/Command.h"

#include <string>
#include <unordered_map>

class KVServer;

#pragma once

enum class RequestType : int {
    PUT = 0,
    GET,
    DELETE
};

class NetServer {
public:
    explicit NetServer(KVServer* kvServer);
    void start(int port);

private:
    int listenFd_;
    KVServer* kv_;
    std::unordered_map<std::string, enum RequestType> requestMap_;

    void handleClient(int clientFd);
    void handlePut(std::istringstream& iss, std::string& response);
    void handleGet(std::istringstream& iss, std::string& response);
    void handleDelete(std::istringstream& iss, std::string& response);
};
