cmake_minimum_required(VERSION 2.8)
project(MiniLD53)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${PROJECT_BINARY_DIR}")
set(CMAKE_MODULE_PATH "${PROJECT_SOURCE_DIR}/cmake/modules/")

find_package(SFML 2.1 COMPONENTS system window graphics audio REQUIRED)
find_package(Box2D REQUIRED)

add_subdirectory(src)