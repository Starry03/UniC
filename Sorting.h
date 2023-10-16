//
// Created by andre on 4/19/2023.
//

#ifndef STARRY_SORTING_H
#define STARRY_SORTING_H

#include <stddef.h>

void BubbleSort(int *array, size_t size);

void InsertionSort(int *array, size_t size);

void MergeSort(int *array, size_t size);

void MergeSort_rec(int *arr, size_t low, size_t high);

void Merge(int *arr, size_t low, size_t mid, size_t high);

void QuickSort_rec(int *arr, size_t low, size_t high);

void QuickSort(int *array, size_t size);

void TimSort(int *array, size_t size);

#endif //STARRY_SORTING_H
