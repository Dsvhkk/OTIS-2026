set(TASK01_SRC "путь_к_task_01/src")

add_executable(OTIS_Lab3
    src/main.cpp
    src/pid.cpp
    "${TASK01_SRC}/model19.cpp"
    "${TASK01_SRC}/model23.cpp"
    "${TASK01_SRC}/model37.cpp"
)
