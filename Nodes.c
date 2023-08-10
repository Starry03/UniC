//
// Created by andre on 8/8/2023.
//

#include "Nodes.h"

#include <stdlib.h>

Node EmptyNode() {
    return (Node) NULL;
}

Node Node_Allocate() {
    return (Node) malloc(sizeof(Node_));
}

Node Node_Init(void *info) {
    Node node = Node_Allocate();
    node->info = info;
    node->next = EmptyNode();
    return node;
}
