//
// Created by andre on 8/9/2023.
//

#ifndef STARRY_CLIBRARY_HASHFUNCTIONS_H
#define STARRY_CLIBRARY_HASHFUNCTIONS_H

#endif //STARRY_CLIBRARY_HASHFUNCTIONS_H

#include <stdlib.h>

size_t normalize(size_t val, size_t size);

size_t hashInt(void *key, size_t size);

size_t hashFloat(void *key, size_t size);

size_t hashString(void *key, size_t size);

size_t hashAddress(void* key, size_t size);
