#include "NetServer.h"
#include "kvserver/KVServer.h"

#include <sys/socket.h>
#include <netinet/in.h>
#include <unistd.h>
#include <cstring>
#include <iostream>
#include <sstream>


NetServer::NetServer(KVServer* KVServer)
    : kv_(KVServer), listenFd_(-1) {}

void NetServer::start(int port) {
    listenFd_ = socket(AF_INET, SOCK_STREAM, 0);

    scokaddr_in addr{};
    addr.sin_family = AF_INET;
    addr.sin_addr.s_addr = INADDR_ANY;
    addr.sin_port = htons(port);

    bind(listenFd_, (sockaddr*)&addr, sizeof(addr));
    listen(listenFd_, 128);

    std::cout << "[KVServer] Listening on port " << port << std::endl;

    while (true) {
        int clientFd = accept(listenFd_, nullptr, nullptr);
        handleClient(clientFd);
        close(clientFd);
    }
}

void NetServer::handleCLient(int clientFd) {
    char buffer[1024];

    while (true) {
        memset(buffer, 0, sizeof(buffer));
        int n = read(clientFd, buffer, sizeof(buffer) - 1);
        if (n <= 0) break;

        std::string req(buffer);
        std::istringstream iss(req);

        std::string cmd;
        iss >> cmd;

        std::string response;
        switch (cmd) {
            case "PUT": handlePut(iss, response); break;
            case "GET": handleGet(iss, response); break;
            case "DEL": handleDelete(iss, response); break;
            default: response = "ERROR: Unknown command\n"; break;
        }

        write(clientFd, response.c_str(), response.size());
    }
}

void NetServer::handlePut(std::istringstream& iss, std::string& response) {
    std::string key, value;
    iss >> key >> value;
    if (kv_->Put(key, value)) {
        response = "OK\n";
    } else {
        response = "ERROR: PUT failed\n";
    }
}

void NetServer::handleGet(std::istringstream& iss, std::string& response) {
    std::string key, value;
    iss >> key;
    if (kv_->Get(key, value)) {
        response = "VALUE " + value + "\n";
    } else {
        response = "ERROR: Key not found\n";
    }
}

void NetServer::handleDelete(std::istringstream& iss, std::string& response) {
    std::string key;
    iss >> key;
    if (kv_->Delete(key)) {
        response = "OK\n";
    } else {
        response = "ERROR: DELETE failed\n";
    }
}
