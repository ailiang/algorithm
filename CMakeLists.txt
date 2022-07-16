

cmake_minimum_required(VERSION 3.5)

set(CMAKE_C_COMPILER gcc)
set(CMAKE_CXX_COMPILER g++)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 -g")

project(algorithm C CXX)

add_executable(alg main.cpp)

add_subdirectory(lru)



