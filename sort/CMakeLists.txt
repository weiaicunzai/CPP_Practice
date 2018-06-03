cmake_minimum_required(VERSION 2.8)
project(sort)

set (CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=gnu++11 -g")

add_executable(insertion_sort insertion_sort.cpp)
add_executable(quick_sort quick_sort.cpp)
add_executable(heap_sort heap_sort.cpp)
add_executable(bucket_sort bucket_sort.cpp)
add_executable(priority_sort priority_sort.cpp)
