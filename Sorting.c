//
// Created by andre on 4/19/2023.
//

#include "Sorting.h"

#include <time.h>
#include "Utils.h"

void BubbleSort(int *array, int size) {
    int swapped;
    while (1) {
        swapped = 0;
        for (int i = 0; i < size - 1; i++) {
            if (array[i] > array[i + 1]) {
                Swap(&array[i], &(array[i + 1]));
                swapped = 1;
            }
        }
        if (!swapped) break;
    }
}

void InsertionSort(int *array, int size) {
    for (int i = 1; i < size; i++) {
        int currentIndex = i;
        while (currentIndex > 0 && array[currentIndex] < array[currentIndex - 1]) {
            Swap(array + currentIndex, array + currentIndex - 1);
            currentIndex--;
        }
    }
}

void QuickSort(int *array, int size) {

}

void MergeSort(int *array, int size) {

}

void TimSort(int *array, int size) {

}

double SortTimer(int arrSize, int loops, void (*func)(const int *, int, int)) {
    clock_t t = clock();
    for (int c = 0; c < loops; c++) func(RandomIntArray(arrSize, 1000), arrSize, 333);
    t = clock() - t;
    return (double) t / CLOCKS_PER_SEC;
}
