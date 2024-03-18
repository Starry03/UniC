//
// Created by andre on 4/19/2023.
//

#include "Sorting.h"
#include <math.h>
#include <stdbool.h>
#include <string.h>
#include "Utils/Logging/Logging.h"
#include "DataStructures/LinkedList/LinkedList.h"

static void int_swap(int *a, int *b) {
	int temp = *a;
	*a = *b;
	*b = temp;
}

// O(n^2)
void BubbleSort(int *array, size_t size) {
	bool swapped;
	while (true) {
		swapped = false;
		for (size_t i = 0; i < size - 1; i++) {
			if (array[i] > array[i + 1]) {
				int_swap(array + i, array + i + 1);
				swapped = true;
			}
		}
		if (!swapped)
			break;
	}
}

// O(n^2)
void InsertionSort(int *array, size_t size) {
	for (size_t i = 1; i < size; i++) {
		size_t currentIndex = i;
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
		if (arr[left] <= arr[right])
			temp[tempCounter++] = arr[left++];
		else
			temp[tempCounter++] = arr[right++];
	}

	// copy the rest of the sub-array that still has elements
	if (right > high)
		while (left <= mid)
			temp[tempCounter++] = arr[left++];
	else
		while (right <= high)
			temp[tempCounter++] = arr[right++];

	// copy temp to arr
	for (size_t i = 0; i < tempLength; i++)
		arr[low + i] = temp[i];
}

// O(n log n)
void MergeSort_rec(int *arr, size_t low, size_t high) {
	// low < high when there are at least 2 elements
	if (low >= high)
		return;
	size_t mid = (low + high) / 2;
	MergeSort_rec(arr, low, mid);
	MergeSort_rec(arr, mid + 1, high);
	Merge(arr, low, mid, high);
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
			while (arr[right] > pivot)
				right--;
			while (left < right && arr[left] <= pivot)
				left++;
			if (left < right)
				int_swap(arr + left, arr + right);
		}

		// fix pivot position
		if (low != right) {
			arr[low] = arr[right];
			arr[right] = pivot;
		}

		// recursive calls
		if (right - 1 > low)
			QuickSort_rec(arr, low, right - 1);
		if (right + 1 < high)
			QuickSort_rec(arr, right + 1, high);
	}
}

// O(n log n)
void QuickSort(int *array, size_t size) {
	QuickSort_rec(array, 0, size - 1);
}

/*
 * O(n + k)
 */
void CountingSort(const int array[], int dest[], int size, int k) {
	int i, j;
	int c[k + 1];

	// number of elements lower than the current element
	int n_lower;

	memset(c, 0, (k + 1) * sizeof(int));
	for (j = 0; j < size; j++)
		c[array[j]] += 1;
	for (i = 1; i < k + 1; i++)
		c[i] = c[i] + c[i - 1];
	for (j = size - 1; j >= 0; j--) {
		n_lower = c[array[j]] - 1;
		dest[n_lower] = array[j];
		c[array[j]] -= 1;
		Log_intarray(dest, size, n_lower);
	}
}

/**
 * O(n)
 *
 * @brief range[0, 1) => 10 buckets of linked lists
 * @param array
 * @param size
 * @warning not runnable
 */
void BucketSort(Generic *array, int size) {
	int index;
	LinkedList buckets[size];
	for (int i = 0; i < size; i++)
		buckets[i] = EmptyList();
	for (int i = 1; i <= size; i++) {
		index = floor(size * (*(int *) array[i]));
		LinkedList_Append(buckets + index, array[i]);
	}
	for (int i = 0; i < size; i++) {
		// InsertionSort(bucket[i], &LinkedList_Cmp)
		// concat lists
	}
}
