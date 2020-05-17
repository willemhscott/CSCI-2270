cmake_minimum_required(VERSION 3.14)
project(midterm-20191004)

set(CMAKE_CXX_STANDARD 14)

#add_executable(DataStructures Structures/LinkedList/LinkedList.cpp lab-1/hello.cpp lab-1/hello.h)
add_executable(
        midterm-20191004
        Array/Array.cpp
        LinkedList/LinkedList.cpp
        LinkedList/LinkedList.hpp
        LinkedList/LinkedListDriver.cpp
        StacksQueue/QueueLL.cpp
        StacksQueue/QueueLL.hpp
        StacksQueue/STACKARR.cpp
        StacksQueue/STACKARR.hpp
        StacksQueue/StackLL.cpp
        StacksQueue/StackLL.hpp
)