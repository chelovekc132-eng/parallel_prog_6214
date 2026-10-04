cmake_minimum_required(VERSION 3.28)

project(ParallelProgramming
    VERSION 1.0
    LANGUAGES CXX
)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

add_executable(matrix_multiplication
    lab1/cpp/main.cpp
    lab1/cpp/matrix.cpp
)

target_sources(matrix_multiplication
    PRIVATE
        FILE_SET cxx_modules TYPE CXX_MODULES
        BASE_DIRS lab1/cpp
        FILES
            lab1/cpp/matrix.ixx
)

if (MSVC)
    target_compile_options(matrix_multiplication PRIVATE
        /W4
        /permissive-
    )
else()
    target_compile_options(matrix_multiplication PRIVATE
        -Wall
        -Wextra
        -Wpedantic
    )
endif()
