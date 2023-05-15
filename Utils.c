//
// Created by andre on 4/19/2023.
//

#include "Utils.h"

void Swap(int *n, int *n2) {
    int temp = *n2;
    *n2 = *n;
    *n = temp;
}

void CopyData(void *dest, size_t size, void *src) {
    for (int i = 0; i < size; i++) {
        *((char *) (dest + i)) = *((char *) (src + i));
    }
}

bool BytesEqual(void *var, void *other, size_t size, size_t size_other) {
    if (size != size_other) return false;
    for (int i = 0; i < size; i++)
        if (*((char *) (var + i)) != *((char *) (other + i)))
            return false;
    return true;
}
