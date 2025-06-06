#include <stdio.h>
#include <math.h>
#include "../main.h"
extern unsigned iter_cnt;

double root(func_t f, func_t g, func_t der_f, func_t der_g,  double a, double b, double eps1){
    iter_cnt = 0;
    int sign_der = (f(b) - g(b) >= f(a) - g(a)) ? 0 : 1;
    int sign_2der = (f(b) - g(b) + f(a) - g(a) >= 2 * (f((a + b) / 2) - g((a + b) / 2)))? 0 : 1;
    double Root;
    if ((sign_der + sign_2der) % 2 == 0){
        while(fabs(a - b) >= eps1){
            double derivative = der_f(b) - der_g(b);
            if (fabs(derivative) < 1e-10) {
                break;
            } 
            a -= (f(a) - g(a)) * (b - a) / (f(b) - g(b) - (f(a) - g(a)));
            b -= (f(b) - g(b))/ (der_f(b) - der_g(b));
            iter_cnt++;
        }
        Root = (a + b) / 2;
        
    }
    else {
        while(fabs(a - b) >= eps1){
            double derivative = der_f(b) - der_g(b);
            if (fabs(derivative) < 1e-10) {
                break;
            }
            b -= (f(b) - g(b)) * (b - a) / (f(b) - g(b) - (f(a) - g(a)));
            a -= (f(a) - g(a))/ (der_f(a) - der_g(a));
            iter_cnt++;
        }
        Root = (a + b) / 2;
        
    }

    return Root;    
}

