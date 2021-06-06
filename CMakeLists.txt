cmake_minimum_required(VERSION 3.10 FATAL_ERROR)

set(PROJECT_NAME xsens_reader)
project(${PROJECT_NAME})

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)

include_directories(
    include
)

add_executable(${PROJECT_NAME}
    src/main.cpp)
