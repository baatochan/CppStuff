cmake_minimum_required(VERSION 3.10)
project(CountHexDigits)

set(CMAKE_CXX_STANDARD 11)

find_package (Threads)

add_executable(CountHexDigits main.cpp Program.cpp Program.h)
target_link_libraries (CountHexDigits ${CMAKE_THREAD_LIBS_INIT})
