cmake_minimum_required(VERSION 3.17)
project(Assignment_3)

set(CMAKE_CXX_FLAGS "-static")
set(CMAKE_CXX_STANDARD 14)

set(CMAKE_CXX_FLAGS "-static")

add_executable(Assignment_3
        src/main.cpp src/Node.h src/BST.cpp src/BST.h src/Dictionary.cpp src/Dictionary.h)
