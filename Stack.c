//
// Created by andre on 5/7/2023.
//

#include "Stack.h"

void Push(Stack* stack, NodeType info) {
    Node* node = InitNode(info);
    node->next = *stack;
    *stack = node;
}

void Pop(Stack* stack) {
    Node* temp = *stack;
    *stack = (*stack)->next;
    free(temp);
}
