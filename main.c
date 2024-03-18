#include <stdio.h>
#include <string.h>
#include "Algorithms/Sort/Sorting.h"
#include "Utils/Logging/Logging.h"

int main() {
	/*
	 * test counting sort
	 */

	int arr[] = {2, 5, 3, 0, 2, 3, 0, 3};
	int size = sizeof(arr) / sizeof(arr[0]);
	int dest[size];
	memset(dest, 0, sizeof(dest));
	CountingSort(arr, dest, size, 5);
	printf("Sorted array\n");
	Log_intarray(dest, size, 0);

}
