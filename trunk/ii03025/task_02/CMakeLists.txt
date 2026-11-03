cmake_minimum_required(VERSION 3.15)
project(OTIS_Lab2_Var19)

add_compile_options(--coverage -O0 -g)
add_link_options(--coverage)

include(FetchContent)
FetchContent_Declare(googletest
  URL https://github.com/google/googletest/archive/refs/tags/v1.14.0.zip)
FetchContent_MakeAvailable(googletest)

set(CORE src/model19.cpp src/model23.cpp src/model37.cpp
         src/stability.cpp src/simulation.cpp)

add_executable(task_02 src/main.cpp ${CORE})

add_executable(tests test/stability_checks.cpp test/model_checks.cpp
                     test/simulation_checks.cpp ${CORE})
target_include_directories(tests PRIVATE src)
target_link_libraries(tests GTest::gtest_main)

enable_testing()
add_test(NAME tests COMMAND tests)