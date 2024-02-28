#include <stdio.h>
#include <stdlib.h>
#include "./DataStructures/Dictionary/Dictionary.h"
#include "./Utils/Dealloc/Dealloc.h"

void alloc(Dict d)
{
	static int i = 0;
	int *key = (int *)malloc(sizeof(int));
	*key = i++;

	int *value = (int *)malloc(sizeof(int));
	*value = 0;

	Dict_Add(d, key, value, &dealloc_int, &dealloc_int);
}

int main() {
	Dict dict = Dict_Init(1000);
	int i = 0;
	while (i++ < 1000)
		alloc(dict);
	Dict_Free(dict);
}

