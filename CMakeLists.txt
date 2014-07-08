cmake_minimum_required(VERSION 2.8)
project(MiniLD53)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${PROJECT_BINARY_DIR}")
set(CMAKE_MODULE_PATH "${PROJECT_SOURCE_DIR}/cmake/modules/")

add_subdirectory(src)