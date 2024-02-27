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

void free_int(Generic addr)
{
	addr = (int *)addr;
	printf("freeing: %p <==> %d\n", addr, *(int *)addr);
	free(addr);
}

int main() {
	int *a, *b;
	a = (malloc(sizeof(int)));
	*a = 10;

	b = (malloc(sizeof(int)));
	*b = 20;

	Dict dict = Dict_init(10);
	Dict_Add(dict, a, b, &free_int, &free_int);

	printf("value: %d\n", *(int *)Dict_Get(dict, a));

	Dict_free(dict);
}
```

Note that dictionary must be deallocated

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
