// Implementation of num.h
#include "num.h"

#include "../../../../../MacroLibrary/Random.h"

#include <limits.h>

Number NUMBERrandom(void) { return CAST(Number) RAND_NUM(INT_MAX); }
