//
// Created by andre on 8/8/2023.
//

#ifndef STARRY_CLIBRARY_LINKEDLIST_H
#define STARRY_CLIBRARY_LINKEDLIST_H

#endif //STARRY_CLIBRARY_LINKEDLIST_H

#include "Nodes.h"

typedef Node LinkedList;

typedef void* LinkedListType;

LinkedList EmptyList();

LinkedList LinkedList_Init(LinkedListType value);

LinkedList LinkedList_Alloc();

void LinkedList_Push(LinkedList *list, LinkedListType object);

void LinkedList_Append(LinkedList *list, LinkedListType value);

void LinkedList_Remove(LinkedList *list, LinkedListType value);

LinkedList LinkedList_GetNext(LinkedList list);

LinkedListType LinkedList_GetInfo(LinkedList list);

void LinkedList_Dealloc(LinkedList head);
