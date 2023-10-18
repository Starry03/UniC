//
// Created by andre on 8/8/2023.
//

#include "LinkedList.h"

#include <stdlib.h>

LinkedList EmptyList() {
    return (LinkedList) NULL;
}

LinkedList LinkedList_Init(Generic value) {
    LinkedList list = LinkedList_Alloc();
    list->info = value;
    list->next = EmptyList();
    return list;
}

LinkedList LinkedList_Alloc() {
    return (LinkedList) malloc(sizeof(Node_));
}

void LinkedList_Push(LinkedList *list, Generic object) {
    LinkedList newNode = Node_Init(object);
    newNode->next = *list;
    *list = newNode;
}

void LinkedList_Append(LinkedList *list, Generic value) {
    if (*list == EmptyList()) {
        *list = LinkedList_Init(value);
        return;
    }

    LinkedList newNode = Node_Init(value);
    while (*list != EmptyList())
        list = &(*list)->next;
    *list = newNode;
}

void LinkedList_Remove(LinkedList *list, Generic value) {
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

Generic LinkedList_GetInfo(LinkedList list) {
    return list->info;
}

void LinkedList_Dealloc(LinkedList head, void(*dealloc_fun)(void *)) {
    while (head != NULL) {
        LinkedList temp = head;
        head = LinkedList_GetNext(head);
        if (dealloc_fun != NULL)
            dealloc_fun(temp->info);
        else free(temp->info);
        free(temp);
    }
}
