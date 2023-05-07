//
// Created by andre on 4/21/2023.
//

#ifndef STARRY_SETLIST_H
#define STARRY_SETLIST_H

#endif //STARRY_SETLIST_H

#include "Nodes.h"
#include "stdbool.h"

typedef NodeType SetType;
typedef SizedNode *SetList;

bool SetContains(SetList set, SetType value, size_t size);

void SetAdd(SetList *set, SetType value, size_t size);

void SetRemove(SetList* set, SetType value, size_t size);

int SetLength(SetList set);
