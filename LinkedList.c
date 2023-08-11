//
// Created by andre on 8/8/2023.
//

#include "LinkedList.h"

#include <stdlib.h>

LinkedList EmptyList() {
    return (LinkedList) NULL;
}

LinkedList LinkedList_Init(LinkedListType value) {
    LinkedList list = LinkedList_Alloc();
    list->info = value;
    list->next = EmptyList();
    return list;
}

LinkedList LinkedList_Alloc() {
    return (LinkedList) malloc(sizeof(Node_));
}

void LinkedList_Push(LinkedList *list, LinkedListType object) {
    LinkedList newNode = Node_Init(object);
    newNode->next = *list;
    *list = newNode;
}

void LinkedList_Append(LinkedList *list, LinkedListType value) {
    if (*list == EmptyList()) {
        *list = LinkedList_Init(value);
        return;
    }
    
    LinkedList newNode = Node_Init(value);
    while (*list != EmptyList())
        list = &(*list)->next;
    *list = newNode;
}

void LinkedList_Remove(LinkedList *list, LinkedListType value) {
    while (*list != EmptyList()) {
        if (LinkedList_GetInfo(*list) == value) {
            LinkedList target = LinkedList_GetNext(*list);
            free(*list);
            *list = target;
            return;
        }
        list = &(*list)->next;
    }
}

LinkedList LinkedList_GetNext(LinkedList list) {
    return list->next;
}

LinkedListType LinkedList_GetInfo(LinkedList list) {
    return list->info;
}

void LinkedList_Dealloc(LinkedList head) {
    while (head != NULL) {
        LinkedList temp = head;
        head = LinkedList_GetNext(head);
        free(temp->info);
        free(temp);
    }
}
