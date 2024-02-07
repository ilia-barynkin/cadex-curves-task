cmake_minimum_required(VERSION 3.16)

project(curves VERSION 0.0.1)

add_library(curves SHARED
    src/curve.cpp
    src/helix.cpp
    src/ellipse.cpp
    src/circle.cpp
)

target_include_directories(curves PUBLIC include)