//
// Created by andre on 8/9/2023.
//

#include "HashFunctions.h"
#include <stdint.h>

#define PRIME 31

size_t normalize(size_t val, size_t size) {
    return val % size;
}

size_t hash_int(void *key, size_t size) {
    return normalize(*(int *) key, size);
}

size_t hash_long(void *key, size_t size) {
    return hash_int(key, size);
}

size_t hash_float(void *key, size_t size) {
    return hash_int(key, size);
}

size_t hash_double(void *key, size_t size) {
    return hash_int(key, size);
}

size_t hash_char(void *key, size_t size) {
    return normalize(*(size_t *) key, size);
}

size_t hash_string(void *key, size_t size) {
    size_t val = 0;
    size_t i = 0;
    char *k = (char *) key;
    while (k[i])
        val += (int) k[i++];
    return normalize(val, size);
}

size_t hash_addr(Generic addr, size_t size) {
	uint64_t out = (uint64_t) addr;
	return normalize(out, size);
}
