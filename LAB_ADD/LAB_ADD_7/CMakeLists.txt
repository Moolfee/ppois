cmake_minimum_required(VERSION 3.16)
project(MerkleTreeDemo LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

add_library(merkle_lib MerkleTree.cpp)
target_include_directories(merkle_lib PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})

add_executable(merkle_demo main.cpp)
target_link_libraries(merkle_demo PRIVATE merkle_lib)
