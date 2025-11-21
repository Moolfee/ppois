cmake_minimum_required(VERSION 3.16)
project(ArtGalleryTests LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

file(GLOB_RECURSE CLASS_SOURCES "domain/*.cpp")
list(FILTER CLASS_SOURCES EXCLUDE REGEX ".*/Test[^/]*\\.cpp$")

file(GLOB_RECURSE TEST_SOURCES "domain/*/Test*.cpp")

add_library(gallery_lib ${CLASS_SOURCES})
target_include_directories(gallery_lib PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})

add_library(simple_gtest STATIC gtest/gtest_main.cpp)
target_include_directories(simple_gtest PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/gtest)

add_executable(gallery_tests ${TEST_SOURCES})
target_include_directories(gallery_tests PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
target_link_libraries(gallery_tests PRIVATE gallery_lib simple_gtest)
