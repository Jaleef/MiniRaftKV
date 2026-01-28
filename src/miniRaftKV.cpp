#include <iostream>

int main(int argc, char* argv[]) {
    RaftNode raft;
    StateMachine sm;
    KVServer kv(&raft, &sm);
    NetServer server(&kv);
    std::cout << "Mini Raft KV start!" << std::endl;
    return 0;
}
