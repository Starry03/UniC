#include <stdio.h>
#include <limits.h>

#include "Math.h"
#include "Tests.h"

int main()
{
    int inputs[] = {1, 4, 8, 16, INT_MAX};
    int expected[] = {1, 2, 0, 4, 0};
    test_int_to_int(inputs, expected, sizeof(inputs) / 4, &Math_int_sqrt);
    return 0;
}
