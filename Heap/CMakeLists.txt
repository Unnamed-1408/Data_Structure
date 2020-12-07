cmake_minimum_required(VERSION 3.5)

project(Priority_queue LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(Priority_queue main.cpp Priority_queue.h Priority_queue.cpp)
