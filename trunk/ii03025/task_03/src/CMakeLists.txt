set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
add_library(pid_core
    ../../task_01/src/model19.cpp
    ../../task_01/src/model23.cpp
    ../../task_01/src/model37.cpp
    pid.cpp
)

target_include_directories(pid_core PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}
)
