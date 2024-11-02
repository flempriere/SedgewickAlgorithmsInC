//Implementation of num.h

#include <stdlib.h>
#include "num.h"

Number randNum(Number upper_bound) {
    return rand() % upper_bound;
}
