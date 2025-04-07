/**
 * @file NumberShort.h
 * @author Felix Lempriere
 * @brief Interface for the number type.
 *
 * This header file defines the interface for the number type used in the
 * multifile implementation example from Chapter 3 of Sedgewick's
 * "Algorithms in C".
 *
 * @date 2025-04-07
 * @version 0.1
 *
 * @copyright Copyright (c) 2025
 */
#pragma once

#include <limits.h>

/**
 * @brief localised typedef for number type being used
 *
 */
typedef unsigned short Number;

constexpr Number NUM_MAX = USHRT_MAX;

/**
 * @brief Generates a random number between [0, min(RAND_MAX, upper_bound)
 *
 * @param upper_bound Exclusive upper bound on Number to generate. May be
 * truncated by RAND_MAX if too large depending on the implementation.
 *
 *
 * @note The number is approximately uniformly distributed.
 *
 * @pre upper_bound <= RAND_MAX.
 * @post returns i \in [0, upper_bound).
 * @return Number random in [0, min(upper_bound, rand_max)
 */
Number NUMBERrandom(Number const ub);