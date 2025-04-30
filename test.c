#include <stdio.h>
#include <stdlib.h>
#include "root.h"
#include "integral.h"
#include "search_root_interval.h"
#include <math.h>


double func1(double x){
    return exp(x);
}
double func2(double x){
    return x + 1;
}
double func3(double x){
    return  - x + 1;
}
double der_func1(double x){
    return exp(x);
}
double der_func2(double x){
    return 1;
}
double der_func3(double x){
    return -1;
}
void test(void){
    printf("Тестирование проводится на функциях y = e^x, y = x + 1, y = -x + 1\n");
    int *segment12 = malloc(2 * sizeof(int));
    int *segment13 = malloc(2 * sizeof(int));
    int *segment23 = malloc(2 * sizeof(int));
    segment12 = search_root_interval(func1, func2, segment12);
    segment13 = search_root_interval(func1, func3, segment13);
    segment23 = search_root_interval(func2, func3, segment23);
    
    printf("Поиск корня\n");
    double root12 = root(func1, func2, der_func1, der_func2, segment12[0], segment12[1], 0.000001);
    if (fabs(root12 - 0) < 0.001){
        printf("Правильно найдена точка пересечения\n");
    }
    else {
        printf("Ошибка при нахождении точки пересечения\n");
        return;
    }
    double root13 = root(func1, func3, der_func1, der_func3, segment13[0], segment13[1], 0.00001);
    if (fabs(root13 - 0) < 0.001){
        printf("Правильно найдена точка пересечения\n");
    }
    else {
        printf("Ошибка при нахождении точки пересечения\n");
        return;
    }
    double root23 = root(func2, func3, der_func2, der_func3, segment23[0], segment23[1], 0.001);
    if (fabs(root23 - 0) < 0.001){
        printf("Правильно найдена точка пересечения\n");
    }
    else {
        printf("Ошибка при нахождении точки пересечения\n");
        return;
    }
    double I1 = integral(func1, 1.0, 2.0, 0.000001);
    if (fabs(exp(2) - exp(1) - I1) < 0.001){
        printf("Правильно посчитана площадь на отрезке [1,2]\n");
    }
    else{
        printf("Ошибка при поиске площади\n");
        return;
    }
    double I2 = integral(func2, 1.0, 2.0, 0.000001);
    if (fabs(5.0/2 - I2) < 0.001){
        printf("Правильно посчитана площадь на отрезке [1,2]\n");
    }
    else{
        printf("Ошибка при поиске площади\n");
        return;
    }
    double I3 = integral(func3, 1.0, 2.0, 0.000001);
    if (fabs(-1.0/2 - I3) < 0.001){
        printf("Правильно посчитана площадь на отрезке [1,2]\n");
    }
    else{
        printf("Ошибка при поиске площади\n");
        return;
    }
    free(segment12);
    free(segment13);
    free(segment23);
}
