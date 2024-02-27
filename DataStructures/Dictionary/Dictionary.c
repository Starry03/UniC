//
// Created by andre on 10/11/2023.
//

#include "Dictionary.h"

#include <stdlib.h>
#include "../../Utils/Hashing/HashFunctions.h"

static inline Dict EmptyDict() { return (Dict)NULL; }

static inline Dict Dict_alloc() { return (Dict)malloc(sizeof(Dictionary)); }

static LinkedList *Dict_alloc_buckets(size_t size)
{
	LinkedList *buckets = (LinkedList*) malloc(sizeof(LinkedList) * size);
	size_t i = 0;
	if (!buckets)
		return NULL;
	while (i < size)
		buckets[i++] = NULL;
	return buckets;
}

Dict Dict_init(size_t size)
{	
	LinkedList *buckets;
	Dict dict = Dict_alloc();
	
	if (!dict)
		return EmptyDict();
	if (!size)
		dict->size = DEFAULT_SIZE;
	else
		dict->size = size;
	buckets = Dict_alloc_buckets(dict->size);
	if (!buckets)
	{
		free(dict);
		return EmptyDict();
	}
	dict->buckets = buckets;
	return (dict);
}

void Dict_Add(Dict dict, Generic value)
{
	size_t hash = hash_addr(value, dict->size);
	LinkedList *buckets = dict->buckets;

	if (buckets[hash] == EmptyList())
		buckets[hash] =	LinkedList_Init(value);
	LinkedList_Push(buckets + hash, value);			
}

