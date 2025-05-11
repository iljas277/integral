#ifndef TEST_H
#define TEST_H

char *help_message = "\
Usage: ./main [options]\n\
Options:\n\
    -help  Display this inforamtion\n\
    -r     Display the abscissa of intersection of functions\n\
    -i     Display the number of iterations of root function\n\
    -ti    Run program in testing mode for integral function\n\
    -tr    Run program in testing mode for root function\n";
char *header = "\
+--------------------------+-----------+-----------+-----------+\n\
|                          |  f1 & f2  |  f1 & f3  |  f2 & f3  |\n\
+--------------------------+-----------+-----------+-----------+\n";
char *iterations = "\
| Number of irerations     |  %-8u |  %-8u |  %-8u |\n\
+--------------------------+-----------+-----------+-----------+\n";




void test_root(void);
void test_integral(void);
void print_root_koords(void);
void print_header(void);
void print_iter_cnt(unsigned i1, unsigned i2, unsigned i3);
#endif