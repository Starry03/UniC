//
// Created by andre on 4/21/2023.
//

#ifndef STARRY_SETLIST_H
#define STARRY_SETLIST_H

#endif //STARRY_SETLIST_H

#include "LinkedList.h"

typedef NodeType SetType;
typedef P_Node SetList;

SetList SetInitFromArray(const SetType* array, size_t size, int length);

int SetContains(SetList set, SetType value, size_t size);

void SetAdd(SetList* set, SetType value, size_t size);

void SetRemove(SetList set, SetType value);

void SetPrint(SetList set);