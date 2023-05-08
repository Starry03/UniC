//
// Created by andre on 4/19/2023.
//

#include "Utils.h"

#include <stdio.h>
#include <time.h>

int *AllocateArray(int len, size_t size) {
    return malloc(len * size);
}

int *SortedIntArray(int size) {
    int *arr = AllocateArray(size, sizeof(int));
    for (int i = 0; i < size; i++) arr[i] = i;
    return arr;
}

int *RandomIntArray(int size, int range) {
    srand(time(NULL));
    int *arr = AllocateArray(size, sizeof(int));
    for (int i = 0; i < size; i++) arr[i] = rand() % range;
    return arr;
}

void PrintArray(int *arr, int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

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
