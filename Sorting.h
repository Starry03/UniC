//
// Created by andre on 4/19/2023.
//

#ifndef STARRY_SORTING_H
#define STARRY_SORTING_H

#endif //STARRY_SORTING_H

void BubbleSort(int *array, int size);             // O(n^2)
void InsertionSort(int *array, int size);          // O(n^2)
void MergeSort(int *array, int size);              // O(n log n)
void MergeSort_rec(int *arr, int low, int high);   // O(log n)
void Merge(int *arr, int low, int mid, int high);  // O(n)
void QuickSort_rec(int *arr, int low, int high);   // O(log n)
void QuickSort(int *array, int size);              // O(n log n)
void TimSort(int *array, int size);
