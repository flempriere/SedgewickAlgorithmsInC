/**
 * @file Number_v2.c
 * @author Felix Lempriere
 * @brief Implementation of the Number_v2 interface which supports two different
 * methods for generating a random number.
 * @version 0.1
 * @date 2025-04-02
 *
 * @copyright Copyright (c) 2025
 *
 */
#include "../Number_v2.h"

#include "MacroLibrary/Random.h"
#include "MacroLibrary/Utility.h"

Number NUMBERrandom_modulus(Number upper_bound) {
    return CAST(Number) RANDUINT(upper_bound);
}

Number NUMBERrandom_truncate(Number upper_bound) {
    return CAST(Number)(RANDUNIFORM(upper_bound));
}