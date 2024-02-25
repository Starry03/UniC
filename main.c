#include <stdio.h>
#include <stdlib.h>
#include "DataStructures/LinkedList/LinkedList.h"

void free_int(Generic addr)
{
	addr = (int *)addr;
	printf("freeing: %p <==> %d\n", addr, *(int *)addr);
	free(addr);
}

int main() {
	int *a = (int *) malloc(sizeof(int));
	*a = 10;

	int *b = (int *) malloc(sizeof(int));
	*b = 20;

	LinkedList list = LinkedList_Init(a);
	LinkedList head = list;
	LinkedList_Append(&list, b);
	// a -> b -> null
	while (list)
	{
		printf("info: %d\n", *(int *)LinkedList_GetInfo(list));
		list = LinkedList_GetNext(list);
	}

	list = head;
	printf("removing b...\n");
	LinkedList_Remove(&list, b, &free_int);

	list = head;
	while (list)
	{
		printf("info: %d\n", *(int *)LinkedList_GetInfo(list));
		list = LinkedList_GetNext(list);
	}

	LinkedList_Dealloc(head, &free_int);
}
