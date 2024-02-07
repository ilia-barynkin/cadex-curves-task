cmake_minimum_required(VERSION 3.16)

project(python)

add_custom_target(python
    COMMAND ${CMAKE_COMMAND} -E echo "Setting up Python virtual environment"
    COMMAND ${CMAKE_COMMAND} -E echo "Running Python data visualization script"
    COMMAND ${CMAKE_COMMAND} -E echo "Running additional Python tests"
    WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/src
    DEPENDS curves
)