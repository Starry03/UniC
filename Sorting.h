//
// Created by andre on 4/19/2023.
//

#ifndef STARRY_SORTING_H
#define STARRY_SORTING_H

#endif //STARRY_SORTING_H

void BubbleSort(int* array, int size);
void InsertionSort(int* array, int size);
void QuickSort(int* array, int size);
void MergeSort(int* array, int size);
void TimSort(int* array, int size);

double SortTimer(int arrSize, int loops, void (*func)(const int* , int, int));
