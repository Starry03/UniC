//
// Created by andre on 10/11/2023.
//

#include <stdlib.h>

#include "Dictionary.h"
#include "DataStructures/LinkedList/LinkedList.h"
#include "Utils/StringUtils/StringUtils.h"
#include "Utils/Hashing/HashFunctions.h"

enum {
    DEFAULT_SIZE = 10,
    INCREMENT_SIZE = 10,
};

Dictionary Dictionary_Create(size_t size) {
    Dictionary dictionary = (Dictionary) malloc(sizeof(Dictionary_));
    if (!dictionary)
        exit(EXIT_FAILURE);
    dictionary->items_stored = 0;
    dictionary->size = (size) ? size : DEFAULT_SIZE;
    dictionary->table = default_table(size);
    return (dictionary);
}

static LinkedList *default_table(size_t size) {
    LinkedList *table = (LinkedList *) malloc(size * sizeof(LinkedList));
    if (!table)
        exit(EXIT_FAILURE);
    for (size_t i = 0; i < size; i++)
        table[i] = NULL;
    return (table);
}

static DictObject DictObj_Create(void *key, void *value, KeyType key_type) {
    DictObject dictObj = (DictObject) malloc(sizeof(DictObject_));
    if (!dictObj)
        exit(EXIT_FAILURE);
    dictObj->key = key;
    dictObj->value = value;
    dictObj->key_type = key_type;
    return (dictObj);
}

static size_t hash_key(void *key, KeyType key_type, size_t size) {
    switch (key_type) {
        case INT:
            return (hash_int(key, size));
        case LONG:
            return (hash_long(key, size));
        case FLOAT:
            return (hash_float(key, size));
        case DOUBLE:
            return (hash_double(key, size));
        case CHAR:
            return (hash_char(key, size));
        case STRING:
            return (hash_string(key, size));
        default:
            exit(EXIT_FAILURE);
    }
}

void Dictionary_Add(Dictionary dict, void *key, void *value, KeyType key_type) {
    if (Dictionary_IsFull(dict)) {}

    const size_t index = hash_key(key, key_type, dict->size);
    DictObject dictObject = DictObj_Create(key, value, key_type);
    LinkedList_Append(dict->table + index, dictObject);
    dict->items_stored++;
}

void Dictionary_AddGeneric(Dictionary dict, void *key, void *value, size_t (*hash_fun)(void *)) {
    if (Dictionary_IsFull(dict)) {}

    const size_t index = hash_fun(key);
    DictObject dictObject = DictObj_Create(key, value, GENERIC);
    LinkedList_Append(dict->table + index, dictObject);
    dict->items_stored++;
}

void *Dictionary_Get(Dictionary dict, void *key, KeyType key_type) {
    if (!dict)
        exit(EXIT_FAILURE);

    const size_t index = hash_key(key, key_type, dict->size);
    LinkedList bucket = dict->table[index];
    DictObject buff;
    void *res = NULL;
    while (bucket && !res) {
        buff = LinkedList_GetInfo(bucket);
        switch (key_type) {
            case INT:
                if (int_equals(buff->key, key))
                    res = buff->value;
                break;
            case LONG:
                if (long_equals(buff->key, key))
                    res = buff->value;
                break;
            case FLOAT:
                if (float_equals(buff->key, key))
                    res = buff->value;
                break;
            case DOUBLE:
                if (double_equals(buff->key, key))
                    res = buff->value;
                break;
            case CHAR:
                if (char_equals(buff->key, key))
                    res = buff->value;
                break;
            case STRING:
                if (str_eq(buff->key, key))
                    res = buff->value;
                break;
        }
        bucket = LinkedList_GetNext(bucket);
    }
    free(key);
    if (!res)
        exit(EXIT_FAILURE);  // nothing found
    return (res);
}

static bool int_equals(int *x, int *y) {
    return (*x == *y);
}

static bool long_equals(long *x, long *y) {
    return (*x == *y);
}

static bool float_equals(float *x, float *y) {
    return (*x == *y);
}

static bool double_equals(double *x, double *y) {
    return (*x == *y);
}

static bool char_equals(char *x, char *y) {
    return (*x == *y);
}

static void DictObj_Dealloc(void *dictObject) {
    DictObject d = (DictObject) dictObject;
    free(d->key);
    free(d->value);
    free(d);
}

void Dictionary_Dealloc(Dictionary dict) {
    for (size_t i = 0; i < dict->size; i++)
        LinkedList_Dealloc(dict->table[i], &DictObj_Dealloc);
    free(dict->table);
    free(dict);
}

bool Dictionary_IsFull(Dictionary dict) {
    return (dict->size - dict->items_stored == 1);
}