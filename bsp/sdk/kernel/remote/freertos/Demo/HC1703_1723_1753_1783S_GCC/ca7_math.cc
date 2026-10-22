#include <math.h>

#include "ca7_math.h"
#include "math_private.h"


/* float roundf(float x)
{
    long n = static_cast<long>(x + 0.5f);
    return static_cast<float>(n);
}

double round(double x)
{
    long n = static_cast<long>(x + 0.5);
    return static_cast<double>(n);
}

float fminf(float x, float y)
{
    return (x < y)? x : y;
}

float fmaxf(float x, float y)
{
    return (x > y)? x : y;
}

float ceilf(float x)
{
    float n = roundf(x);
    return (n < x)? n+1 : n;
}

double frexp(double x, int *exp)
{
    double abs_x;
    int sign;

    if (x < 0) {
        abs_x = -x;
        sign = -1;
    } else if (x > 0) {
        abs_x = x;
        sign = 1;
    } else {
        abs_x = 0;
        sign = 0;
    }

    if (abs_x < 0.00000000001) {
        *exp = 0;
        return 0;
    }

    *exp = 0;
    while (abs_x > 1.0) {
        abs_x /= 2;
        ++*exp;
    }
    while (abs_x < 0.5) {
        abs_x *= 2;
        --*exp;
    }

    return (sign > 0)? abs_x : -abs_x;
} */

/* long long __aeabi_d2lz(double x)
{
    return static_cast<long long>(static_cast<long>(x));
} */

/* float expf(float x)
{
    int n = static_cast<int>(roundf(x));
    float result = 1;
    const float e = 2.7182818;
    if (n == 0) {
        return 1;
    } else if (n > 0) {
        for (int i = 0; i < n; ++i) {
            result *= e;
        }
        return result;
    } else {
        for (int i = 0; i < -n; ++i) {
            result /= e;
        }
        return result;
    }
} */
