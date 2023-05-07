//
// Created by andre on 5/5/2023.
//

#ifndef STARRY_QUEUE_H
#define STARRY_QUEUE_H

#endif //STARRY_QUEUE_H

#include "Nodes.h"

typedef Node* Queue;

Queue EmptyQueue();
void AddToQueue(Queue queue, NodeType info);
void RemoveFromQueue(Queue* queue);
NodeType FirstInQueue(Queue queue);
