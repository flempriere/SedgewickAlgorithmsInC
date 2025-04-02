/**
 * @file NumberInt.c
 * @author Felix Lempriere
 * @brief Implements the Number interface for an unsigned integer type, using
 * modulus to generate the random number.
 * @version 0.1
 * @date 2025-04-02
 *
 * @copyright Copyright (c) 2025
 *
 */
#include "../NumberInt.h"

#include "MacroLibrary/Random.h"

Number NUMBERrandom(Number ub) { return RANDUINT(ub); }