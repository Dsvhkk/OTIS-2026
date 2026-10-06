cmake_minimum_required(VERSION 3.15)
project(OTIS_Lab1_Var19)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

file(GLOB_RECURSE SOURCES "src/*.cpp" "src/*.h")
add_executable(task_01 ${SOURCES})