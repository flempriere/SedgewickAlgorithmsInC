// Implementation of num.h
#include "Number.h"

#include "../../../../../../MacroLibrary/Random.h"
#include "../../../../../../MacroLibrary/Utility.h"

#include <limits.h>

Number NUMBERrandom(void) { return CAST(Number) RAND_NUM(NUM_MAX); }
