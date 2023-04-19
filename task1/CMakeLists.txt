cmake_minimum_required(VERSION 3.12.0)
project(Task_1 VERSION 0.1.0)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${CMAKE_CURRENT_SOURCE_DIR}/bin")

set(SRC_PATH       "${CMAKE_CURRENT_SOURCE_DIR}/src")
set(LIB_PATH       "${CMAKE_CURRENT_SOURCE_DIR}/lib")
set(INCLUDE_PATH   "${CMAKE_CURRENT_SOURCE_DIR}/include"
                   "${CMAKE_CURRENT_SOURCE_DIR}/include/imgui")

list(APPEND LIBS
    ${LIB_PATH}/libglad.a
    ${LIB_PATH}/libglfw3.a
    ${LIB_PATH}/libimgui.a
)

file(GLOB TASK1_SRC CONFIGURE_DEPENDS
    ${SRC_PATH}/*cpp
)

add_executable(task1 ${TASK1_SRC})

target_include_directories(task1 PRIVATE ${INCLUDE_PATH})
target_link_libraries(task1 PRIVATE ${LIBS})