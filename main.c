#include <stdio.h>
#include <stdlib.h>
#include "functions.h"
#include "root.h"
#include "integral.h"
#include "search_root_interval.h"
#include <math.h>



int main(int argc, char **argv){
    int *segment12 = malloc(2 * sizeof(int));
    int *segment13 = malloc(2 * sizeof(int));
    int *segment23 = malloc(2 * sizeof(int));

    segment12 = search_root_interval(f1, f2, segment12);
    segment13 = search_root_interval(f1, f3, segment13);
    segment23 = search_root_interval(f2, f3, segment23);
    double root12 = root(f1, f2, der_f1, der_f2, segment12[0], segment12[1], 0.001);
    double root13 = root(f1, f3, der_f1, der_f3, segment13[0], segment13[1], 0.001);
    double root23 = root(f2, f3, der_f2, der_f3, segment23[0], segment23[1], 0.001);
    printf("%f %f %f\n", root12, root13, root23);
    double I1 = integral(f1, root13, root12, 0.000001);
    double I2 = integral(f2, root23, root12, 0.000001);
    double I3 = integral(f3, root13, root23, 0.000001);
    printf("%f\n%f\n%f\n", I1, I2, I3);
    double I = I1 - I2 - I3;
    printf("%f", I);
    free(segment12);
    free(segment13);
    free(segment23);
    return 0;
}