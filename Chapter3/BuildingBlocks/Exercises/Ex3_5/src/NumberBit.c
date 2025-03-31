// Implementation of num.h
// note relies on the C23 standard for definitions of false and true
// use <stdbool.h> for older standards

#include "NumberBit.h"

#include "../../../../../MacroLibrary/Random.h"

Number NUMBERrandom(void) { return RANDuint(2); }