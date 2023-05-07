//
// Created by andre on 4/21/2023.
//

#include "SetList.h"

#include "Utils.h"

bool SetContains(SetList set, SetType value, size_t size) {
    while (!NodeIsEmpty(set)) {
        if (BytesEqual(value, set->info, size, set->size))
            return true;
        set = set->next;
    }
    return false;
}

void SetAdd(SetList *set, SetType value, size_t size) {
    if (!SetContains(*set, value, size)) {
        SizedNode *node = InitSizedNode(value, size);
        node->next = *set;
        *set = node;
    }
}

#include <stdio.h>
void SetRemove(SetList* set, SetType value, size_t size) {
    while (!NodeIsEmpty(*set)) {
        if (BytesEqual(value, (*set)->info, size, (*set)->size)) {
            SetList temp = *set;
            *set = (*set)->next;
            free(temp);
            break;
        }
        set = &((*set)->next);
    }
}

int SetLength(SetList set) {
    int count = 0;
    while (!NodeIsEmpty(set)) { count++; set = set->next;}
    return count;
}
