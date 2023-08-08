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
