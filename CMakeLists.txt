cmake_minimum_required(VERSION 3.22)
project(Leetcode_Exercises)

set(CMAKE_CXX_STANDARD 20)

if (MSVC)
    set(CMAKE_CXX_FLAGS_RELEASE "/O2")
    add_compile_options(/Wall)
else()
    set(CMAKE_CXX_FLAGS_RELEASE "-O3")
    add_compile_options(-Wall -Wextra -Wpedantic
            -Wcast-qual -Wfloat-equal -Wshadow=global -Wlogical-op -Wcast-align)
endif()

add_executable(Leetcode_Exercises
      src/P2007_find_original_array_from_doubled_array.cpp)
set(EXTERNAL_HEADERS_DIR ${CMAKE_CURRENT_SOURCE_DIR}/include COMPILE_FLAGS "...")
target_include_directories(Leetcode_Exercises PRIVATE ${EXTERNAL_HEADERS_DIR} )