cmake_minimum_required(VERSION 3.16)
project(FractalSquare LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

add_library(fractal_lib FractalSquare.cpp)
target_include_directories(fractal_lib PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})

add_executable(fractal_demo main.cpp)
target_link_libraries(fractal_demo PRIVATE fractal_lib)
