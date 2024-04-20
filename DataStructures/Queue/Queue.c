//
// Created by andre on 5/5/2023.
//

#include "Queue.h"
#include <stdlib.h>

#define QUEUE_EMPTY (Queue)0

Queue	Queue_Init(Generic info)
{
	Queue queue;

	queue = (Queue)malloc(sizeof(Node));
	if (!queue)
		return (QUEUE_EMPTY);
	queue->info = info;
	queue->next = NULL;
	return (queue);
}

void	Queue_Add(Queue queue, Generic info)
{
	Queue node;

	if (queue == NULL)
		return ;
	while (queue->next != NULL)
	{
		queue = queue->next;
	}
	node = Queue_Init(info);
	if (!node)
		return ;
	queue->next = node;
}

Generic	Queue_Get(Queue *queue)
{
	Queue node;

	if (!queue || !*queue)
		return (GENERIC_NULL);
	node = *queue;
	*queue = node->next;
	return (node->info);
}

void	Queue_Remove(Queue *queue, void (*dealloc)(Generic))
{
	Queue node;

	if (!queue || !*queue)
		return ;
	node = *queue;
	*queue = node->next;
	if (dealloc)
		dealloc(node->info);
	free(node);
}

void	Queue_Dealloc(Queue *queue, void (*dealloc)(Generic))
{
	if (!queue || !*queue)
		return ;
	while (*queue)
		Queue_Remove(queue, dealloc);
}
