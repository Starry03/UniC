//
// Created by andre on 5/5/2023.
//

#ifndef STARRY_STRUCTURES_H
#define STARRY_STRUCTURES_H

#endif //STARRY_STRUCTURES_H

#include <stdlib.h>
#include <stdbool.h>

typedef void *NodeType;

typedef struct Node {
    NodeType info;
    struct Node *next;
} Node;

#define NODE_SIZE 16

typedef struct SizedNode {
    NodeType info;
    struct SizedNode *next;
    size_t size;
} SizedNode;

#define SIZED_NODE_SIZE 24

bool NodeIsEmpty(void *node);

Node *InitNode(NodeType info);

SizedNode *InitSizedNode(NodeType info, size_t size);
