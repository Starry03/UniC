# Starry_CLibrary

## Version 1.3

## About

This is a "library" with the purpose of storing univerity material and to experiment with C

Feel free to use it, but please note:

1. it's not optimized for performance
2. it could be obviously improved

## Data structures

1. Arrays
2. Binary tree
3. Matrices
4. Node
5. Linked list
6. Queue
7. Vector
8. Dictionary

### Dictionaries

Handles native types

example:

```c
#include <stdio.h>
#include <stdlib.h>
#include "./DataStructures/Dictionary/Dictionary.h"
#include "./Utils/Dealloc/Dealloc.h"

void alloc(Dict d)
{
	static int i = 0;
	Dict_Add(d, i++, 10, NULL, NULL);
}

int main() {
	Dict dict = Dict_Init(10);
	int i = 0;
	while (i++ < 10)
		alloc(dict);
	Dict_Status(dict);
	int a = (int)Dict_Get(dict, 0);
	printf("%d\n", a);
	Dict_Free(dict);
}


```

## Algorithms

1. Search
2. Sort

## Utilities

###### functions are implemented from scratch

1. Math
2. String

## Testing

1. int to int

```c
int inputs[] = {1, 4, 8, 16, INT_MAX};
int expected[] = {1, 2, 0, 4, 0};
test_int_to_int(inputs, expected, sizeof(inputs) / 4, &Math_int_sqrt);
```
