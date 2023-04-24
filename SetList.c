/*
//
// Created by andre on 4/21/2023.
//

#include "SetList.h"

SetList SetInitFromArray(const SetType *array, int size) {
    SetList list = InitNode(array[0]);
    SetList start = list;
    for (int i = 1; i < size; i++) {
        if (!SetContains(start, array[i])) {
            SetList nextNode = InitNode(array[i]);
            list->next = nextNode;
            list = nextNode;
        }
    }
    return start;
}

int SetContains(SetList set, SetType value) {
    while (!NodeIsEmpty(&set)) {
        if (set->info == value) return 1;
        set = set->next;
    }
    return 0;
}

void SetAdd(SetList* set, SetType value) {
    if (!SetContains(*set, value)) ListAppend(set, value);
}

void SetRemove(SetList set, SetType value) {
    while (!NodeIsEmpty(&set)) {
        if (set->info == value) {
            ListRemove(set, value);
        }
    }
}

void SetPrint(SetList set) {
    ListPrint(set);
}
*/
