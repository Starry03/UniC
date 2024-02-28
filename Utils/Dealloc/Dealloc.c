#include "Dealloc.h"

void inline dealloc_int(Generic addr) { free((int *)addr); }
void inline dealloc_float(Generic addr) { free((float *)addr); }
void inline dealloc_string(Generic addr) { free((char *)addr); }
void inline dealloc_long(Generic addr) { free((long long *)addr); }
void inline dealloc_double(Generic addr) { free((double *)addr); }



