#include "Heap.h"
#include <stdlib.h>

t_heap	Heap_init(size_t capacity, Comparator cmp, Deallocator dealloc,
		bool is_min_heap)
{
	t_heap	heap;

	heap = malloc(sizeof(t_heap_));
	if (!heap)
		return (NULL);
	heap->entries = malloc(sizeof(t_heap_entry) * capacity);
	if (!heap->entries)
	{
		free(heap);
		return (NULL);
	}
	heap->length = 0;
	heap->capacity = capacity;
	heap->cmp = cmp;
	heap->dealloc = dealloc;
	heap->is_min_heap = is_min_heap;
	return (heap);
}
void	Heap_Free(t_heap heap)
{
	size_t			i;
	t_heap_entry	*entries;
	Deallocator		dealloc;

	if (!heap)
		return ;
	i = 0;
	entries = heap->entries;
	dealloc = heap->dealloc;
	while (i < heap->length)
	{
		dealloc(entries[i]);
		i++;
	}
	free(heap->entries);
	free(heap);
}

static void	swap_entries(t_heap_entry a, t_heap_entry b)
{
	Generic	key;
	Generic	value;

	key = a->key;
	value = a->value;
	a->key = b->key;
	a->value = b->value;
	b->key = key;
	b->value = value;
}

void	Heap_Heapify(t_heap heap, size_t index)
{
	t_heap_entry	left;
	t_heap_entry	right;
	t_heap_entry	temp[3];
	t_heap_entry	swap;

	left = HeapEntry_GetLeftChild(heap, index);
	right = HeapEntry_GetRightChild(heap, index);
	temp[0] = heap->entries[index];
	temp[1] = left;
	temp[2] = right;
	qsort(temp, 3, sizeof(t_heap_entry), heap->cmp);
	if (heap->is_min_heap)
		swap = temp[0];
	else
		swap = temp[2];
	if (swap == heap->entries[index])
		return ;
	swap_entries(heap->entries[index], swap);
	if (swap == left)
		Heap_Heapify(heap, ENTRY_LEFT(index));
	else
		Heap_Heapify(heap, ENTRY_RIGHT(index));
}

void	Heap_Build(t_heap heap)
{
	size_t	i;

	i = heap->length / 2;
	while (i > 0)
	{
		Heap_Heapify(heap, i);
		i--;
	}
}
Generic	Heap_GetMin(t_heap heap)
{
	if (!heap || !heap->is_min_heap)
		return (NULL);
	return (heap->entries[0]->value);
}
Generic	Heap_GetMax(t_heap heap)
{
	if (!heap || heap->is_min_heap)
		return (NULL);
	return (heap->entries[0]->value);
}
Generic	Heap_PollMin(t_heap heap)
{
	t_heap_entry	min;

	if (!heap || !heap->is_min_heap)
		return (NULL);
	min = heap->entries[0];
	heap->entries[0] = heap->entries[heap->length - 1];
	heap->dealloc(min);
	heap->length--;
	Heap_Heapify(heap, 0);
	return (min->value);
}
Generic	Heap_PollMax(t_heap heap)
{
	t_heap_entry	max;

	if (!heap || heap->is_min_heap)
		return (NULL);
	max = heap->entries[0];
	heap->entries[0] = heap->entries[heap->length - 1];
	heap->dealloc(max);
	heap->length--;
	Heap_Heapify(heap, 0);
	return (max->value);
}

static void	Heap_Increase(t_heap heap, size_t index, Generic key, Generic value)
{
	t_heap_entry	entry;
	t_heap_entry	parent;
	Comparator		cmp;
	t_heap_entry	*entries;

	cmp = heap->cmp;
	entries = heap->entries;
	if (cmp(key, HeapEntry_GetParent(heap, index)->key) < 0)
		return ;
	entries[index] = HeapEntry_init(key, value);
	while (index && cmp(entries[ENTRY_PARENT(index)]->key, key) < 0)
	{
		swap_entries(entries[index], entries[ENTRY_PARENT(index)]);
		index = ENTRY_PARENT(index);
	}
}

static void	Heap_Decrease(t_heap heap, size_t index, Generic key, Generic value)
{
	t_heap_entry	entry;
	t_heap_entry	parent;
	Comparator		cmp;
	t_heap_entry	*entries;

	cmp = heap->cmp;
	entries = heap->entries;
	if (cmp(key, HeapEntry_GetParent(heap, index)->key) > 0)
		return ;
	entries[index] = HeapEntry_init(key, value);
	while (index && cmp(entries[ENTRY_PARENT(index)]->key, key) > 0)
	{
		swap_entries(entries[index], entries[ENTRY_PARENT(index)]);
		index = ENTRY_PARENT(index);
	}
}

void	Heap_Insert(t_heap heap, Generic key, Generic value)
{
	if (!heap || !key)
		return ;
	if (heap->length == heap->capacity)
		return ;
	heap->length++;
	if (heap->is_min_heap)
		Heap_Decrease(heap, heap->length - 1, key, value);
	else
		Heap_Increase(heap, heap->length - 1, key, value);
}
