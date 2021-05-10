# Specify minimum required version of CMake.
cmake_minimum_required(VERSION 3.16 FATAL_ERROR)

# Specify project and identify languages used.
project(chapter6 LANGUAGES CXX)

# Enable verbose makefiles.
# set(CMAKE_VERBOSE_MAKEFILE true)

# Add each source code to a target.
file(GLOB_RECURSE code_sources "*.cpp")
foreach(code_src ${code_sources})
    get_filename_component(targets ${code_src} NAME_WE)
    add_executable(${targets} ${code_src})
endforeach()

# Address sanitizer.
set (CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -fsanitize=address")
set (CMAKE_CXX_FLAGS "${CMAKE_EXE_LINKER_FLAGS} -fsanitize=address")

# Undefined behaviour sanitizer.
set (CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -fsanitize=undefined")
set (CMAKE_CXX_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} -fsanitize=undefined")