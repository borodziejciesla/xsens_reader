cmake_minimum_required(VERSION 3.10 FATAL_ERROR)

add_library(handler OBJECT
    src/xsens_reader_handler.cpp
)

### Xsens ###
include_directories(components/xsens/include)
link_directories(components/xsens/lib)
target_link_libraries(${PROJECT_NAME}
    libxstypes.so
    libxsensdeviceapi.so
)

target_include_directories(handler PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}/include
)