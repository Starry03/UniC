//
// Created by andre on 8/9/2023.
//

#include "HashFunctions.h"

#define MAGIC 0xdeadbeef

size_t normalize(size_t val, size_t size) {
    return val % size;
}

size_t hash_addr(Generic addr, size_t size)
{
	size_t addr_ = (size_t)addr;
	addr_ = addr_ ^ (addr_ >> 4);
	addr_ = (addr_ + (addr_ << 5)) ^ MAGIC;
	addr_ = addr_ ^ (addr_ >> 11);
	return normalize(addr_, size);
}