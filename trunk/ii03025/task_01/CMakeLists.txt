cmake_minimum_required(VERSION 3.15)
project(OTIS_Lab1_Var19)

file(GLOB_RECURSE SOURCES "src/*.cpp" "src/*.h")
add_executable(task_01 ${SOURCES})
