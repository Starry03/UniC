//
// Created by andre on 5/5/2023.
//

#include "Queue.h"

Queue EmptyQueue() {
    return NULL;
}

void AddToQueue(Queue queue, NodeType info) {
    while (queue->next != NULL)
        queue = queue->next;
    Node *newNode = InitNode(info);
    queue->next = newNode;
}

void RemoveFromQueue(Queue* queue) {
    Queue temp = *queue;
    *queue = (*queue)->next;
    free(temp);
}

NodeType FirstInQueue(Queue queue) {
    return queue->info;
}
