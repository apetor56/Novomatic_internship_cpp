@echo off

if not exist build (
    mkdir build
    cmake -S . -B build -G "MinGW Makefiles"
)

cmake --build build