//
// Created by andre on 10/11/2023.
//

#include "../../Utils/Hashing/HashFunctions.h"
#include "Dictionary.h"
#include <stdio.h>
#include <stdlib.h>

#define DEFAULT_SIZE 20
#define REALLOC_COEFF 2

static inline t_dict	EmptyDict(void)
{
	return ((t_dict)NULL);
}

static inline t_dict	Dict_alloc(void)
{
	return (t_dict)malloc(sizeof(t_dictionary));
}

static Dict_obj	Dict_Obj_Init(Generic key, Generic value,
		void (*dealloc_key)(Generic), void (*dealloc_value)(Generic))
{
	Dict_obj	obj;

	obj = (Dict_obj)malloc(sizeof(t_dict_obj));
	if (!obj)
		return (NULL);
	obj->key = key;
	obj->value = value;
	obj->dealloc_key = dealloc_key;
	obj->dealloc_value = dealloc_value;
	return (obj);
}

static void	Dict_Obj_Dealloc(Generic dict_obj)
{
	Dict_obj	obj;

	obj = (Dict_obj)dict_obj;
	if (obj->dealloc_key)
		obj->dealloc_key(obj->key);
	if (obj->dealloc_value)
		obj->dealloc_value(obj->value);
	free(dict_obj);
}

static LinkedList	*Dict_Alloc_Buckets(size_t size)
{
	LinkedList	*buckets;
	size_t		i;

	buckets = (LinkedList *)malloc(sizeof(LinkedList) * size);
	if (!buckets)
		return (NULL);
	i = 0;
	while (i < size)
		buckets[i++] = NULL;
	return (buckets);
}

/**
 * @brief Creates Dictionary instance
 *
 * @param size if null, will be DEFAULT_SIZE
 * @param cmp function to compare keys
 * @param hash_key function to hash keys
 * @return Dict
 */
t_dict	Dict_Init(size_t size, Comparator cmp, Hasher hash_key)
{
	LinkedList	*buckets;
	t_dict		dict;

	dict = Dict_alloc();
	if (!dict)
		return (EmptyDict());
	if (!size)
		dict->size = DEFAULT_SIZE;
	else
		dict->size = size;
	buckets = Dict_Alloc_Buckets(dict->size);
	if (!buckets)
	{
		free(dict);
		return (EmptyDict());
	}
	dict->buckets = buckets;
	dict->cmp = cmp;
	dict->hash_key = hash_key;
	dict->used = 0;
	return (dict);
}

/**
 * @brief Reallocates dict creating a new one with double the size
 * @warning causes double free, will be fixed in the future
 * @param old_dict
 * @return Dict
 */
t_dict	Dict_Realloc(t_dict old_dict)
{
	t_dict		new_dict;
	size_t		i;
	LinkedList	current_bucket;
	Dict_obj	obj;

	new_dict = Dict_Init(old_dict->size * REALLOC_COEFF, old_dict->cmp,
			old_dict->hash_key);
	i = 0;
	while (i < old_dict->size)
	{
		current_bucket = old_dict->buckets[i];
		while (current_bucket)
		{
			obj = current_bucket->info;
			Dict_Add(&new_dict, obj->key, obj->value, obj->dealloc_key,
				obj->dealloc_value);
			current_bucket = LinkedList_GetNext(current_bucket);
		}
		i++;
	}
	Dict_Free(old_dict);
	return (new_dict);
}

/**
 * @brief Add value to dict\r
 * @attention Key and value <= 8 bytes, use pointers for larger values
 *
 * @param dict
 * @param key value or address
 * @param value value or address
 * @param dealloc_key null if is a value
 * @param dealloc_value null if is a value
 * @param cmp function to compare keys
 * @return true if added, false if key already exists
 */
bool	Dict_Add(t_dict *dict, Generic key, Generic value,
		Deallocator dealloc_key, Deallocator dealloc_value)
{
	size_t		hash;
	LinkedList	*buckets;
	t_dict		d;
	Dict_obj	obj;

	if (!dict || Dict_Get(*dict, key))
		return (false);
	d = *dict;
	if (d->used + 1 > d->size)
		*dict = Dict_Realloc(*dict);
	hash = hash_generic(d->hash_key(key, d->size), d->size);
	buckets = d->buckets;
	obj = Dict_Obj_Init(key, value, dealloc_key, dealloc_value);
	if (!obj)
		return (false);
	LinkedList_Push(buckets + hash, obj);
	d->used++;
	return (true);
}

/**
 * @brief Get value from dict
 *
 * @param dict
 * @param key
 * @param hash_key
 * @param cmp
 * @return void*
 */
void	*Dict_Get(t_dict dict, Generic key)
{
	const size_t	hash = hash_generic(dict->hash_key(key, dict->size),
				dict->size);
	LinkedList		bucket;
	Dict_obj		obj;

	if (!dict || !dict->used)
		return (NULL);
	bucket = (dict->buckets)[hash];
	while (LinkedList_GetInfo(bucket)
		&& dict->cmp(((Dict_obj)LinkedList_GetInfo(bucket))->key, key))
		bucket = LinkedList_GetNext(bucket);
	obj = (Dict_obj)LinkedList_GetInfo(bucket);
	if (!obj)
		return (NULL);
	return (obj->value);
}

/**
 * @brief Remove key and value from dict
 *
 * @param dict
 * @param key
 */
void	Dict_Remove(t_dict dict, Generic key)
{
	const size_t	hash = hash_generic((size_t)key, dict->size);
	LinkedList		bucket;

	bucket = (dict->buckets)[hash];
	while (((Dict_obj)LinkedList_GetInfo(bucket))->key != key)
		bucket = LinkedList_GetNext(bucket);
	LinkedList_Remove(dict->buckets + hash, &Dict_Obj_Dealloc);
}

/**
 * @brief Frees all memory used by dict
 *
 * @param dict
 */
void	Dict_Free(t_dict dict)
{
	size_t		i;
	LinkedList	bucket;

	i = 0;
	while (i < dict->size)
	{
		bucket = ((dict->buckets)[i]);
		LinkedList_Dealloc(bucket, &Dict_Obj_Dealloc);
		i++;
	}
	free(dict->buckets);
	free(dict);
}

/**
 * @brief Log the status of the dict
 *
 * @param dict
 */
void	Dict_Status(t_dict dict)
{
	LinkedList	bucket;
	size_t		count;

	printf("Number of buckets used: %zu\n", dict->size);
	for (size_t i = 0; i < dict->size; i++)
	{
		bucket = dict->buckets[i];
		count = 0;
		while (bucket != NULL)
		{
			count++;
			bucket = LinkedList_GetNext(bucket);
		}
		printf("Bucket %zu: %zu elements\n", i, count);
	}
}
