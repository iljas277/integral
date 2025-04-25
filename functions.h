#ifndef FUNCTIONS_H
#define FUNCTIONS_H
#include "root.c"
#include "integral.c"
typedef double func(double); 
typedef double (*func_t)(double);
extern func f1, f2, f3, der_f1, der_f2, der_f3;
double root(func_t f, func_t g, func_t der_f, func_t der_g,  double a, double b, double eps1);
double integral(func_t f, double a, double b, double eps2);
#endif 