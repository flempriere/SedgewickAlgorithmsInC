//Implementation of num.h

#include <stdlib.h>
#include <limits.h>
#include "num.h"

Number randNum(void) {
    return rand() % NUM_MAX;
}
