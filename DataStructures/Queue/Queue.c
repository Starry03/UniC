//
// Created by andre on 5/5/2023.
//

#include "Queue.h"
#include <stdlib.h>

#define QUEUE_EMPTY (Queue)0

inline Queue	Queue_Init(Generic info)
{
	return (Queue)LinkedList_Init(info);
}

inline void	Queue_Add(Queue *queue, Generic info)
{
	LinkedList_Append(queue, info);
}

Queue	Queue_poll(Queue *queue)
{
	Queue	out;

	if (!queue || !*queue)
		return (GENERIC_NULL);
	out = *queue;
	*queue = (*queue)->next;
	return (out);
}

void	Queue_DeallocElement(Queue queue, Deallocator dealloc)
{
	if (!queue)
		return ;
	if (dealloc)
		dealloc(queue->info);
	free(queue);
}

inline void	Queue_Dealloc(Queue *queue, Deallocator dealloc)
{
	LinkedList_Dealloc(*queue, dealloc);
}
