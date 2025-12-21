cmake_minimum_required(VERSION 3.16)
project(AStarDemo LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

add_library(astar_lib AStar.cpp)
target_include_directories(astar_lib PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})

add_executable(astar_demo main.cpp)
target_link_libraries(astar_demo PRIVATE astar_lib)
