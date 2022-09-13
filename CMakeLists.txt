cmake_minimum_required(VERSION 3.22)
project(Leetcode_Exercises)

set(CMAKE_CXX_STANDARD 20)

if (MSVC)
    set(CMAKE_CXX_FLAGS_RELEASE "/O2")
    add_compile_options(/Wall)
else()
    set(CMAKE_EXE_LINKER_FLAGS "-static")
    set(CMAKE_CXX_FLAGS_DEBUG "-g")
    set(CMAKE_CXX_FLAGS_RELEASE "-O3")
    add_compile_options(-Wall -Wextra -Wpedantic
            -Wcast-qual -Wfloat-equal -Wshadow=global -Wlogical-op -Wcast-align)
endif()

add_executable(Leetcode_Exercises
        src/P0101_binary_tree_level_order_traversal.cpp)
set(EXTERNAL_HEADERS_DIR ${CMAKE_CURRENT_SOURCE_DIR}/include COMPILE_FLAGS "...")
target_include_directories(Leetcode_Exercises PRIVATE ${EXTERNAL_HEADERS_DIR} )