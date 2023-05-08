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

void Merge(int *arr, int low, int mid, int high) {
    int tempLength = high - low + 1;
    int temp[tempLength];
    // pointers to the left and right sub-arrays
    int left = low;
    int right = mid + 1;
    int tempCounter = 0;

    // basic merge
    while (left <= mid && right <= high) {
        if (arr[left] <= arr[right]) temp[tempCounter++] = arr[left++];
        else temp[tempCounter++] = arr[right++];
    }

    // copy the rest of the sub-array that still has elements
    if (right > high) while (left <= mid) temp[tempCounter++] = arr[left++];
    else while (right <= high) temp[tempCounter++] = arr[right++];

    // copy temp to arr
    for (int i = 0; i < tempLength; i++) arr[low + i] = temp[i];
}

void MergeSort_rec(int *arr, int low, int high) {
    // low < high when there are at least 2 elements
    if (low < high) {
        int mid = (low + high) / 2;
        MergeSort_rec(arr, low, mid);
        MergeSort_rec(arr, mid + 1, high);
        Merge(arr, low, mid, high);
    }
}

void MergeSort(int *array, int size) {
    MergeSort_rec(array, 0, size - 1);
}

void QuickSort_rec(int *arr, int low, int high) {
    if (low < high) {
        int left = low;
        int right = high;
        int pivot = arr[low];

        // partition
        while (left < right) {
            while (arr[right] > pivot) right--;
            while (left < right && arr[left] <= pivot) left++;
            if (left < right) Swap(arr + left, arr + right);
        }

        // fix pivot position
        if (low != right) {
            arr[low] = arr[right];
            arr[right] = pivot;
        }

        // recursive calls
        if (right - 1 > low) QuickSort_rec(arr, low, right - 1);
        if (right + 1 < high) QuickSort_rec(arr, right + 1, high);
    }
}

void QuickSort(int *array, int size) {
    QuickSort_rec(array, 0, size - 1);
}

double SortTimer(int arrSize, int loops, void (*func)(const int *, int, int)) {
    clock_t t = clock();
    for (int c = 0; c < loops; c++) func(RandomIntArray(arrSize, 1000), arrSize, 333);
    t = clock() - t;
    return (double) t / CLOCKS_PER_SEC;
}
