//
// Created by andre on 8/9/2023.
//

#include "HashFunctions.h"
#include <stdio.h>

size_t normalize(size_t val, size_t size) {
    return val % size;
}

size_t hashInt(void *key, size_t size) {
    return normalize(*(size_t *) key, size);
}

size_t hashFloat(void *key, size_t size) {
    return hashInt(key, size);
}

size_t hashString(void *key, size_t size) {
    size_t val = 0;
    int i = 0;
    char *k = (char *) key;
    while (k[i] != '\0') {
        val += (int) k[i];
        i++;
    }
    return normalize(val, size);
}

size_t hashAddress(void *key, size_t size) {
    size_t a = *(size_t *) key;
    a = (a ^ 61) ^ (a >> 16);
    a = a + (a << 3);
    a = a ^ (a >> 4);
    a = a * 0x27d4eb2d;
    a = a ^ (a >> 15);
    return normalize(a, size);
}
