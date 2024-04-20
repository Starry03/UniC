//
// Created by andre on 8/8/2023.
//

#include "LinkedList.h"
#include <stdlib.h>


LinkedList	EmptyList(void)
{
	return ((LinkedList)NULL);
}

static LinkedList	LinkedList_Alloc(void)
{
	return (LinkedList)malloc(sizeof(Node_));
}

LinkedList	LinkedList_Init(Generic value)
{
	LinkedList list = LinkedList_Alloc();
	if (!list)
		return (EmptyList());
	list->info = value;
	list->next = EmptyList();
	return (list);
}

void	LinkedList_Push(LinkedList *list, Generic object)
{
	LinkedList node;
	
	if (!list || !*list)
		return ;
	node = LinkedList_Init(object);
	node->next = *list;
	*list = node;
}

void	LinkedList_Remove(LinkedList *node, void (*dealloc)(Generic))
{
	LinkedList	next;

	if (!node || !*node || !dealloc)
		return ;
	next = LinkedList_GetNext(*node);
	dealloc(LinkedList_GetInfo(*node));
	free(*node);
	*node = next;
}

void	LinkedList_RemoveByValue(LinkedList *list, Generic value,
		void (*dealloc)(Generic))
{
	if (!list || !*list || !value)
		return ;
	while (LinkedList_GetInfo(*list) != value)
		list = &((*list)->next);
	LinkedList_Remove(list, dealloc);
}

LinkedList	LinkedList_GetNode(LinkedList list, Generic value)
{
	if (!list || !value)
		return (EmptyList());
	while (LinkedList_GetInfo(list) != value)
		list = LinkedList_GetNext(list);
	return (list);
}

LinkedList	LinkedList_GetNext(LinkedList list)
{
	if (!list)
		return ((LinkedList)NULL);
	return (list->next);
}

Generic	LinkedList_GetInfo(LinkedList list)
{
	if (!list)
		return ((Generic)NULL);
	return (list->info);
}

LinkedList	LinkedList_GetLast(LinkedList list)
{
	if (!list)
		return (EmptyList());
	while (list->next)
		list = LinkedList_GetNext(list);
	return (list);
}

void	LinkedList_Dealloc(LinkedList head, void (*dealloc)(Generic))
{
	LinkedList next;
	if (!head)
		return ;
	while (head)
	{
		next = head->next;
		if (dealloc)
			dealloc(head->info);
		free(head);
		head = next;
	}
}
