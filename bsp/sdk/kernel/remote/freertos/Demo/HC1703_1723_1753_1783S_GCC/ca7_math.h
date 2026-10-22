#ifndef MATH_H_
#define MATH_H_

#ifdef __cplusplus

extern "C" {

float roundf(float x);
double round(double x);
float fminf(float x, float y);
float fmaxf(float x, float y);
float ceilf(float x);
double frexp(double x, int *exp);
// long long __aeabi_d2lz(double x);
float expf(float x);

}

#endif
#endif
