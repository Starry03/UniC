#ifndef CONVERSION_H
#define CONVERSION_H

#include "../types.h"
#include <stdint.h>
#include <stddef.h>

t_string uintToString(uint64_t n, size_t bits);

#endif // !CONVERSION_H
