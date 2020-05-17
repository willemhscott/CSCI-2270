cmake_minimum_required(VERSION 3.14)
project(project)

set(CMAKE_CXX_STANDARD 14)

#add_executable(DataStructures Structures/LinkedList/LinkedList.cpp lab-1/hello.cpp lab-1/hello.h)
add_executable(
        project
        BookCollection.cpp
        BookCollection.h
        CheckoutTimers.cpp
        CheckoutTimers.h
        AsyncManager.cpp
        AsyncManager.h
        main.cpp
)

if (DEBUG_LEVEL)
    add_definitions(-DDEBUG_LEVEL=${DEBUG_LEVEL})
endif()