//
// Created by andre on 5/5/2023.
//

#ifndef STARRY_STRUCTURES_H
#define STARRY_STRUCTURES_H

#endif //STARRY_STRUCTURES_H

#include <stdlib.h>
#include <stdbool.h>
#include "DataHolder.h"

typedef void *NodeType;

typedef struct Node_{
    DataHolder data;
    struct Node_ *next;
} Node_;

typedef Node_ *Node;

#define NODE_SIZE 16

bool NodeIsEmpty(Node node);

Node InitNode(NodeType info, int datatype);
