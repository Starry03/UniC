//
// Created by andre on 4/19/2023.
//

#include "Utils.h"

int *SortedIntArray(int size) {
    int *arr = (int *) malloc(size * sizeof(int));
    for (int i = 0; i < size; i++) arr[i] = i;
    return arr;
}

int *RandomIntArray(int size, int range) {
    srand(time(NULL));
    int *arr = (int *) malloc(size * sizeof(int));
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
