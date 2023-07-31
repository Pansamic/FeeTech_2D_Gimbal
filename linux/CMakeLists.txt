cmake_Minimum_required(VERSION 2.8.13)
set(project "gimbal_test")
project(${project})

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 -O3")

include_directories(./inc)
link_directories(./src)

file(GLOB hdrs ./inc/*.h)
file(GLOB srs ./src/*.cpp)

message(STATUS "hdrs: ${hdrs}")
message(STATUS "srs: ${srs}")

add_executable(${project} main.cpp ${hdrs} ${srs})