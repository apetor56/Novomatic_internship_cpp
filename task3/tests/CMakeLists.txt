cmake_minimum_required(VERSION 3.12.0)
project(test VERSION 0.1.0)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${CMAKE_CURRENT_SOURCE_DIR}")
set(INCLUDE_PATH "${CMAKE_CURRENT_SOURCE_DIR}/include")
set(LIB_PATH "${CMAKE_CURRENT_SOURCE_DIR}/lib")

enable_testing()

add_executable(
  test_task3
  test_task3.cpp
)

list(APPEND LIBS
    ${LIB_PATH}/libgtest.a
    ${LIB_PATH}/libgtest_main.a
    ${LIB_PATH}/libtask3.a
)

target_include_directories(test_task3 PRIVATE ${INCLUDE_PATH})
target_link_libraries(test_task3 PRIVATE ${LIBS})