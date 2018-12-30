cmake_minimum_required(VERSION 3.9)
project(ASCII_Rouguelike)

set(CMAKE_CXX_STANDARD 11)

add_executable(ASCII_Rouguelike main.cpp GameSystem.cpp Player.cpp Level.cpp)