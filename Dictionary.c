//
// Created by andre on 8/9/2023.
//

#include "Dictionary.h"
#include "HashFunctions.h"

#include <stdlib.h>
#include <string.h>
#include <stdio.h>

Dictionary Dictionary_Create(size_t size, size_t (*hash)(void *, size_t)) {
    Dictionary dict = malloc(sizeof(Dictionary_));
    dict->size = SetDimension(size);
    dict->items_stored = 0;
    dict->hash = hash;
    dict->table = AllocList(size);
    InitListsToNull(dict->table, size);
    return dict;
}

LinkedList **AllocList(size_t size) {
    return (LinkedList **) malloc(sizeof(LinkedList *) * size);
}

size_t SetDimension(size_t size) {
    return (!size) ? DEFAULT_SIZE : size;
}

void InitListsToNull(LinkedList **dest, size_t length) {
    for (int i = 0; i < length; i++)
        dest[i] = NULL;
}

DictObject DictObject_Create(void *key, void *value) {
    DictObject dictObject = (DictObject) malloc(sizeof(DictObject_));
    dictObject->key = key;
    dictObject->value = value;
    return dictObject;
}

void Dictionary_Add(Dictionary *dict, void *key, void *value) {
    size_t index = (*dict)->hash(key, (*dict)->size);
    LinkedList *list = (*dict)->table[index];
    if (list == NULL) {
        (*dict)->table[index] = (LinkedList *) malloc(sizeof(LinkedList));
        DictObject dictObject = DictObject_Create(key, value);
        *(*dict)->table[index] = LinkedList_Init((void *) dictObject);
    } else {
        list = &((*list)->next);
        LinkedList_Push(list, (void *) DictObject_Create(key, value));
    }
    (*dict)->items_stored++;
}

void *Dictionary_Get(Dictionary dict, void *key, const char *key_type) {
    const size_t index = dict->hash(key, dict->size);
    LinkedList *listChose = dict->table[index];
    while (*listChose != NULL) {
        void *dict_key = ((DictObject) ((*listChose)->info))->key;
        void *dict_value = ((DictObject) ((*listChose)->info))->value;

        if (strcmp(key_type, "int") == 0) {
            if (*(int *) dict_key == *(int *) key)
                return dict_value;
        } else if (strcmp(key_type, "float") == 0) {
            if (*(float *) dict_key == *(float *) key)
                return dict_value;
        } else if (strcmp(key_type, "str") == 0) {
            if (strcmp((char *) dict_key, (char *) key) == 0)
                return dict_value;
        } else {
            printf("Error: key_type not recognized\n");
            exit(DICT_ERROR);
        }

        listChose = &((*listChose)->next);
    }
    return NULL;
}

int Dictionary_GetInt(void *result) {
    return *(int *) result;
}

float Dictionary_GetFloat(void *result) {
    return *(float *) result;
}

char *Dictionary_GetString(void *result) {
    return (char *) result;
}

void Dictionary_DebugTable(Dictionary dict) {
    LinkedList **table = dict->table;
    for (int i = 0; i < dict->size; i++) {
        LinkedList *addr = table[i];
        printf("addr%d: %p\n", i, addr);
    }
}
