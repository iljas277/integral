#include <stdio.h>
#include "test.h"
#include "count.h"
#include <string.h>



int main(int argc, char **argv){
    if (argc == 2 && !strcmp(argv[1], "-tr")){
        test_root();
    }
    else if (argc == 2 && !strcmp(argv[1], "-ti")){
        test_integral();
    }
    else
        count();
    return 0;
}