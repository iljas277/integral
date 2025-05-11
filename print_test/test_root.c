#include <stdio.h>
#include <stdlib.h>
#include "../integral_functions/integral.h"
#include "../root_functions/root.h"
#include <math.h>


double func1(double x){
    return exp(x) - 3;
}
double func2(double x){
    return - x * x - x + 5;
}
double func3(double x){
    return  1 / (x + 3) + 3;
}
double func4(double x){
    return pow(2, x) - 2;
}
double der_func1(double x){
    return exp(x);
}
double der_func2(double x){
    return - 2 * x - 1;
}
double der_func3(double x){
    return -1 / pow(x + 3, 2);
}
double der_func4(double x){
    return pow(2, x) * log(2);
}
void test_root(void){
    const double eps = 1e-5;
    printf("Тестирование  на поиск корня\n");
    printf("Поиск корня ...\n");
    printf("f: e^x - 3\n");
    printf("g: -x^2 - x + 5\n");
    printf("eps: %.5f\n", eps);
    printf("interval: [0, 2]\n");
    printf("Correct root: 1.47239\n");
    double root12 = root(func1, func2, der_func1, der_func2, 0.0, 2.0, eps);
    printf("Calculated root: %.5f\n", root12);
    if (fabs(root12 - 1.47239) < eps){
        printf("Правильно найдена точка пересечения\n");
    }
    else {
        printf("Ошибка при нахождении точки пересечения\n");
        return;
    }
    double root34 = root(func3, func4, der_func3, der_func4, 0.0, 4.0, eps);
    printf("Поиск корня\n");
    printf("f: 1 / (x + 3) + 3\n");
    printf("g: 2 ^ x - 2\n");
    printf("eps: %.5f\n", eps);
    printf("interval: [0, 2]\n");
    printf("Correct root: 2.37464\n");
    printf("Calculated root: %.5f\n", root34);
    if (fabs(root34 - 2.37464) < eps){
        printf("Правильно найдена точка пересечения\n");
    }
    else {
        printf("Ошибка при нахождении точки пересечения\n");
        return;
    }
}
