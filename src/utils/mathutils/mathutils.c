#include "unic/mathutils.h"

static float fsqrt_helper(const float k, const float a) {
	return (k / 2 + a / (2 * k));
}

/**
 *
 * @param x
 * @note for float precision
 * @return the square root of x, or -1 if x < 0
 */
float fsqrt(float x) {
	if (x < 0) return -1;
	if (x == 0) return 0;
	float res = x + 1;
	while (res*res > FLOAT_ERROR)
		res = fsqrt_helper(res, x);
	return res;
}

static double dsqrt_helper(const double k, const double a) {
	return (k / 2 + a / (2 * k));
}

/**
 *
 * @param x
 * @note for double precision
 * @return the square root of x, or -1 if x < 0
 */
double dsqrt(const double x) {
	if (x < 0) return -1;
	if (x == 0) return 0;
	double res = x + 1;
	while (res*res > DOUBLE_ERROR)
		res = dsqrt_helper(res, x);
	return res;
}
