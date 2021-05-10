# Specify minimum required version of CMake.
cmake_minimum_required(VERSION 3.16 FATAL_ERROR)

# Specify project and identify languages used.
project(cgal LANGUAGES CXX)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

# Enable verbose makefiles.
# set(CMAKE_VERBOSE_MAKEFILE true)

find_package(CGAL)
# add_executable(my_executable my_source_file.cpp)
# target_link_libraries(my_executable CGAL::CGAL)


# Add each source code to a target.
file(GLOB_RECURSE code_sources "*.cpp")
foreach(code_src ${code_sources})
    get_filename_component(targets ${code_src} NAME_WE)
    add_executable(${targets} ${code_src})
    target_link_libraries(${targets} CGAL::CGAL) # Configure CGAL
endforeach()

# Turn off CGAL warning about build type.
set(CGAL_DO_NOT_WARN_ABOUT_CMAKE_BUILD_TYPE TRUE)

# Address sanitizer.
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -fsanitize=address")
set(CMAKE_CXX_FLAGS "${CMAKE_EXE_LINKER_FLAGS} -fsanitize=address")

# Undefined behaviour sanitizer.
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -fsanitize=undefined")
set(CMAKE_CXX_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} -fsanitize=undefined")