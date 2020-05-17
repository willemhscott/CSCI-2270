cmake_minimum_required(VERSION 3.14)
project(lab-12)

set(CMAKE_CXX_STANDARD 14)

#add_executable(DataStructures Structures/LinkedList/LinkedList.cpp lab-1/hello.cpp lab-1/hello.h)
add_executable(lab-12 driver.cpp MinHeap.hpp MinHeap.cpp)
#DriverQueue.cpp QueueLL.cpp QueueLL.hpp