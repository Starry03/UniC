//
// Created by andre on 5/5/2023.
//

#ifndef STARRY_QUEUE_H
#define STARRY_QUEUE_H

#include "Nodes.h"

typedef Node Queue;
typedef NodeType QueueType;

Queue EmptyQueue();

Queue Queue_Init(QueueType info);

void Queue_Add(Queue queue, QueueType info);

NodeType Queue_GetFirst(Queue queue);

#endif //STARRY_QUEUE_H
