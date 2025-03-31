// Implementation of num.h

#include "Number_v2.h"

#include "../../../../../MacroLibrary/Random.h"
#include "../../../../../MacroLibrary/Utility.h"

Number NUMBERrandom_modulus(Number upper_bound) {
    return CAST(Number) RANDuint(upper_bound);
}

Number NUMBERrandom_truncate(Number upper_bound) {
    return CAST(Number)(RANDuniform() * upper_bound);
}
