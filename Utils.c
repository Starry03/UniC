//
// Created by andre on 4/19/2023.
//

#include "Utils.h"

void int_swap(int *n, int *n2) {
    int temp = *n2;
    *n2 = *n;
    *n = temp;
}

void bytes_copy(void *dest, size_t size, void *src) {
    if (dest == NULL || src == NULL) return;

    for (int i = 0; i < size; i++)
        *((char *) (dest + i)) = *((char *) (src + i));
}
