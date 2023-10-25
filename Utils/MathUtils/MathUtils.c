//
// Created by andre on 10/4/2023.
//

#include "MathUtils.h"

// Binary search sqrt
// Handles from min int to max int
// O(log n)
int Math_int_sqrt(int x) {
    typedef long long ll;

    // best case
    if (!x || x < 0)
        return 0;

    if (x == 1)
        return 1;

    ll left = 2;
    ll right = x;
    ll mid;
    ll sq;
    ll lx = (ll) x;

    while (left <= right) {
        mid = (left + right) / 2;
        sq = mid * mid;
        if (sq > lx)
            right = mid - 1;
        else if (sq == lx)
            return (int) mid;
        else
            left = mid + 1;
    }
    return 0;
}

// O(1)
int Math_int_sq(int x) {
    return x * x;
}

// O(n)
int Math_int_pow(int x, int exp) {
    // best case
    if (x == 0 || exp < 0)
        return 0;
    if (exp == 0)
        return 1;

    int temp = x;
    while (exp > 1) {
        x *= temp;
        exp--;
    }
    return x;
}

float Math_float_pow(float x, float exp) {
    // best case
    if (x == 0) return (0);
    if (exp == 0) return (1);

    // TODO
    return 0;
}
