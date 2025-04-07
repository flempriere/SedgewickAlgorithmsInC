/**
 * @file NumberInt.h
 * @author Felix Lempriere
 * @brief Provides a variant of the Number Interface wrapping an unsigned
 * integer typedef.
 *
 * @date 2025-04-07
 * @version 0.1
 *
 * @copyright Copyright (c) 2025
 */
#pragma once

/**
 * @brief Supports a flexible numeric type.
 */
typedef unsigned int Number;

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
Number NUMBERrandom(Number const upper_bound);