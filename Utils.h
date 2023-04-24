//
// Created by andre on 4/19/2023.
//

#ifndef STARRY_UTILS_H
#define STARRY_UTILS_H

#endif //STARRY_UTILS_H

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>

// arrays

int *SortedIntArray(int size);

int *RandomIntArray(int size, int range);

void PrintArray(int* arr, int size);

void Swap(int* n, int* n2);

void CopyData(void* dest, size_t size, void* src);
