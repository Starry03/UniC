//
// Created by andre on 10/5/2023.
//

#ifndef STARRY_CLIBRARY_TESTS_H
#define STARRY_CLIBRARY_TESTS_H

#include <stddef.h>

void test_int_to_int(int inputs[], const int expected[], size_t n_test, int (func)(int));

#endif //STARRY_CLIBRARY_TESTS_H
