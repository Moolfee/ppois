cmake_minimum_required(VERSION 3.16)
project(GraphTask LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

file(GLOB_RECURSE CLASS_SOURCES "Graph/*.cpp")
list(FILTER CLASS_SOURCES EXCLUDE REGEX ".*/Test[^/]*\\.cpp$")

file(GLOB_RECURSE TEST_SOURCES "Graph/*Test*.cpp")

if(CLASS_SOURCES)
    add_library(graph_lib ${CLASS_SOURCES})
    target_include_directories(graph_lib PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
else()
    add_library(graph_lib INTERFACE)
    target_include_directories(graph_lib INTERFACE ${CMAKE_CURRENT_SOURCE_DIR})
endif()

add_library(simple_gtest STATIC gtest/gtest_main.cpp)
target_include_directories(simple_gtest PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}
                                              ${CMAKE_CURRENT_SOURCE_DIR}/gtest)

add_executable(graph_tests ${TEST_SOURCES})
target_include_directories(graph_tests PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
target_link_libraries(graph_tests PRIVATE graph_lib simple_gtest)

option(ENABLE_COVERAGE "Enable gcov/lcov coverage flags" ON)
if(ENABLE_COVERAGE AND CMAKE_CXX_COMPILER_ID MATCHES "GNU|Clang")
    set(COVERAGE_TARGETS graph_tests simple_gtest)
    if(CLASS_SOURCES)
        list(APPEND COVERAGE_TARGETS graph_lib)
    endif()
    foreach(target_name IN LISTS COVERAGE_TARGETS)
        target_compile_options(${target_name} PRIVATE -O0 -g --coverage)
        target_link_options(${target_name} PRIVATE --coverage)
    endforeach()
endif()
