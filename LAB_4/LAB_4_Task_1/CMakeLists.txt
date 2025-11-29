cmake_minimum_required(VERSION 3.16)
project(SortingLabTests LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

file(GLOB_RECURSE CLASS_SOURCES "domain/*.cpp")
list(FILTER CLASS_SOURCES EXCLUDE REGEX ".*/Test[^/]*\\.cpp$")

file(GLOB_RECURSE TEST_SOURCES "domain/*/Test*.cpp")

add_library(sorting_lib ${CLASS_SOURCES})
target_include_directories(sorting_lib PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})

add_library(simple_gtest STATIC gtest/gtest_main.cpp)
target_include_directories(simple_gtest PUBLIC ${CMAKE_CURRENT_SOURCE_DIR} ${CMAKE_CURRENT_SOURCE_DIR}/gtest)

add_executable(sorting_tests ${TEST_SOURCES})
target_include_directories(sorting_tests PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
target_link_libraries(sorting_tests PRIVATE sorting_lib simple_gtest)

option(ENABLE_COVERAGE "Enable gcov/lcov coverage flags" ON)
if(ENABLE_COVERAGE AND CMAKE_CXX_COMPILER_ID MATCHES "GNU|Clang")
    foreach(target_name IN ITEMS sorting_lib sorting_tests simple_gtest)
        target_compile_options(${target_name} PRIVATE -O0 -g --coverage)
        target_link_options(${target_name} PRIVATE --coverage)
    endforeach()
endif()
