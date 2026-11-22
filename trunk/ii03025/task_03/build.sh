#!/bin/bash

echo "=================================="
echo "СБОРКА ЛАБОРАТОРНОЙ РАБОТЫ №3"
echo "=================================="

echo ""
echo "Этап 1. Подготовка CMake..."
cmake -S . -B build

if [ $? -ne 0 ]; then
    echo "Ошибка конфигурации CMake!"
    exit 1
fi

echo ""
echo "Этап 2. Компиляция проекта..."
cmake --build build

if [ $? -ne 0 ]; then
    echo "Ошибка сборки проекта!"
    exit 1
fi

echo ""
echo "Сборка успешно завершена!"
