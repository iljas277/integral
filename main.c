#include <stdio.h>
#include "print_test/test.h"
#include <string.h>
#include "root_functions/root.h"
#include "integral_functions/integral.h"
#include "asm_functions/functions.h"
unsigned iter_cnt = 0;
int main(int argc, char **argv){
    int root_print = 0, iter_count_print = 0;
    unsigned i1, i2, i3;
    const double eps1 = 1e-5;
    const double eps2 = 1e-5;
    for(int i = 1; i < argc; i++){
        if(strcmp(argv[i], "-help") == 0){
            printf(help_message);
            return 0;
        } else
        if(strcmp(argv[i], "-i") == 0){
            iter_count_print = 1;
        } else
        if(strcmp(argv[i], "-r") == 0){
            root_print = 1;
        } else
        if(strcmp(argv[i], "-ti") == 0){
            test_integral();
            return 0;
        } else
        if(strcmp(argv[i], "-tr") == 0){
            test_root();
            return 0;
        } 
    }
    double root12 = root(f1, f2, der_f1, der_f2, 1.0, 2.0, eps1);
    i1 = iter_cnt;
    double root13 = root(f1, f3, der_f1, der_f3, -3.0, -2.0, eps1);
    i2 = iter_cnt;
    double root23 = root(f2, f3, der_f2, der_f3, 0.0, 1.0, eps1);
    i3 = iter_cnt;
    if(root_print || iter_count_print){
        print_header();
        if(root_print) print_root_koords();
        if(iter_count_print) print_iter_cnt(i1, i2, i3);
        printf("\n");
    }
    double I1 = integral(f1, root13, root12, eps2);
    double I2 = integral(f2, root23, root12, eps2);
    double I3 = integral(f3, root13, root23, eps2);
    double I = I1 - I2 - I3;
    printf("Counted area = %.3f", I);
    return 0;
}