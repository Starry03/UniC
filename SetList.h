//
// Created by andre on 4/21/2023.
//

#ifndef STARRY_SETLIST_H
#define STARRY_SETLIST_H

#endif //STARRY_SETLIST_H

#include "LinkedList.h"

typedef NodeType SetType;
typedef P_Node SetList;

SetList SetInitFromArray(const SetType* array, int size);

int SetContains(SetList set, SetType value);

void SetAdd(SetList* set, SetType value);

void SetRemove(SetList set, SetType value);

void SetPrint(SetList set);