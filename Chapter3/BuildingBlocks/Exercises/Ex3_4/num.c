//Implementation of num.h

#include <stdlib.h>
#include "num_v2.h"

Number randNumModulus(Number upper_bound) {
    return rand() % upper_bound;
}

Number randNumTruncate(Number upper_bound) {
    double rand_num = 1.0*rand()/RAND_MAX;
    return rand_num*upper_bound;
}
