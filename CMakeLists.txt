cmake_minimum_required(VERSION 3.20)
project(calculator)

set(CMAKE_CXX_STANDARD 14)

add_executable(calculator main.cpp)
add_executable(checker checker.cpp testlib/testlib.h)

