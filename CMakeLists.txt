cmake_minimum_required(VERSION 4.0)
project(dsa_project2)

set(CMAKE_CXX_STANDARD 20)

add_executable(dsa_project2
        src/main.cpp
        src/dataset.cpp
        src/quicksort.cpp
        src/heapsort.cpp
)
