// Implementation of NumberInt.h that uses a RAND_UNIFORM rather than RAND_NUM
// as its underlying system.

#include "../../../../../MacroLibrary/Random.h"
#include "../../Ex3_2/src/NumberInt.h"

Number NUMBERrandom(Number const ub) {
    return CAST(Number)(RANDuniform() * ub);
}
