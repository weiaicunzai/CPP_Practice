cmake_minimum_required(VERSION 2.6)
project(sort)
set (CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=gnu++11")

add_executable(insertion_sort insertion_sort.cpp)
add_executable(quick_sort quick_sort.cpp)
