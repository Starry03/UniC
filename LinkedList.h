//
// Created by andre on 4/13/2023.
//

#ifndef STARRY_LINKEDLIST_H
#define STARRY_LINKEDLIST_H

#endif //STARRY_LINKEDLIST_H

#include "Nodes.h"

#include <stdbool.h>

typedef Node *LinkedList;

LinkedList NewNode(NodeType info);

int ListLength(LinkedList list);

void ListPush(LinkedList *list, NodeType info);

void ListAppend(LinkedList* list, NodeType value);

void ListConcat(LinkedList newList, LinkedList startingNode);

void RemoveNode(LinkedList *node);

NodeType ListGet(LinkedList list, int pos);

LinkedList LastNode(LinkedList *list);

// Removes all nodes of info 'value'
void ListRemove(LinkedList list, NodeType value);

void ListRemoveLast(LinkedList *list);

void ListRemoveFirst(LinkedList list);

// Frees every node
void DeleteList(LinkedList list);

void ListReplace(LinkedList list, NodeType old, NodeType newValue);

void ListReplaceAll(LinkedList list, NodeType target, NodeType newValue);

void ListInsert(LinkedList *list, NodeType value, int pos);

void ListReverse(LinkedList *list);

LinkedList ListCreate(int length, NodeType init);

LinkedList ListCreateFromArray(const NodeType *array, const int length);

void NodePrint(int i);

void ListPrint(LinkedList list);
