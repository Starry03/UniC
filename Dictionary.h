//
// Created by andre on 8/9/2023.
//

#ifndef STARRY_CLIBRARY_DICTIONARY_H
#define STARRY_CLIBRARY_DICTIONARY_H

#endif //STARRY_CLIBRARY_DICTIONARY_H

#define DEFAULT_SIZE 10
#define SIZE_INCREMENT 10
#define RESIZING_VALUE 10

#define DICT_ERROR 104

#include "LinkedList.h"
#include <stdlib.h>

typedef struct DictObject {
    void *key;
    void *value;
} DictObject_;

typedef DictObject_ *DictObject;

typedef struct Dictionary_ {
    size_t size;
    size_t items_stored;

    size_t (*hash)(void *, size_t);

    LinkedList **table;
} Dictionary_;

typedef Dictionary_ *Dictionary;

Dictionary Dictionary_Create(size_t size, size_t (*hash)(void *, size_t));

LinkedList **AllocList(size_t size);

size_t SetDimension(size_t size);

DictObject DictObject_Create(void *key, void *value);

void InitListsToNull(LinkedList **dest, size_t length);

void Dictionary_Add(Dictionary *dict, void *key, void *value);

void *Dictionary_Get(Dictionary dict, void *key, const char *key_type);

int Dictionary_GetInt(void *result);

float Dictionary_GetFloat(void *result);

char *Dictionary_GetString(void *result);

void Dictionary_DebugTable(Dictionary dict);
