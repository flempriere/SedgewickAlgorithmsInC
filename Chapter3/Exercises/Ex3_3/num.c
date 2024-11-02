//Implementation of num.h

#include <stdlib.h>
#include "num.h"

Number randNum(Number upper_bound) {
    double rand_num = 1.0*rand()/RAND_MAX;
    return rand_num*upper_bound;
}
