//
// Created by andre on 4/21/2023.
//

#include "SetList.h"

SetList SetInitFromArray(SetType *array, size_t size, int length) {
    SetList list = InitNode(array[0], size);
    SetList start = list;
    for (int i = 1; i < length; i++) {
        if (!SetContains(start, array[i], size)) {
            SetList nextNode = InitNode(array[i], size);
            list->next = nextNode;
            list = nextNode;
        }
    }
    return start;
}

bool SetContains(SetList set, SetType value, size_t size) {
    while (!NodeIsEmpty(set)) {
        if (BytesEqual(value, set, size)) return true;
        set = set->next;
    }
    return false;
}

void SetAdd(SetList* set, SetType value, size_t size) {
    if (!SetContains(*set, value, size)) ListPush(set, value, size);
}

void SetRemove(SetList set, SetType value) {
    while (!NodeIsEmpty(set)) {
        if (set->info == value) {
            ListRemove(set, value);
            return;
        }
        set = set->next;
    }
}

void SetPrint(SetList set) {
    ListPrint(set);
}
