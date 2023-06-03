//
// Created by andre on 5/6/2023.
//
#include "Nodes.h"

bool NodeIsEmpty(Node node) {
    return node == NULL;
}

Node InitNode(NodeType info, int datatype) {
    Node node = (Node) malloc(NODE_SIZE);
    node->data = NewDataHolder(info, datatype);
    node->next = NULL;
    return node;
}
