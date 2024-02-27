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

	Dict dict = Dict_Init(10);
	Dict_Add(dict, a, b, &free_int, &free_int);

	printf("value: %d\n", *(int *)Dict_Get(dict, a));

	Dict_Free(dict);
}
