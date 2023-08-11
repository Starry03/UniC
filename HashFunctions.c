//
// Created by andre on 8/9/2023.
//

#include "HashFunctions.h"

size_t hashInt(void *key, size_t size) {
    return *(int *) key % size;
}

size_t hashFloat(void *key, size_t size) {
    return hashInt(key, size);
}

size_t hashString(void *key, size_t size) {
    int out = 0;
    int i = 0;
    char *k = (char *) key;
    while (k[i] != '\0') {
        out += (int) k[i];
        i++;
    }
    return out % size;
}
