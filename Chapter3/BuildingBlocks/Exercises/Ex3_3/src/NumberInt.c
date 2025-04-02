// Implementation of NumberInt.h that uses a RAND_UNIFORM rather than RAND_NUM
// as its underlying system.

#include "Interfaces/Number/v1/NumberInt/NumberInt.h"

#include "MacroLibrary/Random.h"

Number NUMBERrandom(Number const ub) { return CAST(Number)(RANDUNIFORM(ub)); }
