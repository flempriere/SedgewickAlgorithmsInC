/**
 * @file Ex3-5
 * @author Felix Lempriere
 * @brief Solution to Exercise 3.5.
 *
 * Implements a variant of Program 3.2 that supports bit types. We take this
 * to mean 0 or 1 values (like bool) rather than explicitly bit-sized types.
 *
 * @date 2025-04-07
 * @version 0.1
 *
 * @copyright Copyright (c) 2025
 */

#include "MacroLibrary/NumberParse.h"
#include "MacroLibrary/Random.h"
#include "MacroLibrary/Statistics.h"
#include "MacroLibrary/Utility.h"
#include "include/NumberBit.h"

#include <stdio.h>
#include <stdlib.h>
#include <tgmath.h>

/**
 * @brief Wrap NUMBERrandom in the interface required for calculate statistics.
 *
 * @return double
 */
double rand_num_to_double(void);

/**
 * @brief Performs avg and std. dev calculations
 * on random bits.
 *
 * @return EXIT_SUCCESS on success else EXIT_FAILURE.
 */
int main(int argc, char* argv[argc + 1]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: ./app N\n");
        return EXIT_FAILURE;
    }
    register size_t const N = NUMPARSEexit_on_fail(N, argv[1]);
    RAND_SEED_TIME;

    register STATSmeasures sm =
        STATScalculate_statistics(rand_num_to_double, N);
    STATSsummary_print(sm);

    return EXIT_SUCCESS;
}

double rand_num_to_double(void) { return CAST(double) NUMBERrandom(); }