/**
 * @file Number_v2.h
 * @author Felix Lempriere
 * @brief Provides a variant of the Number Interface wrapping an unsigned
 * integer typedef.
 *
 * Updates the interface to have two methods of choice for generating
 * a random number each corresponding to either Ex3.2 or Ex3.3.
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
 * @brief Generates a random number between [0, min(RAND_MAX, upper_bound) using
 * the modulus function.
 *
 * @param upper_bound Exclusive upper bound on Number to generate will be
 * truncated by RAND_MAX if too large
 *
 *
 * @note The number is approximately uniformly distributed.
 *
 * @pre upper_bound <= RAND_MAX.
 * @post returns i \in [0, upper_bound).
 * @return Number random in [0, min(upper_bound, rand_max)
 */
Number NUMBERrandom_modulus(Number upper_bound);

/**
 * @brief Generates a random number between [0, min(RAND_MAX, upper_bound) using
 * a rescaled double.
 *
 * Generate a random integer between 0
 * and upper_bound -1 by through generating
 * a double in the interval [0, 1) and expanding
 * to the interval [0, upper_bound) and truncating.
 *
 * @param upper_bound Exclusive upper bound on Number to generate.
 *
 *
 * @note The number is approximately uniformly distributed.
 *
 * @pre upper_bound > 0.
 * @post returns i \in [0, upper_bound).
 * @return Number random in [0, upper_bound)
 */
/**
 * @brief 
 * @param upper_bound
 * @return Number
 */
Number NUMBERrandom_truncate(Number upper_bound);