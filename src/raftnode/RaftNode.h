#pragma once

#include "StateMachine.h"

class RaftNode {
public:
    RaftNode(StateMachine* sm);

private:
    StateMachine* sm_;
};
