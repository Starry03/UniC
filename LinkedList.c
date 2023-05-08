//
// Created by andre on 4/15/2023.
//

// Generic List

#include "LinkedList.h"

#include <stdio.h>
#include "Utils.h"

LinkedList NewNode(NodeType info) {
    return (LinkedList) InitNode(info);
}

int ListLength(LinkedList list) {
    LinkedList start = list;
    int count = 0;
    while (!NodeIsEmpty(start)) {
        count++;
        start = start->next;
    }
    return count;
}

void ListPush(LinkedList *list, NodeType info) {
    LinkedList newNode = NewNode(info);
    newNode->next = *list;
    *list = newNode;
}

void ListAppend(LinkedList *list, NodeType value) {
    if (NodeIsEmpty(*list)) {
        *list = NewNode(value);
        return;
    }
    LinkedList current = *list;
    while (!NodeIsEmpty(current->next)) current = current->next;
    current->next = NewNode(value);
}

void ListConcat(LinkedList newList, LinkedList startingNode) {
    while (!NodeIsEmpty(newList)) {
        startingNode->next = newList;
        startingNode = startingNode->next;
        newList = newList->next;
    }
}

void RemoveNode(LinkedList *node) {
    LinkedList temp = *node;
    *node = (*node)->next;
    free(temp);
}

void ListRemove(LinkedList list, NodeType value) {
    while (!NodeIsEmpty(list)) {
        if (list->info == value) RemoveNode(&list);
        list = list->next;
    }
}

NodeType ListGet(LinkedList list, int pos) {
    for (int i = 0; i < pos; i++)
        list = list->next;
    return list->info;
}

LinkedList LastNode(LinkedList *list) {
    LinkedList currentNode = *list;
    if (NodeIsEmpty(currentNode)) return NULL;
    while (!NodeIsEmpty(currentNode->next))
        currentNode = currentNode->next;
    return currentNode;
}

void ListRemoveLast(LinkedList *list) {
    LinkedList lastNode = LastNode(list);
    RemoveNode(&lastNode);
}

void ListRemoveFirst(LinkedList list) {
    RemoveNode(&list);
}

void DeleteList(LinkedList list) {
    while (!NodeIsEmpty(list)) {
        RemoveNode(&list);
        list = list->next;
    }
}

void ListReplace(LinkedList list, NodeType old, NodeType newValue) {
    while (!NodeIsEmpty(list)) {
        list->info = (list->info == old) ? newValue : list->info;
        return;
    }
}

void ListReplaceAll(LinkedList list, NodeType target, NodeType newValue) {
    while (!NodeIsEmpty(list)) {
        list->info = (list->info == target) ? newValue : list->info;
        list = list->next;
    }
}

void ListInsert(LinkedList *list, NodeType value, int pos) {
    while (pos-- > 0) { list = &((*list)->next); }

    LinkedList temp = *list;
    LinkedList newNode = NewNode(value);
    *list = newNode;
    newNode->next = temp;
}

void ListReverse(LinkedList *list) {
    LinkedList prev = NULL;
    LinkedList nextNode;
    while (!NodeIsEmpty(*list)) {
        nextNode = *list;
        *list = (*list)->next;
        nextNode->next = prev;
        prev = nextNode;
    }
    *list = prev;
}

LinkedList ListCreate(int length, NodeType init) {
    // To do
    return NULL;
}

LinkedList ListCreateFromArray(const NodeType *array, const int length) {
    if (length == 0) return NULL;
    LinkedList list = NewNode(array[0]);
    LinkedList start = list;
    for (int i = 1; i < length; i++) {
        LinkedList nextNode = NewNode(array[i]);
        list->next = nextNode;
        list = nextNode;
    }
    return start;
}

void NodePrint(int i) {
    printf("Node[%d] { Generic } -> ", i);
}

void ListPrint(LinkedList list) {
    int count = 0;

    printf("\nList:\n");
    while (!NodeIsEmpty(list)) {
        NodePrint(count);
        list = list->next;
        count++;
    }

    printf("End\n");
}
