//
// Created by andre on 4/18/2023.
//

#include "Search.h"

// O(n)
size_t LinearSearch(const Generic *arr, size_t length, Generic target) {
    size_t count = 0;
    while (count < length) {
        if (arr[count] == target)
            return count;
        count++;
    }
    return -1;
}

// Arr has to be sorted
// O(log n)
size_t BinarySearch(const Generic *arr, size_t length, Generic target) {
    size_t left = 0;
    size_t right = length - 1;
    size_t mid;
    while (left <= right) {
        mid = left + (right - left) / 2;
        if (arr[mid] == target) return mid;
        if (target > arr[mid]) left = mid + 1;
        else right = mid - 1;
    }
    return -1;
}
