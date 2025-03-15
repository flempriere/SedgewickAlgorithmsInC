//Implementation of num.h
//note relies on the C23 standard for definitions of false and true
//use <stdbool.h> for older standards

#include <stdlib.h>
#include "num_bit.h"

Number randNum(void) {
    return ((rand() % 2));
}