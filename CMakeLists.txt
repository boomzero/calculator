cmake_minimum_required(VERSION 3.20)
project(calculator)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_EXE_LINKER_FLAGS "-static")

add_executable(calculator main.cpp)
add_executable(checker checker.cpp testlib/testlib.h)

