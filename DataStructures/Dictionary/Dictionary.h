//
// Created by andre on 8/9/2023.
//

#ifndef DICTIONARY_H
#define DICTIONARY_H

#include <stdbool.h>
#include <corecrt.h>
#include "../../DataStructures/LinkedList/LinkedList.h"
#include "../../Utils/AllocationUtils/AllocationUtils.h"

typedef struct s_dictionary {
	LinkedList **buckets;
	size_t size;
} t_dictionary;

#endif
