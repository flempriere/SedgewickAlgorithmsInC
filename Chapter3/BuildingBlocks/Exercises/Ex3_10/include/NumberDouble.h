/**
 * @file NumberDouble.h
 * @author Felix Lempriere
 * @brief Number interface with an explicitly typedefed Double.
 * @version 0.1
 * @date 2025-03-15
 *
 * @copyright Copyright (c) 2025
 *
 */
#pragma once

/**
 * @brief Localises numerical data definition
 *
 */
typedef double Number;

/**
 * @brief Generates a random number between [0, 1.0)
 *
 * @note The number is approximately uniformly distributed.
 *
 * @post returns i \in [0, 1.0).
 * @return Random number in [0, min(upper_bound, rand_max)
 */
Number NUMBERrandom(void);