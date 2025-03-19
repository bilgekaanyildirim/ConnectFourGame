cmake_minimum_required(VERSION 3.27)
project(ConnectFourGame)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(ConnectFourGame
        Board.cpp
        Board.h
        main.cpp
        Player.cpp
        Player.h)
