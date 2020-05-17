cmake_minimum_required(VERSION 3.14)
project(DataStructures)

set(CMAKE_CXX_STANDARD 14)

#add_executable(DataStructures Structures/LinkedList/LinkedList.cpp lab-1/hello.cpp lab-1/hello.h)
add_executable(DataStructures
        #Structures/LinkedList/LinkedList.cpp
        #Structures/LinkedList/LinkedList.cpp
        #Structures/LinkedList/LinkedList.h
        Structures/HashTable/HashTable.h
        Structures/HashTable/HashTable.cpp)