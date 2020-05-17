cmake_minimum_required(VERSION 3.14)
project(lab-11)

set(CMAKE_CXX_STANDARD 14)

#add_executable(DataStructures Structures/LinkedList/LinkedList.cpp lab-1/hello.cpp lab-1/hello.h)
add_executable(lab-11 driver.cpp hash.hpp hash.cpp)
#DriverQueue.cpp QueueLL.cpp QueueLL.hpp