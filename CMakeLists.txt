cmake_minimum_required(VERSION 3.26)
project(DataStructuresCpp)

set(CMAKE_CXX_STANDARD 23)

add_executable(DataStructuresCpp main.cpp
        DArray.cpp
        DArray.h
        LinkedList.cpp
        LinkedList.h
        Queue.cpp
        Queue.h
        Vectors.h
)
