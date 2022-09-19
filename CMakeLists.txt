cmake_minimum_required(VERSION 3.15)

project(cpp_practice)

find_package(Catch2 REQUIRED)

aux_source_directory(./leetcode/ LEETCODE_SRCS)
foreach(SRC_NAME ${LEETCODE_SRCS})
    string(REPLACE ".cpp" "" EXE_NAME ${SRC_NAME})
    add_executable(a ${SRC_NAME})
    target_link_libraries(a PRIVATE Catch2::Catch2WithMain)
endforeach()
