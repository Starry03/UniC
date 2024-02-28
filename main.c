#include <stdio.h>
#include <stdlib.h>
#include "./DataStructures/Dictionary/Dictionary.h"
#include "./Utils/Dealloc/Dealloc.h"

void alloc(Dict d)
{
	static int i = 0;
	Dict_Add(d, (Generic)i, (Generic)10, NULL, NULL);
	i++;
}

int main() {
	Dict dict = Dict_Init(100);
	int i = 0;
	while (i++ < 100)
		alloc(dict);
	Dict_Status(dict);
	int a = (int)Dict_Get(dict, 0);
	printf("%d\n", a);
	Dict_Free(dict);
}
