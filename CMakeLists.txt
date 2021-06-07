cmake_minimum_required(VERSION 3.10 FATAL_ERROR)

set(PROJECT_NAME xsens_reader)
project(${PROJECT_NAME})

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

include_directories(${PROJECT_NAME} PUBLIC
    include
)
add_library(${PROJECT_NAME}
    src/xsens_reader.cpp)

# xsens
include_directories(/home/maciek/Downloads/xsens/include)
link_directories(/home/maciek/Downloads/xsens/lib)
target_link_libraries(${PROJECT_NAME}
    libxstypes.so
    libxsensdeviceapi.so
)

### Unit Tests ###
enable_testing()
find_package(GTest REQUIRED)
include_directories(${GTEST_INCLUDE_DIR})

target_link_libraries(${PROJECT_NAME} GTest::GTest GTest::Main)

add_subdirectory(tests)