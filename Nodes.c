//
// Created by andre on 5/6/2023.
//
#include "Nodes.h"

bool NodeIsEmpty(void *node) {
    return node == NULL;
}

Node *InitNode(NodeType info) {
    Node *newNode = (Node *) malloc(NODE_SIZE);
    newNode->info = info;
    newNode->next = NULL;
    return newNode;
}

SizedNode * InitSizedNode(NodeType info, size_t size) {
    SizedNode *newNode = (SizedNode *) malloc(SIZED_NODE_SIZE);
    newNode->info = info;
    newNode->next = NULL;
    newNode->size = size;
    return newNode;
}
