cmake_minimum_required(VERSION 3.10)

project(projet)

set(CMAKE_C_STANDARD 11)

add_executable(projet
    src/main.cpp
    src/matrice.cpp
)

include_directories(include)

target_compile_options(projet PRIVATE -Wall -Wextra -Wpedantic)

