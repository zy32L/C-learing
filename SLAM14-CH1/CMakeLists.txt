cmake_minimum_required(VERSION 3.26)
project(ch1)

set(CMAKE_CXX_STANDARD 17)

add_library(hello libHelloSLAM.cpp)
add_executable(ch1 main.cpp
        libHelloSLAM.cpp
        libHelloSLAM.h)
