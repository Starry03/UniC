//
// Created by andre on 8/8/2023.
//

#ifndef STARRY_CLIBRARY_NODES_H
#define STARRY_CLIBRARY_NODES_H

typedef void *NodeType;

typedef struct Node_ {
    NodeType info;
    struct Node_ *next;
} Node_;

typedef Node_ *Node;

static Node EmptyNode();

static Node Node_Allocate();

Node Node_Init(NodeType info);

#endif //STARRY_CLIBRARY_NODES_H
