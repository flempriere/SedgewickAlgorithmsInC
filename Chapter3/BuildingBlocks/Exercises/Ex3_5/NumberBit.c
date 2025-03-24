// Implementation of num.h
// note relies on the C23 standard for definitions of false and true
// use <stdbool.h> for older standards

#include "../../../../MacroLibrary/Random.h"
#include "NumberBit.h"

Number NUMBERrandom(void) { return RAND_NUM(2); }