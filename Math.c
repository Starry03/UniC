//
// Created by andre on 10/4/2023.
//

#include "Math.h"
#include <stdio.h>

int Math_int_sqrt(int x) {
    // best case
    if (!x || x < 0)
        return 0;
    if (x == 1)
        return 1;

    long long left = 1;
    long long right = x;
    long long mid;
    long long sq;
    long long lx = (long long) x;

    while (left < right) {
        mid = (left + right) / 2;
        sq = mid * mid;
        if (sq > lx)
            right = mid - 1;
        else if (sq == lx)
            return mid;
        else
            left = mid + 1;
    }
    return 0;
}