#include "kvserver/KVServer.h"
#include "raftnode/RaftNode.h"
#include "raftnode/StateMachine.h"
#include "common/Command.h"

KVServer::KVServer(RaftNode* raftNode, StateMachine* stateMachine)
    : raftNode_(raftNode), stateMachine_(stateMachine) {}


bool KVServer::Put(const std::string& key, const std::string& value) {
    return true;
}


bool KVServer::Get(const std::string& key, std::string& value) {
    return true;
}

bool KVServer::Delete(const std::string& key) {
    return true;
}
