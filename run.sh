#!/bin/bash

BUILD_DIR="build"

mkdir -p "$BUILD_DIR"

cd "$BUILD_DIR" || exit

cmake ..

make

if [[ "$1" == "--valgrind" ]]; then
	valgrind ./main
elif [[ "$1" == "--gdb" ]]; then
	gdb ./main
else
	./main
fi
