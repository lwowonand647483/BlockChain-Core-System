cmake_minimum_required(VERSION 3.18)
project(BlockChainCore)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_FLAGS "-O2 -pthread")

include_directories(./include)

file(GLOB SRC_FILES
    *.cpp
)

add_executable(blockchain ${SRC_FILES})

target_link_libraries(blockchain ssl crypto)
