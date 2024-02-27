//
// Created by andre on 10/11/2023.
//

#include "Dictionary.h"

#include <stdlib.h>
#include "../../Utils/Hashing/HashFunctions.h"

#include <stdio.h>

static inline Dict EmptyDict() { return (Dict)NULL; }

static inline Dict Dict_alloc() { return (Dict)malloc(sizeof(t_dictionary)); }

void Dict_obj_dealloc(Generic dict_obj) {
	Dict_obj obj = (Dict_obj)dict_obj;
	obj->dealloc_key(obj->key);
	obj->dealloc_value(obj->value);
	free(dict_obj);
}

static LinkedList *Dict_alloc_buckets(size_t size) {
	LinkedList *buckets = (LinkedList*) malloc(sizeof(LinkedList) * size);
	size_t i = 0;
	if (!buckets)
		return NULL;
	while (i < size)
		buckets[i++] = NULL;
	return buckets;
}

Dict Dict_init(size_t size) {	
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

void Dict_Add(Dict dict, Generic key, Generic value, void(*dealloc_key)(Generic), void(*dealloc_value)(Generic)) {
	size_t hash = hash_addr(key, dict->size);
	LinkedList *buckets = dict->buckets;
	Dict_obj obj = (Dict_obj)malloc(sizeof(t_dict_obj));
	if (!obj)
		return;
	obj->key = key;
	obj->value = value;
	obj->dealloc_key = dealloc_key;
	obj->dealloc_value = dealloc_value;
	LinkedList_Push(buckets + hash, obj);
}

void *Dict_Get(Dict dict, Generic key) {
	size_t hash = hash_addr(key, dict->size);
	LinkedList bucket = (dict->buckets)[hash];
	while (((Dict_obj)LinkedList_GetInfo(bucket))->key != key)
		bucket = LinkedList_GetNext(bucket);
	return ((Dict_obj)LinkedList_GetInfo(bucket))->value;
}

void Dict_Remove(Dict dict, Generic key) {
	size_t hash = hash_addr(key, dict->size);
	LinkedList bucket = (dict->buckets)[hash];
	while (((Dict_obj)LinkedList_GetInfo(bucket))->key != key)
		bucket = LinkedList_GetNext(bucket);
	LinkedList_Remove(dict->buckets + hash, &Dict_obj_dealloc);
}

void Dict_free(Dict dict)
{
	size_t i = 0;
	LinkedList bucket;
	while (i < dict->size)
	{
		bucket = ((dict->buckets)[i]);
		LinkedList_Dealloc(bucket, &Dict_obj_dealloc);
		i++;
	}
	free(dict->buckets);
	free(dict);
}

