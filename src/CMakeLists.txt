include_directories(${CMAKE_CURRENT_SOURCE_DIR})

add_subdirectory(netserver)
add_subdirectory(kvserver)
add_subdirectory(raftnode)
add_subdirectory(kvstore)

add_executable(miniRaftKV miniRaftKV.cpp)
target_link_libraries(miniRaftKV netserver kvserver raftnode kvstore)
