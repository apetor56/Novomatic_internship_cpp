cmake_minimum_required(VERSION 3.12.0)
project(Task_3 VERSION 0.1.0)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${CMAKE_CURRENT_SOURCE_DIR}/bin")
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY "${CMAKE_CURRENT_SOURCE_DIR}/tests/lib")
set(SRC_PATH "${CMAKE_CURRENT_SOURCE_DIR}/src")
set(INCLUDE_PATH "${CMAKE_CURRENT_SOURCE_DIR}/include")

add_library(task3 ${SRC_PATH}/task3.cpp)
add_executable(main ${SRC_PATH}/task3.cpp ${SRC_PATH}/main.cpp )

target_include_directories(task3 PUBLIC ${INCLUDE_PATH})
target_include_directories(main PUBLIC ${INCLUDE_PATH})

add_subdirectory(tests)