//
// Created by andre on 5/15/2023.
//

#include "Arrays.h"
#include <stdlib.h>
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

int *RandomIntArray(size_t len, size_t range)
{
    srand(time(NULL));
    int *arr = (int *)AllocateArray(len, sizeof(int));
    for (int i = 0; i < len; i++)
        arr[i] = rand() % range;
    return arr;
}

double* RandomDoubleArray(size_t len, size_t range, double offset)
{
    srand(time(NULL));
    double *arr = (double *)AllocateArray(len, sizeof(double));
    for (int i = 0; i < len; i++)
        arr[i] = (rand() % range) - offset;
    return arr;
}

int *IntArray_Zeros(size_t len)
{
    return (int *)calloc(len, sizeof(int));
}
