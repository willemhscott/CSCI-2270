cmake_minimum_required(VERSION 3.14)
project(exam-1)

set(CMAKE_CXX_STANDARD 14)

#add_executable(DataStructures Structures/LinkedList/LinkedList.cpp lab-1/hello.cpp lab-1/hello.h)
add_executable(exam-1
        #Array/array.cpp
        LinkedList/LinkedList.hpp
        LinkedList/LinkedList.cpp
        LinkedList/LinkedListDriver.cpp
        #StacksQueue/Driver.cpp
        StacksQueue/QUEUEST.cpp
        StacksQueue/QUEUEST.hpp
        StacksQueue/STACKARR.cpp
        StacksQueue/STACKARR.hpp)