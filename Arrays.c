//
// Created by andre on 5/15/2023.
//

#include "Arrays.h"
#include <stdio.h>
#include <time.h>

void *AllocateArray(size_t len, size_t varSize)
{
    return calloc(len, varSize);
}

int *SortedIntArray(size_t len)
{
    int *arr = (int *)AllocateArray(len, sizeof(int));
    for (int i = 0; i < len; i++)
        arr[i] = i;
    return arr;
}

int *RandomIntArray(size_t len, int range)
{
    srand(time(NULL));
    int *arr = (int *)AllocateArray(len, sizeof(int));
    for (int i = 0; i < len; i++)
        arr[i] = rand() % range;
    return arr;
}

int *IntArray_Zeros(size_t len)
{
    return (int *)calloc(len, sizeof(int));
}

void PrintArray(int *arr, int size)
{
    for (int i = 0; i < size; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
}