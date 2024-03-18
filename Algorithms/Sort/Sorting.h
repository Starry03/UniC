//
// Created by andre on 4/19/2023.
//

#ifndef STARRY_SORTING_H
#define STARRY_SORTING_H

#include <stddef.h>
#include "Utils/types.h"

void BubbleSort(int *array, size_t size);

void InsertionSort(int *array, size_t size);

void MergeSort(int *array, size_t size);

void MergeSort_rec(int *arr, size_t low, size_t high);

void Merge(int *arr, size_t low, size_t mid, size_t high);

void QuickSort_rec(int *arr, size_t low, size_t high);

void QuickSort(int *array, size_t size);

void CountingSort(const int array[], int dest[], int size, int k);

void RadixSort(int *array, size_t size);

void BucketSort(Generic *array, int size);

#endif //STARRY_SORTING_H
