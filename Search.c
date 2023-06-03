//
// Created by andre on 4/18/2023.
//

#include <time.h>
#include "Utils.h"
#include "Arrays.h"

int LinearSearch(const int *arr, int length, int target) {
    int count = 0;
    while (count < length) {
        if (arr[count] == target) return count;
        count++;
    }
    return -1;
}

// Arr has to be sorted from - to +
int BinarySearch(const int arr[], int length, int target) {
    int left = 0;
    int right = length - 1;
    int mid;
    while (left <= right) {
        mid = left + (right - left) / 2;
        if (arr[mid] == target) return mid;
        if (target > arr[mid]) left = mid + 1;
        else right = mid - 1;
    }
    return -1;
}

double SearchTimer(int arrSize, int loops, int (*func)(const int *, int, int)) {
    clock_t t = clock();
    for (int c = 0; c < loops; c++) func(SortedIntArray(arrSize), arrSize, 333);
    t = clock() - t;
    return (double) t / CLOCKS_PER_SEC;
}
