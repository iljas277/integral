#include <stdio.h>
#include "../root_functions/root.h"
#include "../asm_functions/functions.h"

void print_root_koords(){
    const double eps = 1e-5;
    double root12 = root(f1, f2, der_f1, der_f2, 1.0, 2.0, eps);
    double root13 = root(f1, f3, der_f1, der_f3, -3.0, -2.0, eps);
    double root23 = root(f2, f3, der_f2, der_f3, 0.0, 1.0, eps);

    printf("\
|                          |  %.5f  |  %.5f  |  %.5f  |\n\
+--------------------------+-----------+-----------+-----------+\n", root12, root13, root23);
}
void print_header(void){
    char *header = "\
+--------------------------+-----------+-----------+-----------+\n\
|                          |  f1 & f2  |  f1 & f3  |  f2 & f3  |\n\
+--------------------------+-----------+-----------+-----------+\n";
    printf(header);
}


void print_iter_cnt(unsigned i1, unsigned i2, unsigned i3){
    char *s = "\
| Number of irerations     |  %-8u |  %-8u |  %-8u |\n\
+--------------------------+-----------+-----------+-----------+\n";
    printf(s, i1, i2, i3);
}