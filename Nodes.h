//
// Created by andre on 8/8/2023.
//

#ifndef STARRY_CLIBRARY_NODES_H
#define STARRY_CLIBRARY_NODES_H

#endif //STARRY_CLIBRARY_NODES_H

typedef double NodeType;

typedef struct Node {
    NodeType info;
    struct Node *next;
} Node_;

typedef Node_ * Node;

#define NODE_SIZE 16

Node EmptyNode();

Node Node_Allocate();

Node Node_Init(NodeType info);
