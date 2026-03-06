cmake_minimum_required(VERSION 4.0)
project(dsa_project2)

set(CMAKE_CXX_STANDARD 20)

add_executable(dsa_project2
        database/anime.csv
        database/rating.csv
        src/dataset.cpp
        src/dataset.h
        src/main.cpp
        src/quicksort.cpp
        src/quicksort.h
        src/heapsort.cpp
        src/heapsort.h
        src/dataset.cpp
)
