#ifndef ROOT_H
#define ROOT_H
typedef double (*func_t)(double);
double root(func_t f, func_t g, func_t der_f, func_t der_g,  double a, double b, double eps1);
#endif