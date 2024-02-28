//
// Created by andre on 8/9/2023.
//

#ifndef DICTIONARY_H
#define DICTIONARY_H

#include <stdbool.h>
#include <stddef.h>
#include "../../DataStructures/LinkedList/LinkedList.h"

#define DEFAULT_SIZE 20

typedef struct s_dictionary {
	LinkedList *buckets;
	size_t size;
} t_dictionary;

typedef t_dictionary *Dict;

typedef struct s_dict_obj {
	Generic key;
	Generic value;
	void(*dealloc_key)(Generic);
	void(*dealloc_value)(Generic);
} t_dict_obj;

typedef t_dict_obj *Dict_obj;

Dict Dict_Init(size_t size);
void Dict_Add(Dict dict, Generic key, Generic value, void(*dealloc_key)(Generic), void(*dealloc_value)(Generic));
void *Dict_Get(Dict dict, Generic key);
void Dict_Remove(Dict dict, Generic key);
void Dict_Free(Dict dict);

#endif
