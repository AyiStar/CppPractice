cmake_minimum_required(VERSION 3.15)

project(cpp_practice)
set(CMAKE_CXX_STANDARD 20)

if (MSVC)
    # warning level 4
    add_compile_options(/W4)
else()
    # additional warnings
    add_compile_options(-Wall -Wextra -Wpedantic)
endif()

find_package(Catch2 REQUIRED)

add_subdirectory(leetcode/ leetcode/)
