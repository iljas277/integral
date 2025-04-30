#include <stdio.h>
#include <math.h>
#include "main.h"

int *search_root_interval(func_t f, func_t g, int *coords){
    double start_value1 = (f(0) - g(0)), start_value2 = (f(0) - g(0));
    if (fabs(start_value1) < 1e-15) {
        coords[0] = 0;
        coords[1] = 0;
        return coords;
    }
    int i = 1;
    while (1){
        double temp_value1 = f(i) - g(i);
        double temp_value2 = f(-i) - g(-i);
        if (temp_value1 * start_value1 < 0){
            coords[0] = i - 1;
            coords[1] = i;
            break;
        }

        if (temp_value2 * start_value2 < 0){
            coords[0] = -i;
            coords[1] = -i + 1;
            break;
        }
        i++;
        start_value1 = temp_value1;
        start_value2 = temp_value2;
    }

    return coords;
}