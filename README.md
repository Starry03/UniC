# UniC

## Version 1.3

## About

Feel free to use it, but please note:

1. it's not optimized for performance
2. it could be obviously improved

## Data structures

1. Matrices
1. Vector
1. Node
1. Linked list
1. Queue
1. Binary tree
1. Dictionary

### Dictionaries

Handles everything

example:

```c
#include <stdio.h>
#include <stdlib.h>
#include "./DataStructures/Dictionary/Dictionary.h"

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

1. Does not resize
2. Handles 8 bytes data, use malloc'd pointers to handle bigger datas

## Algorithms

1. Search
2. Sort

## Libft

Basic implementation

## Utilities

1. Types (used in the library)
2. Dealloc
3. Hashing

