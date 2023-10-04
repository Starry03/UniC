//
// Created by andre on 10/5/2023.
//

#include "Tests.h"
#include <stdio.h>

void test_int_to_int(int inputs[], int expected[], int n_test, int (func) (int)) {
    int i = 0;
    int passed = 0;
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
        }
        else
            printf("FAILED\n");
        printf("Res: %d Expected: %d\n", res, expected_res);
        i++;
    }
    printf("Passed: %d / %d\n", passed, n_test);
    printf("%s", "END TEST\n\n");
}
