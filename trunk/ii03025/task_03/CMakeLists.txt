cmake_minimum_required(VERSION 3.14)

project(OTIS_Lab3_PID)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_subdirectory(src)

# Основная программа
add_executable(OTIS_Lab3
    src/main.cpp
)

target_link_libraries(OTIS_Lab3 PRIVATE pid_core)

# Google Test
include(FetchContent)

if(POLICY CMP0135)
    cmake_policy(SET CMP0135 NEW)
endif()

FetchContent_Declare(
    googletest
    URL https://github.com/google/googletest/archive/refs/tags/v1.14.0.zip
)

FetchContent_MakeAvailable(googletest)

enable_testing()

# Тесты
add_executable(tests
    test/test_pid.cpp
)

target_link_libraries(tests
    PRIVATE
    pid_core
    GTest::gtest_main
)

include(GoogleTest)

gtest_discover_tests(tests)
