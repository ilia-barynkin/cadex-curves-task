cmake_minimum_required(VERSION 3.16)

project(MyProject)

add_subdirectory(curves)
add_subdirectory(main)
add_subdirectory(tests)
add_subdirectory(python)

include(CTest)