#pragma once

#include <string>
#include <memory>

class RaftNode;
class StateMachine;

/**
 * KVServer
 * -------------
 * 对外提供 KV 存储服务的服务器组件
 * 不负责一致性，不直接操作存储
 * 所有写请求必须交给 RaftNode
*/
class KVServer {
public:
    KVServer(RaftNode* raftNode, StateMachine* stateMachine);

    bool Put(const std::string& key, const std::string& value);

    bool Get(const std::string& key, std::string& value_out);

    bool Delete(const std::string& key);

private:
    RaftNode* raftNode_;
    StateMachine* stateMachine_;
};
