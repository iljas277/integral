#include <stdio.h>
#include <math.h>
#include "../main.h"


double integral(func_t f, double a, double b, double eps2){
    int n = 1;
    double start_I;
    double h = (b - a) / (2 * n);
    double even_ind_sum = 0.0;
    double x = a + 2 * h;
    for (int i = 2; i < 2 * n; i += 2){
        even_ind_sum += f(x);
        x += h * 2;
    }
    even_ind_sum *= 2;
    x = a + h;
    double odd_ind_sum = 0.0;
    for (int i = 1; i < 2 * n; i += 2){
        odd_ind_sum += f(x);
        x += h * 2;
    }
    odd_ind_sum *= 4;
    start_I = (f(a) + f(b) + odd_ind_sum + even_ind_sum) * h / 3;
    double I = start_I;
    odd_ind_sum /= 4;
    even_ind_sum /= 2;
    do
    {   
        n *= 2;
        start_I = I;
        double H = (b - a) / (2 * n);
        double Even_ind_sum = even_ind_sum + odd_ind_sum;
        Even_ind_sum *= 2;
        double X = a + H;
        double Odd_ind_sum = 0.0;
        for (int i = 1; i < 2 * n; i += 2){
            Odd_ind_sum += f(X);
            X += H * 2;
        }
        Odd_ind_sum *= 4;
        I = (f(a) + f(b) + Odd_ind_sum + Even_ind_sum) * H / 3;
        even_ind_sum = Even_ind_sum / 2, odd_ind_sum = Odd_ind_sum / 4;
    } while (fabs(I - start_I) > eps2);
    
    return I;
}