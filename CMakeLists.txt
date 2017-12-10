cmake_minimum_required(VERSION 2.8.7)

project(Mines)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

include_directories(${CMAKE_CURRENT_SOURCE_DIR}/include/)

add_library(${PROJECT_NAME} STATIC ${CMAKE_CURRENT_SOURCE_DIR}/sources/group.cpp /sources/cell.cpp) 

add_executable(Examples ${CMAKE_CURRENT_SOURCE_DIR}/examples/main.cpp /include/cell.hpp /include/group.hpp /sources/cell.cpp /sources/group.cpp)
