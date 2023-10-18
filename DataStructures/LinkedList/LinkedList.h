//
// Created by andre on 8/8/2023.
//

#ifndef STARRY_CLIBRARY_LINKEDLIST_H
#define STARRY_CLIBRARY_LINKEDLIST_H

#include "Nodes/Nodes.h"

typedef Node LinkedList;
typedef NodeType Generic;

LinkedList EmptyList();

LinkedList LinkedList_Init(Generic value);

LinkedList LinkedList_Alloc();

void LinkedList_Push(LinkedList *list, Generic object);

void LinkedList_Append(LinkedList *list, Generic value);

void LinkedList_Remove(LinkedList *list, Generic value);

LinkedList LinkedList_GetNext(LinkedList list);

Generic LinkedList_GetInfo(LinkedList list);

void LinkedList_Dealloc(LinkedList head, void (*dealloc)(Generic));

#endif //STARRY_CLIBRARY_LINKEDLIST_H
