//
// Created by andre on 4/18/2023.
//

#ifndef STARRY_SEARCH_H
#define STARRY_SEARCH_H

#include <stddef.h>
#include "../../Utils/types.h"

size_t LinearSearch(const Generic *arr, size_t length, Generic target);

size_t BinarySearch(const Generic *arr, size_t length, Generic target);

#endif //STARRY_SEARCH_H
