#pragma once

# include "unic/types.h"
# include <stdbool.h>
# include <stddef.h>

void	bubblesort(t_generic *array, size_t size, t_comparator cmp);

void	insertionsort(t_generic *array, size_t size, t_comparator cmp);

void	mergesort(t_generic *array, size_t size, t_comparator cmp);

void	mergesort_rec(t_generic *arr, size_t low, size_t high,
			t_comparator cmp);

void	merge(t_generic *arr, size_t low, size_t mid, size_t high,
			t_comparator cmp);

void	quicksort_rec(int *arr, size_t low, size_t high);

void	quicksort(int *array, size_t size);

void	countingsort(const int array[], int dest[], int size, int k);

void	radixsort(int *array, size_t size);

void	bucketsort(t_generic *array, int size);

void	heapsort(int *arr, size_t size);
