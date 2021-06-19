cmake_minimum_required(VERSION 3.10 FATAL_ERROR)

set(PROJECT_NAME xsens_reader)
project(${PROJECT_NAME})

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_BUILD_TYPE Debug)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++17")

### Core ###
target_include_directories(${PROJECT_NAME} PRIVATE
  $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/components>
)

include_directories(${PROJECT_NAME} PUBLIC
    include
)
add_library(${PROJECT_NAME}
    src/xsens_reader_handler.cpp)

### Unit Tests ###
enable_testing()
find_package(GTest REQUIRED)
include_directories(${GTEST_INCLUDE_DIR})

target_link_libraries(${PROJECT_NAME} GTest::GTest GTest::Main)

add_subdirectory(tests)