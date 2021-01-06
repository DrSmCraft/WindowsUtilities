cmake_minimum_required(VERSION 3.17)
project(WindowsUtilities)

set(CMAKE_CXX_STANDARD 17)

include_directories(.)

#add_executable(Main
#        main.cpp
#        string_util.cpp
#        string_util.h)

add_executable(NetshPassword
        NetshPassword.cpp string_util.cpp string_util.h)

add_executable(Logo
        Logo.cpp)

add_executable(Touch Touch.cpp)