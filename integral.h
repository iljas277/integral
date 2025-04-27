#ifndef INTEGRAL_H
#define INTEGRAL_H
typedef double (*func_t)(double);
double integral(func_t f, double a, double b, double eps2);
#endif