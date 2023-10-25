//
// Created by andre on 5/15/2023.
//

#ifndef STARRY_ARRAYS_H
#define STARRY_ARRAYS_H

#include <stddef.h>

int *SortedIntArray(size_t size);

int *RandomIntArray(size_t size, size_t range);

double *RandomDoubleArray(size_t len, size_t range, double offset);

int *IntArray_Zeros(size_t len);

#endif //STARRY_ARRAYS_H