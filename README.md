# Starry_CLibrary

## Version 1.3

## About

This is a "library" with the purpose of storing univerity material and to experiment with C

Feel free to use it, but please note that it is not optimized for performance.

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
#include "Dictionary.h"
#include <stdio.h>

int main() {
    Dictionary dict = Dictionary_Create(10);
    Dictionary_Add(
            dict,
            string("key"),
            int_(1),
            STRING
    );
    printf("%d\n", *(int *) Dictionary_Get(dict, string("key"), STRING));
    Dictionary_Dealloc(dict);
}
```

##### Please note that the dictionary will not deallocate the memory of the values you put in it. You must do that yourself.

###### Add & Get will ask for a malloc'd pointer, and will deallocate it in Get.

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
