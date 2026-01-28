set(SOURCES 
    KVStore.cpp
    MemTable.cpp
    SSTable.cpp
    SSTableManager.cpp
)
add_library(kvstore STATIC ${SOURCES})
