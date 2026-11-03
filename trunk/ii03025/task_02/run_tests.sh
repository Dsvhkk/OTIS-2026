#!/bin/bash
set -e

echo "======================================="
echo " Сборка проекта..."
echo "======================================="

rm -rf build
mkdir build
cd build

cmake .. -DCMAKE_BUILD_TYPE=Debug
cmake --build .

echo "======================================="
echo " Запуск модульных тестов (Google Test)..."
echo "======================================="
./tests

echo "======================================="
echo " Отчёт о покрытии кода"
echo "======================================="
gcovr -r .. --gcov-executable "xcrun llvm-cov gcov" \
  --exclude "../test" --exclude ".*_deps.*" --exclude ".*main.cpp"

cd ..