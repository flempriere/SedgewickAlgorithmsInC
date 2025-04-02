// Interface for the number type
#pragma once

#include <limits.h>

/**
 * @brief localised typedef for number type being used
 *
 */
typedef unsigned short Number;

constexpr Number NUM_MAX = USHRT_MAX;

/**
 * @brief Generates a random number up to
 * MIN(RAND_MAX, INT_MAX)
 *
 * @return Number
 */
Number NUMBERrandom(Number const ub);