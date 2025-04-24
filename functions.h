#ifndef FUNCTIONS_H
#define FUNCTIONS_H
#include "functions/root.c"
#include "functions/integral.c"
typedef double (*func_t)(double);

double root(func_t f, func_t g, func_t der_f, func_t der_g,  double a, double b, double eps1);
double integral(func_t f, double a, double b, double eps2);
#endif 