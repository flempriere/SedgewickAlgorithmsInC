/**
 * @file avg.c
 * @author Felix Lempriere
 * @brief Multifile implementation of Program 3.2.
 *
 * This file serves as the client file in a multifile implementation
 * that utilizes an interface file (num.h) and an implementation file (num.c).
 * It demonstrates the use of modular programming by separating the client,
 * interface, and implementation logic.
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
#include "include/NumberShort.h"

#include <stdio.h>
#include <stdlib.h>
#include <tgmath.h>

/**
 * @brief Converts a random number to a double.
 *
 * Designed to wrap the NUMBERrandom in the interface for calculateStatistics
 * @return double
 */
static inline double rand_num_to_double(double const ub);
/**
 * @brief Calculate the average and standard deviation
 * of a collection of random numbers.
 *
 * @param argv[1] number of random numbers to generate
 *
 * @return EXIT_SUCCESS on success, else EXIT_FAILURE
 *
 */
int main(int argc, char* argv[argc + 1]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: ./app N\n");
        return EXIT_FAILURE;
    }
    register size_t const N = NUMPARSEexit_on_fail(N, argv[1]);
    RAND_SEED_TIME;

    register STATSmeasures results =
        STATScalculate_statistics(rand_num_to_double, N, NUM_MAX);
    STATSsummary_print(results);

    return EXIT_SUCCESS;
}

double rand_num_to_double(double const ub) {
    return CAST(double) NUMBERrandom(CAST(Number) ub);
}