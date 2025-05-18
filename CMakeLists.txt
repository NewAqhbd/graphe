cmake_minimum_required(VERSION 3.8)

project(projet)

set(CMAKE_C_STANDARD 11)

add_executable(projet
    src/main.cpp
)

target_compile_options(projet PRIVATE -Wall -Wextra -Wpedantic)

