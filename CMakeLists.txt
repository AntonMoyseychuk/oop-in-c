cmake_minimum_required(VERSION 3.2.0)

set(CMAKE_C_STANDARD 11)

project(oop-in-c)

file(GLOB SRC "${PROJECT_SOURCE_DIR}/src/*.c")

add_executable(${PROJECT_NAME} ${SRC})