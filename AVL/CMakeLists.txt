cmake_minimum_required(VERSION 3.5)

project(AVL LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(AVL main.cpp AVL.h AVL.cpp)
