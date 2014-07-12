cmake_minimum_required(VERSION 2.8)
project(MiniLD53)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${PROJECT_BINARY_DIR}")
set(CMAKE_MODULE_PATH "${PROJECT_SOURCE_DIR}/cmake/modules/")

# Temporary
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

include(cmake/version.cmake)

find_package(SFML 2.1 COMPONENTS system window graphics audio REQUIRED)

add_subdirectory(src)