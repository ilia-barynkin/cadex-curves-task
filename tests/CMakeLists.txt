cmake_minimum_required(VERSION 3.16)

project(tests)

find_package(GTest REQUIRED)

enable_testing()

add_executable(tests
    src/tests.cpp
)

target_link_libraries(tests
    PRIVATE
    GTest::GTest
    GTest::Main
    curves
)

gtest_discover_tests(tests)