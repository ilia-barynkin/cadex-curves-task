cmake_minimum_required(VERSION 3.16)

project(main)

find_package(OpenMP REQUIRED)

add_executable(main
    src/main.cpp
)

target_link_libraries(main
    PRIVATE
    OpenMP::OpenMP_CXX
    curves
)