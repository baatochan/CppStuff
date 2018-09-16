cmake_minimum_required(VERSION 3.11)
project(SpdlogTest)

set(CMAKE_CXX_STANDARD 11)

find_package (Threads)

add_executable(SpdlogTest main.cpp)
target_link_libraries (SpdlogTest ${CMAKE_THREAD_LIBS_INIT})
