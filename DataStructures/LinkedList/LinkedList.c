//
// Created by andre on 8/8/2023.
//

#include "LinkedList.h"

#include <stdlib.h>

LinkedList EmptyList() {
	return (LinkedList) NULL;
}

static LinkedList LinkedList_Alloc() {
	return (LinkedList) malloc(sizeof(Node_));
}

LinkedList LinkedList_Init(Generic value) {
	LinkedList list = LinkedList_Alloc();
	if (!list)
		return EmptyList();
	list->info = value;
	list->next = EmptyList();
	return list;
}

void LinkedList_Push(LinkedList *list, Generic object) {
	if (!list || !object)
		return;
	LinkedList newNode = Node_Init(object);
	if (!newNode)
		return;
	newNode->next = *list;
	*list = newNode;
}

void LinkedList_Append(LinkedList *list, Generic value) {
	if (!list || !value)
		return;
	if (*list == EmptyList()) {
		*list = LinkedList_Init(value);
		return;
	}
	LinkedList newNode = Node_Init(value);
	while (*list != EmptyList())
		list = &(*list)->next;
	*list = newNode;
}

void LinkedList_Remove(LinkedList *list, Generic value, void(*dealloc)(Generic)) {
	if (!list || !value)
		return;
	while (*list != EmptyList()) {
		if (LinkedList_GetInfo(*list) == value) {
			LinkedList target = LinkedList_GetNext(*list);
			dealloc((*list)->info);
			free(*list);
			*list = target;
			return;
		}
		list = &((*list)->next);
	}
}

LinkedList LinkedList_GetNode(LinkedList list, Generic value)
{
	if (!list || !value)
		return EmptyList();
	while (LinkedList_GetInfo(list) != value)
		list = LinkedList_GetNext(list);
	return list;
}

LinkedList LinkedList_GetNext(LinkedList list) {
	if (!list)
		return (LinkedList) NULL;
	return list->next;
}

Generic LinkedList_GetInfo(LinkedList list) {
	if (!list)
		return (Generic) NULL;
	return list->info;
}

void LinkedList_Dealloc(LinkedList head, void(*dealloc)(Generic)) {
	LinkedList next;
	if (!head || !dealloc)
		return;
	while (head != NULL) {
		next = head->next;
		dealloc(head->info);
		free(head);
		head = next;
	}
}
