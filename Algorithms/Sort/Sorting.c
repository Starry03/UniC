//
// Created by andre on 4/19/2023.
//

#include "Sorting.h"

#include "../../Utils/GenericUtils/GenericUtils.h"

// O(n^2)
void BubbleSort(int *array, size_t size) {
    int swapped;
    while (1) {
        swapped = 0;
        for (int i = 0; i < size - 1; i++) {
            if (array[i] > array[i + 1]) {
                int_swap(&array[i], &(array[i + 1]));
                swapped = 1;
            }
        }
        if (!swapped) break;
    }
}

// O(n^2)
void InsertionSort(int *array, size_t size) {
    for (int i = 1; i < size; i++) {
        int currentIndex = i;
        while (currentIndex > 0 && array[currentIndex] < array[currentIndex - 1]) {
            int_swap(array + currentIndex, array + currentIndex - 1);
            currentIndex--;
        }
    }
}

// O(n log n)
void Merge(int *arr, size_t low, size_t mid, size_t high) {
    size_t tempLength = high - low + 1;
    size_t temp[tempLength];
    // pointers to the left and right sub-arrays
    size_t left = low;
    size_t right = mid + 1;
    size_t tempCounter = 0;

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

// O(n log n)
void MergeSort_rec(int *arr, size_t low, size_t high) {
    // low < high when there are at least 2 elements
    if (low < high) {
        size_t mid = (low + high) / 2;
        MergeSort_rec(arr, low, mid);
        MergeSort_rec(arr, mid + 1, high);
        Merge(arr, low, mid, high);
    }
}

// O(n log n)
void MergeSort(int *array, size_t size) {
    MergeSort_rec(array, 0, size - 1);
}

// O(n log n)
void QuickSort_rec(int *arr, size_t low, size_t high) {
    if (low < high) {
        size_t left = low;
        size_t right = high;
        int pivot = arr[low];

        // partition
        while (left < right) {
            while (arr[right] > pivot) right--;
            while (left < right && arr[left] <= pivot) left++;
            if (left < right) int_swap(arr + left, arr + right);
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

// O(n log n)
void QuickSort(int *array, size_t size) {
    QuickSort_rec(array, 0, size - 1);
}
