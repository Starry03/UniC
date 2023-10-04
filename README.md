# Starry_CLibrary

## Version 1.2

## Data structures

1. Arrays
2. Binary tree
3. Linked list
4. Matrices
5. Node
6. Queue
7. Vector
8. Dictionary

### Dictionaries

Hold every type of values (int, custom structs etc.)
example:

```c
Matrix matrix = MatrixInit(4, 4);
Matrix_Fill(matrix, 1, 1, 1);

Dictionary dict = Dictionary_Create(100);
Dictionary_Add(&dict, matrix, CreateInt(5), "struct");
int mat = Dictionary_GetInt(Dictionary_Get(dict, matrix, "struct"));
printf("%d\n", mat);
```

## Algorithms

1. Search
2. Sort

## Utilities

1. Math

## Testing

1. int to int

```c
int inputs[] = {1, 4, 8, 16, INT_MAX};
int expected[] = {1, 2, 0, 4, 0};
test_int_to_int(inputs, expected, sizeof(inputs) / 4, &Math_int_sqrt);
```
