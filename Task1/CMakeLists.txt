cmake_minimum_required(VERSION 3.10)
project(Project_Conquer_Task1)
set(CMAKE_CXX_STANDARD 17)

# Place runtime outputs (executables) in the build directory
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR})

add_executable(task1 src/main.cpp src/singleton/singleton_main.cpp src/settings_manager/settings_manager.cpp src/task/task_base.cpp src/explorer/explorer.cpp src/task/audio_task.cpp)

target_include_directories(task1 PUBLIC 
    ${PROJECT_SOURCE_DIR}/src/
    ${PROJECT_SOURCE_DIR}/src/settings_manager 
    ${PROJECT_SOURCE_DIR}/src/singleton
    ${PROJECT_SOURCE_DIR}/src/task
    ${PROJECT_SOURCE_DIR}/src/explorer
)

# Explicitly ensure the produced executable is named 'task1'
set_target_properties(task1 PROPERTIES OUTPUT_NAME "task1")
