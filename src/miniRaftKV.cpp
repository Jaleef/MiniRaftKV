#include "raftnode/RaftNode.h"
#include "raftnode/StateMachine.h"
#include "kvserver/KVServer.h"
#include "netserver/NetServer.h"
#include <iostream>

int main(int argc, char* argv[]) {
    StateMachine sm;
    RaftNode raft(&sm);
    KVServer kv(&raft, &sm);
    NetServer server(&kv);
    std::cout << "Mini Raft KV start!" << std::endl;
    server.start(9000);
    return 0;
}
