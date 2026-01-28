set(SOURCES
    LogManager.cpp
    RaftNode.cpp
    StateMachine.cpp
    WAL.cpp
)

add_library(raftnode STATIC ${SOURCES})
