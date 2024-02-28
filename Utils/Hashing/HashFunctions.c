//
// Created by andre on 8/9/2023.
//

#include "HashFunctions.h"
#include <stdint.h>

#define PRIME 31

size_t normalize(size_t val, size_t size) {
    return val % size;
}

size_t hash_addr(Generic addr, size_t size) {
	uint64_t out = ((uint64_t) addr) * (uint64_t)PRIME;
	return normalize(out, size);
}

