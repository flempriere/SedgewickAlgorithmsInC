// Implementation of num.h

#include "Number_v2.h"

#include "../../../../../MacroLibrary/Random.h"
#include "../../../../../MacroLibrary/Utility.h"

Number NUMBERrandom_modulus(Number upper_bound) {
    return RAND_NUM(upper_bound);
}

Number NUMBERrandom_truncate(Number upper_bound) {
    return CAST(Number)(RAND_UNIFORM() * upper_bound);
}
