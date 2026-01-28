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
}
