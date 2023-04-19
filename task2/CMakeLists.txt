cmake_minimum_required(VERSION 3.12.0)
project(Task_2 VERSION 0.1.0)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${CMAKE_CURRENT_SOURCE_DIR}/bin")
set(SRC_PATH "${CMAKE_CURRENT_SOURCE_DIR}/src")

add_executable(task2 ${SRC_PATH}/main.cpp)