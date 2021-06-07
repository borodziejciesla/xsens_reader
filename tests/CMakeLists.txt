set(TEST_PROJECT_NAME xsens_reader_tests)

project(${PROJECT_NAME} VERSION 0.1)

add_executable(${TEST_PROJECT_NAME}
xsens_reader_tests.cpp
)

target_link_libraries(${TEST_PROJECT_NAME}
    gtest_main
    ${PROJECT_NAME}
)