//
// Created by andre on 5/5/2023.
//

#include "Queue.h"

#include <stdlib.h>

Queue EmptyQueue() {
    return (Queue)NULL;
}

Queue Queue_Init(Generic info) {
    Queue queue = (Queue) malloc(sizeof(Node));
	if (!queue)
		return EmptyQueue();
    queue->info = info;
    queue->next = NULL;
    return queue;
}

void Queue_Add(Queue queue, Generic info) {
	Queue node;
    if (queue == NULL)
		return;
    while (queue->next != NULL) {
        queue = queue->next;
    }
	node = Queue_Init(info);
	if (!node)
		return;
    queue->next = node;
}

Generic Queue_Get(Queue *queue) {
	Queue node;
	if (!queue || !*queue)
		return (Generic)NULL;
	node = *queue;
    *queue = node->next;
	return node->info;
}
