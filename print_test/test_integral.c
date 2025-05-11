#include <stdio.h>
#include <stdlib.h>
#include "../root_functions/root.h"
#include "../integral_functions/integral.h"
#include <math.h>


double i_func1(double x){
    return 1;
}
double i_func2(double x){
    return 2 * x;
}
double i_func3(double x){
    return  x * x  - 3 * x  + 5;
}
double i_func4(double x){
    return exp(x);
}
void test_integral(void){
    const double eps = 1e-5;
    printf("Тестирование на вычисление интеграла\n");
    
    printf("Поиск  ...\n");
    printf("f: 1\n");
    printf("eps: %.5f\n", eps);
    printf("interval: [0, 2]\n");
    printf("Correct integral: 2.0\n");
    double I1 = integral(i_func1, 0.0, 2.0, eps);
    printf("Calculated integral: %.5f\n", I1);
    if (fabs(I1 - 2.0) < eps){
        printf("Правильно найден интеграл\n");
    }
    else {
        printf("Ошибка при нахождении интеграла\n");
        return;
    }
    printf("Поиск  ...\n");
    printf("f: 2 * x\n");
    printf("eps: %.5f\n", eps);
    printf("interval: [-1, 2]\n");
    printf("Correct integral: 3.0\n");
    double I2 = integral(i_func2, -1.0, 2.0, eps);
    printf("Calculated integral: %.5f\n", I2);
    if (fabs(I2 - 3.0) < eps){
        printf("Правильно найден интеграл\n");
    }
    else {
        printf("Ошибка при нахождении интеграла\n");
        return;
    }
    printf("Поиск  ...\n");
    printf("f: x^2 - 3*x + 5\n");
    printf("eps: %.5f\n", eps);
    printf("interval: [-1, 2]\n");
    printf("Correct integral: 13.5\n");
    double I3 = integral(i_func3, -1.0, 2.0, eps);
    printf("Calculated integral: %.5f\n", I3);
    if (fabs(I3 - 13.5) < eps){
        printf("Правильно найден интеграл\n");
    }
    else {
        printf("Ошибка при нахождении интеграла\n");
        return;
    }
    printf("Поиск  ...\n");
    printf("f: e^x\n");
    printf("eps: %.5f\n", eps);
    printf("interval: [-1, 2]\n");
    printf("Correct integral: 7.02117\n");
    double I4 = integral(i_func4, -1.0, 2.0, eps);
    printf("Calculated integral: %.5f\n", I4);
    if (fabs(I4 - 7.02117) < eps){
        printf("Правильно найден интеграл\n");
    }
    else {
        printf("Ошибка при нахождении интеграла\n");
        return;
    }
}
