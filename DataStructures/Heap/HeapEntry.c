#include "Heap.h"
#include <stdlib.h>

t_heap_entry	HeapEntry_init(Generic key, Generic value)
{
	t_heap_entry	entry;

	entry = malloc(sizeof(t_heap_entry_));
	if (!entry)
		return (NULL);
	entry->key = key;
	entry->value = value;
	entry->index = 0;
	return (entry);
}
t_heap_entry	HeapEntry_GetLeftChild(t_heap heap, size_t i)
{
	size_t	left_child_index;

	left_child_index = ENTRY_LEFT(i);
	if (left_child_index >= heap->length)
		return (NULL);
	return (heap->entries[left_child_index]);
}
t_heap_entry	HeapEntry_GetRightChild(t_heap heap, size_t i)
{
	size_t	right_child_index;

	right_child_index = ENTRY_RIGHT(i);
	if (right_child_index >= heap->length)
		return (NULL);
	return (heap->entries[right_child_index]);
}
t_heap_entry	HeapEntry_GetParent(t_heap heap, size_t i)
{
	if (!i)
		return (NULL);
	return (heap->entries[ENTRY_PARENT(i)]);
}
