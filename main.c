#include <stdio.h>
#include <stdlib.h>
#include "./DataStructures/Dictionary/Dictionary.h"

int main() {
	int a = 10;
	int b = 20;
	Dict dict = Dict_Init(10);
	Dict_Add(dict, &a, &b, NULL, NULL);
	printf("value: %d\n", *(int *)Dict_Get(dict, &a));
	Dict_Free(dict);
}

