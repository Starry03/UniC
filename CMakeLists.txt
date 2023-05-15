cmake_minimum_required(VERSION 3.25)
project(Starry C)

set(CMAKE_C_STANDARD 17)

add_executable(Starry main.c Matrix.h LinkedList.h LinkedList.c Search.h Search.c Utils.c Utils.h Sorting.c Sorting.h Matrix.c SetList.c SetList.h Log.c Log.h Vector.c Vector.h StringFX.c StringFX.h Nodes.h Queue.c Queue.h Nodes.c Stack.c Stack.h BinaryTree.c BinaryTree.h)
