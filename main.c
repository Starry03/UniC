#include <stdio.h>
#include <limits.h>

#include "Math.h"
#include "Tests.h"

int main()
{
    int inputs[] = {81, INT_MIN, INT_MAX, 9, 25, 144, 2500, 6241, 0, 1, -2};
    int expected[] = {9, 0, 0, 3, 5, 12, 50, 79, 0, 1, 0};
    test_int_to_int(inputs, expected, sizeof(inputs) / sizeof(int), &Math_int_sqrt);
    return 0;
}
