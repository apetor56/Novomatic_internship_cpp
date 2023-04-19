cmake_minimum_required(VERSION 3.12.0)
project(Novomatic VERSION 0.1.0)

set(CMAKE_CXX_STANDARD 17) 
set(CMAKE_CXX_STANDARD_REQUIRED ON)
add_compile_options(-Wall -pedantic)

add_subdirectory(task1)
add_subdirectory(task2)
add_subdirectory(task3)