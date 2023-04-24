//
// Created by andre on 4/15/2023.
//

// Generic List

#include "LinkedList.h"

P_Node InitNode(NodeType info, size_t size) {
    P_Node newNode = (P_Node) malloc(NODE_SIZE);
    newNode->info = malloc(size);
    CopyData(newNode->info, size, info);
    newNode->next = NULL;
    return newNode;
}

int NodeIsEmpty(P_Node node) {
    return node == NULL;
}

int ListLength(P_Node list) {
    P_Node start = list;
    int count = 0;
    while (!NodeIsEmpty(start)) {
        count++;
        start = start->next;
    }
    return count;
}

void ListPush(P_Node *list, NodeType info, size_t size) {
    P_Node newNode = InitNode(info, size);
    newNode->next = *list;
    *list = newNode;
}

void ListAppend(P_Node *list, NodeType value, size_t size) {
    P_Node currentNode = *list;
    if (NodeIsEmpty(currentNode)) {
        currentNode = InitNode(value, size);
        *list = currentNode;
        return;
    }
    while (!NodeIsEmpty((currentNode->next))) currentNode = currentNode->next;
    currentNode->next = InitNode(value, size);
}

void ListConcat(P_Node newList, P_Node startingNode) {
    while (!NodeIsEmpty(newList)) {
        startingNode->next = newList;
        startingNode = startingNode->next;
        newList = newList->next;
    }
}

void RemoveNode(P_Node *node) {
    P_Node temp = *node;
    *node = (*node)->next;
    free(temp);
}

void ListRemove(P_Node list, NodeType value) {
    while (!NodeIsEmpty(list)) {
        if (list->info == value) RemoveNode(&list);
        list = list->next;
    }
}

NodeType ListGet(P_Node list, int pos) {
    NodeType value;
    P_Node start = list;
    for (int i = 0; i < pos; i++) {
        start = start->next;
    }
    value = InitNode(start->info, sizeof(start->info));
    return value;
}

P_Node LastNode(P_Node *list) {
    P_Node currentNode = *list;
    if (NodeIsEmpty(currentNode)) return NULL;
    while (!NodeIsEmpty(currentNode->next))
        currentNode = currentNode->next;
    return currentNode;
}

void ListRemoveLast(P_Node list) {

}

void ListRemoveFirst(P_Node list) {
    RemoveNode(&list);
}

void DeleteList(P_Node list) {
    while (!NodeIsEmpty(list)) {
        RemoveNode(&list);
        list = list->next;
    }
}

void ListReplace(P_Node list, NodeType old, NodeType newValue) {
    while (!NodeIsEmpty(list)) {
        list->info = (list->info == old) ? newValue : list->info;
        return;
    }
}

void ListReplaceAll(P_Node list, NodeType target, NodeType newValue) {
    while (!NodeIsEmpty(list)) {
        list->info = (list->info == target) ? newValue : list->info;
        list = list->next;
    }
}

void ListReverse(P_Node *list) {
    P_Node prev = NULL;
    P_Node nextNode;
    while (!NodeIsEmpty(*list)) {
        nextNode = *list;
        *list = (*list)->next;
        nextNode->next = prev;
        prev = nextNode;
    }
    *list = prev;
}

P_Node ListCreate(int length, NodeType init, size_t size) {
    P_Node start = NULL;
    for (int i = 0; i < length; i++) {
        ListPush(&start, init, size);
    }
    free(init);
    return start;
}

P_Node ListCreateFromArray(const NodeType *array, const int length, size_t size) {
    if (length == 0) return NULL;
    P_Node list = InitNode(array[0], size);
    P_Node start = list;
    for (int i = 1; i < length; i++) {
        P_Node nextNode = InitNode(array[i], size);
        list->next = nextNode;
        list = nextNode;
    }
    return start;
}

void NodePrint(int pos) {
    printf("Node[%d] { Generic } -> ", pos);
}

void ListPrint(P_Node list) {
    P_Node currentNode = list;
    int count = 0;

    printf("\nList:\n");
    while (!NodeIsEmpty(currentNode)) { ;
        NodePrint(count);
        currentNode = currentNode->next;
        count++;
    }
    printf("\n");
}
