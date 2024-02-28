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

