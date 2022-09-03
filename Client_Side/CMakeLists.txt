cmake_minimum_required(VERSION 3.23)
project(Client_Side)

set(CMAKE_CXX_STANDARD 11)
add_library(IO)
add_library(Commands)
add_executable(Client_Side main.cpp CLI.cpp CLI.h)