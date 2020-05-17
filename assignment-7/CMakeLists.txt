cmake_minimum_required(VERSION 3.14)
project(assignment-7)

set(CMAKE_CXX_STANDARD 14)

add_executable(assignment-7
        MovieTree.cpp
        MovieTree.hpp
        driver.cpp ../Project/main.cpp ../Project/BookCollection.cpp ../Project/BookCollection.h)