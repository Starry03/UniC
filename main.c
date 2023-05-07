#include <stdio.h>

#include "LinkedList.h"

int arr[] = {1, 2, 3, 4};

int main() {
    LinkedList linkedList = NULL;
    for (int i = 0; i < 4; i++)
        ListAppend(&linkedList, arr + i);
    ListReverse2(&linkedList);
    while (linkedList != NULL) {
        printf("%d\n", *(int *) (linkedList->info));
        linkedList = linkedList->next;
    }

    return 0;
}
