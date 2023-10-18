//
// Created by andre on 8/9/2023.
//

#ifndef DICTIONARY_H
#define DICTIONARY_H

// forward declarations

#include <stdbool.h>
#include <corecrt.h>
#include "Nodes/Nodes.h"
#include "AllocationUtils/AllocationUtils.h"

enum KeyType {
    INT,
    LONG,
    FLOAT,
    DOUBLE,
    CHAR,
    STRING,
    GENERIC,
};

typedef enum KeyType KeyType;

typedef char *String;
typedef Node LinkedList;

// end

typedef struct DictObject {
    void *key;
    void *value;
    KeyType key_type;
} DictObject_;

typedef DictObject_ *DictObject;

typedef struct Dictionary_ {
    size_t size;
    size_t items_stored;
    LinkedList *table;
} Dictionary_;

typedef Dictionary_ *Dictionary;

Dictionary Dictionary_Create(size_t size);

static LinkedList *default_table(size_t size);

static DictObject DictObj_Create(void *key, void *value, KeyType key_type);

static void Dictionary_Rehash(Dictionary dict);

static bool Dictionary_IsFull(Dictionary dict);

static size_t hash_key(void *key, KeyType key_type, size_t size);

void Dictionary_Add(Dictionary dict, void *key, void *value, KeyType key_type);

void Dictionary_AddGeneric(Dictionary dict, void *key, void *value, size_t (*hash_fun)(void *));

void *Dictionary_Get(Dictionary dict, void *key, KeyType key_type);

void *Dictionary_GetGeneric(Dictionary dict, void *key, size_t (*hash_fun)(void *));

static bool int_equals(int *x, int *y);

static bool long_equals(long *x, long *y);

static bool float_equals(float *x, float *y);

static bool double_equals(double *x, double *y);

static bool char_equals(char *x, char *y);

static void *allocate_generic(void *value, size_t key_type);

static void DictObj_Dealloc(void *dictObject);

void Dictionary_Dealloc(Dictionary dict);

#endif
