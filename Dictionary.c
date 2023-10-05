//
// Created by andre on 8/9/2023.
//

#include "Dictionary.h"
#include "HashFunctions.h"

#include <stdlib.h>
#include <string.h>
#include <stdio.h>

Dictionary Dictionary_Create(size_t size) {
    Dictionary dict = malloc(sizeof(Dictionary_));
    dict->size = GetDimension(size);
    dict->items_stored = 0;
    dict->table = AllocList(size);
    InitListsToNull(dict->table, size);
    return dict;
}

LinkedList **AllocList(size_t size) {
    return (LinkedList **) malloc(sizeof(LinkedList *) * size);
}

size_t GetDimension(size_t size) {
    return (!size) ? DEFAULT_SIZE : size;
}

void InitListsToNull(LinkedList **dest, size_t length) {
    for (int i = 0; i < length; i++)
        dest[i] = NULL;
}

DictObject DictObject_Create(void *key, char *keyType, void *value) {
    DictObject dictObject = (DictObject) malloc(sizeof(DictObject_));
    dictObject->key = key;
    dictObject->value = value;
    return dictObject;
}

size_t Dictionary_GetIndex(void *key, const char *key_type, size_t dict_size) {
    if (strcmp(key_type, "int") == 0) {
        return hashInt(key, dict_size);
    } else if (strcmp(key_type, "float") == 0) {
        return hashFloat(key, dict_size);
    } else if (strcmp(key_type, "str") == 0) {
        return hashString(key, dict_size);
    } else if (strcmp(key_type, "struct") == 0) {
        size_t a = hashAddress(key, dict_size);
        printf("hash: %zu\n", a);
        return a;
    } else {
        printf("Error: key_type not recognized\n");
        exit(DICT_ERROR);
    }
}

void Dictionary_Add(Dictionary *dict, void *key, void *value, char *key_type) {
    size_t dict_size = (*dict)->size;
    size_t index = Dictionary_GetIndex(key, key_type, dict_size);
    LinkedList *list = (*dict)->table[index];
    if (list == NULL) {
        (*dict)->table[index] = (LinkedList *) malloc(sizeof(LinkedList));
        DictObject dictObject = DictObject_Create(key, key_type, value);
        *(*dict)->table[index] = LinkedList_Init((void *) dictObject);
    } else {
        list = &((*list)->next);
        LinkedList_Push(list, (void *) DictObject_Create(key, key_type, value));
    }
    (*dict)->items_stored++;
}

bool CompareInt(void *a, void *b) {
    return *(int *) a == *(int *) b;
}

bool CompareFloat(void *a, void *b) {
    return *(float *) a == *(float *) b;
}

bool CompareString(void *a, void *b) {
    return !strcmp((char *) a, (char *) b);
}

bool CompareAddresses(void *a, void *b) {
    return *(size_t *) a == *(size_t *) b;
}

void *Dictionary_Get(Dictionary dict, void *key, const char *key_type) {
    size_t index = Dictionary_GetIndex(key, key_type, dict->size);
    LinkedList *listChosen = dict->table[index];
    bool (*compare)(void *, void *);

    if (strcmp(key_type, "int") == 0) {
        compare = CompareInt;
    } else if (strcmp(key_type, "float") == 0) {
        compare = CompareFloat;
    } else if (strcmp(key_type, "str") == 0) {
        compare = CompareString;
    } else if (strcmp(key_type, "struct") == 0) {
        compare = CompareAddresses;
    } else {
        printf("Error: key_type not recognized\n");
        exit(DICT_ERROR);
    }

    while (*listChosen != NULL) {
        void *dict_key = DictObject_GetKey((DictObject) (LinkedList_GetInfo(*listChosen)));
        void *dict_value = DictObject_GetValue((DictObject) (LinkedList_GetInfo(*listChosen)));

        if (compare(key, dict_key))
            return dict_value;

        listChosen = &((*listChosen)->next);
    }

    printf("Error: key not in dictionary\n");
    exit(DICT_ERROR);
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

void *DictObject_GetKey(DictObject dictObject) {
    return dictObject->key;
}

void *DictObject_GetValue(DictObject dictObject) {
    return dictObject->value;
}

void Dictionary_DebugTable(Dictionary dict) {
    LinkedList **table = dict->table;
    for (int i = 0; i < dict->size; i++) {
        LinkedList *addr = table[i];
        printf("addr%d: %p\n", i, addr);
    }
}

void Dictionary_Dealloc(Dictionary dict) {
    LinkedList **table = dict->table;
    for (int i = 0; i < dict->size; i++) {
        LinkedList *list = table[i];
        if (list == NULL) {
            free(list);
            continue;
        }
        LinkedList currentList = *list;
        LinkedList_Dealloc(currentList);
        free(list);
    }
    free(table);
    free(dict);
}
