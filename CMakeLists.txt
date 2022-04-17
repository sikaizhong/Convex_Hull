# Created by the script cgal_create_cmake_script
# This is the CMake script for compiling a CGAL application.

cmake_minimum_required(VERSION 3.1...3.20)
project(Convex_Hull)
set(CMAKE_CXX_STANDARD 17)

add_subdirectory(src/kernel_version)
add_subdirectory(src/non_template_version)


