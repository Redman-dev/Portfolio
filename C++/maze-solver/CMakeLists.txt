cmake_minimum_required(VERSION 3.17)
project(Assignment_2)

set(CMAKE_CXX_FLAGS "-static")
set(CMAKE_CXX_STANDARD 23)

add_executable(Assignment_2
        src/main.cpp src/Map.cpp src/Map.h src/Node.h src/Stack.cpp src/Stack.h src/Point.cpp src/Point.h)
