#include "KVServer.h"
#include "RaftNode.h"
#include "StateMachine.h"
#include "Command.h"

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
