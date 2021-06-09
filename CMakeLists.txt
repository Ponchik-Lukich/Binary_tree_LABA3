cmake_minimum_required(VERSION 3.17)
project(LABA3)

set(CMAKE_CXX_STANDARD 14)

add_subdirectory(tests)

add_executable(LABA3 Main.cpp complex.h person.h)

