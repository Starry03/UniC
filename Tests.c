//
// Created by andre on 10/5/2023.
//

#include "Tests.h"

#include <stdio.h>

void test_int_to_int(int inputs[], const int expected[], size_t n_test, int (func)(int)) {
    size_t i = 0;
    size_t passed = 0;
    int res;
    int expected_res;
    printf("%s", "TESTING\n");
    while (i < n_test) {
        printf("Test %d\nInput: %d\n", i, inputs[i]);
        res = func(inputs[i]);
        expected_res = expected[i];
        if (res == expected_res) {
            printf("PASSED\n");
            passed++;
        } else
            printf("FAILED\n");
        printf("Res: %d Expected: %d\n", res, expected_res);
        i++;
    }
    printf("Passed: %lld / %lld\n", passed, n_test);
    printf("%s", "END TEST\n\n");
}
