#include <stdio.h>
#include "test.h"
#include "count.h"
#include <string.h>



int main(int argc, char **argv){
    if (argc == 2 && !strcmp(argv[1], "-t")){
        test();
    }
    else
        count();
    return 0;
}