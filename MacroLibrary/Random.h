/**
 * @file Random.h
 * @author Felix Lempriere
 * @brief File containing Macros and functions related to random numbers.
 * @version 0.1
 * @date 2025-03-23
 *
 * @copyright Copyright (c) 2025
 *
 */
#pragma once

#include "Utility.h"

#include <stdlib.h>
#include <time.h>
/**
 * @brief Seed the Random Number Generator with the current time.
 *
 */
#define RAND_SEED_TIME srand(CAST(unsigned int) time(nullptr))

/**
 * @brief Generate a random unsigned int between 0 and ub (exlusive)
 *
 * @param ub positive integer < @RAND_MAX
 * @return unsigned int from [0, ub).
 */
static inline unsigned int RANDuint(unsigned int ub) {
    return CAST(unsigned) rand() % ub;
}

/**
 * @brief Generate a random float between 0 and 1.0.
 *
 * @return double
 */
static inline double RANDuniform(void) { return 1.0 * rand() / RAND_MAX; }

/**
 * @brief Performs a weighted coin toss
 * and return true if successful
 * @param weight probability of success.
 * @return true if successful else
 * @return false
 */
static inline bool RANDcoin_toss(long double weight) {
    return (RANDuniform() < weight);
}

#define RAND_COIN_TOSS(...) CALL1(RANDcoin_toss, 0.5, __VA_ARGS__)
