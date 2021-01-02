cmake_minimum_required(VERSION 3.17)
project(WindowsUtilities)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(WindowsUtilities
        main.cpp
        string_util.cpp
        string_util.h)
