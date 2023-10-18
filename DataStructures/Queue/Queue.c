//
// Created by andre on 5/5/2023.
//

#include "Queue.h"

#include <stdlib.h>

Queue EmptyQueue() {
    return NULL;
}

Queue Queue_Init(QueueType info) {
    Queue queue = (Queue) malloc(sizeof(Node));
    queue->info = info;
    queue->next = NULL;
    return queue;
}

void Queue_Add(Queue queue, QueueType info) {
    if (queue == NULL) { return; }
    while (queue->next != NULL) {
        queue = queue->next;
    }
    queue->next = Queue_Init(info);
}

QueueType Queue_GetFirst(Queue queue) {
    return queue->info;
}
