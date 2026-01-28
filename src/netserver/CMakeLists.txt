set(SOURCES NetServer.cpp)
add_library(netserver STATIC ${SOURCES})

target_link_libraries(netserver kvserver)
