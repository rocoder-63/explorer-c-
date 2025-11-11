cmake_minimum_required(VERSION 3.10)
project(Project_Conquer_Task1)
set(CMAKE_CXX_STANDARD 17)

# Place runtime outputs (executables) in the build directory
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR})

add_executable(task1 src/main.cpp)

# Explicitly ensure the produced executable is named 'task1'
set_target_properties(task1 PROPERTIES OUTPUT_NAME "task1")
