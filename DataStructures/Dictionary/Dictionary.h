//
// Created by andre on 8/9/2023.
//

#ifndef DICTIONARY_H
#define DICTIONARY_H

#include <stdbool.h>
#include <stddef.h>
#include "../../DataStructures/LinkedList/LinkedList.h"

typedef struct s_dictionary {
	LinkedList *buckets;
	size_t size;
} t_dictionary;

typedef t_dictionary *Dict;

Dict Dict_init(size_t size);
void Dict_Add(Dict dict, Generic value);
void Dict_Remove(Dict dict, Generic value);
Dict Dict_free();

#endif
