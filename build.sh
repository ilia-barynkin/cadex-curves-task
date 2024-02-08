#!/bin/sh

rm -rf build
mkdir build
cd build
cmake ..
cmake --build .
ctest --rerun-failed --output-on-failure
./main/main
cd ..