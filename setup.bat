@echo off

if not exist build (
    mkdir build
    cmake -S . -B build -G "MinGW Makefiles" -DCMAKE_BUILD_TYPE=Release
)

cmake --build build 