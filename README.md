# UniC

### Version 1.5

### Latest features & changes

- Dictionary (Hashmap)
- Hashing function

## About

General purpose library

Feel free to use it, but please note:

- it's not optimized for performance
- it could be obviously improved

## Data structures

- Matrices
- Vector
- Node
- Linked list
- Queue
- Binary tree
- Dictionary

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

- Does not resize
- Handles 8 bytes data, use malloc'd pointers to handle bigger datas

## Algorithms

- Search
- Sort

## Libft

Basic implementation

