cmake_minimum_required(VERSION 3.14)
project(lect-190923)

set(CMAKE_CXX_STANDARD 14)

#add_executable(DataStructures Structures/LinkedList/LinkedList.cpp lab-1/hello.cpp lab-1/hello.h)
add_executable(lect-190923 LinkedList.cpp LinkedList.h main.cpp Stack.cpp Stack.h Queue.cpp Queue.h)