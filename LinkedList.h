//
// Created by andre on 4/13/2023.
//

#ifndef STARRY_LINKEDLIST_H
#define STARRY_LINKEDLIST_H

#endif //STARRY_LINKEDLIST_H

#include <stdio.h>
#include <stdlib.h>

#include "Utils.h"

typedef void *NodeType;

typedef struct Node {
    NodeType info;
    struct Node *next;
} Node;

#define NODE_SIZE 16

typedef Node *P_Node;

P_Node InitNode(NodeType info, size_t size);

int NodeIsEmpty(P_Node node);

int ListLength(P_Node list);

void ListPush(P_Node *list, NodeType info, size_t size);

void ListAppend(P_Node *list, NodeType value, size_t size);

void ListConcat(P_Node newList, P_Node startingNode);

void RemoveNode(P_Node *node);

NodeType ListGet(P_Node list, int pos);

P_Node LastNode(P_Node *list);

// Removes all nodes of info 'value'
void ListRemove(P_Node list, NodeType value);

void ListRemoveLast(P_Node list);

void ListRemoveFirst(P_Node list);

// Frees every node
void DeleteList(P_Node list);

void ListReplace(P_Node list, NodeType old, NodeType newValue);

void ListReplaceAll(P_Node list, NodeType target, NodeType newValue);

void ListReverse(P_Node *list);

// Use this function to create every list, other functions don't call free
P_Node ListCreate(int length, NodeType init, size_t size);

P_Node ListCreateFromArray(const NodeType *array, const int length, size_t size);

void NodePrint(int pos);

void ListPrint(P_Node list);
