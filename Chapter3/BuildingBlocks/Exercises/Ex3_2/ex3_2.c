/**
 * @file Ex3-2
 * @author Felix Lempriere
 * @brief Solution to Exercise 3.2.
 *
 * Test the random number generator on your system by generating
 * N random integers from 0 to r-1 with rand() % r and computing
 * the avg and std. dev. for r = 10, 100, 1000, N = 10^3, 10^4,
 * 10^5, 10^6.
 *
 * @date 2025-04-07
 * @version 0.1
 *
 * @copyright Copyright (c) 2025
 */

#include "MacroLibrary/Random.h"
#include "MacroLibrary/Statistics.h"
#include "MacroLibrary/Utility.h"
#include "include/NumberInt.h"

#include <stdio.h>
#include <stdlib.h>
#include <tgmath.h>

/**
 * @brief Number of test cases for N. Each successive test case is 10x larger
 * than the previous case.
 *
 */
constexpr size_t N_CASES = 4u;
/**
 * @brief Number of test cases for r. As with @N_CASES each case is 10x larger
 * than the previous case.
 *
 */
constexpr size_t R_CASES = 3u;

/**
 * @brief Starting value for N
 *
 */
constexpr size_t N_INIT = 10000u;

/**
 * @brief Starting value for R
 *
 */
constexpr unsigned int R_INIT = 10u;

/**
 * @brief Wraps the NUMBERrandom interface in the required structure
 * for the statistics.h calling methods.
 *
 * @param ub upper bound.
 * @return double
 */
static inline double rand_num_to_double(double const ub);

/**
 * @brief Test the random number generator by
 * generating numbers between 0 and r - 1 using
 * rand() % (r), N times and compute the avg
 * and std. dev.
 *
 * Starts and R = R_INIT, and N = N_INIT, and
 * each successive case is 10x larger.
 *
 * @return EXIT_SUCCESS
 */
int main(int argc, char* argv[argc + 1]) {
    register size_t n = N_INIT;
    register Number r = R_INIT;

    RAND_SEED_TIME;

    for (register size_t i = 0; i < N_CASES;
         n *= 10, i++) {    // iterate over N values
        for (register size_t j = 0; j < R_CASES;
             r *= 10, j++) {    // iterate over r values

            register STATSmeasures sm =
                STATScalculate_statistics(rand_num_to_double, n, r);

            STATSsummary_print(sm, "Results for N: %zu, R: %u", n, r);
        }
        printf("\n");
        r = R_INIT;
    }

    return EXIT_SUCCESS;
}

static inline double rand_num_to_double(double const ub) {
    return CAST(double) NUMBERrandom(CAST(Number) ub);
}