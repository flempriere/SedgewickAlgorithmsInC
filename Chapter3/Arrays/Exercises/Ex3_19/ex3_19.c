/**
 * @file ex3_19.c
 * @author Felix Lempriere
 * @brief Solution to Exercise 3-19.
 *
 * Empirically determine the number of random positive integers less than 1000
 * that you can expect to generate before getting all values.
 * 
 * This implementation repeats the experiment M times where M is a command line
 * argument.
 *
 * @date 2025-04-07
 * @version 0.1
 *
 * @copyright Copyright (c) 2025
 */

#include "MacroLibrary/NumberParse.h"
#include "MacroLibrary/Random.h"
#include "MacroLibrary/Statistics.h"

#include <stdio.h>
#include <stdlib.h>
#include <tgmath.h>

/**
 * @brief largest number we can generate
 *
 */
constexpr size_t MAX_NUM = 1000u;

/**
 * @brief generates numbers until all possible values are computed and returns
 * the number of numbers generated.
 *
 * @return double > 0.0
 */
double n_generated(void);

/**
 * @brief Generates random positive integers
 * with values up to MAX_NUM until all values are generated.
 *
 * This process is repeated @M times and the
 * average and std. dev computed.
 *
 * @param argv[1] M
 * @return EXIT_SUCCESS on successful execution else
 * @return EXIT_FAILURE
 *
 * @see MAX_NUM
 */
int main(int argc, char* argv[argc + 1]) {
    if (argc != 2) {
        fprintf(stderr, "Error: call structure is ./ex3_18 M\n");
        return EXIT_FAILURE;
    }

    register size_t const M = NUMPARSEexit_on_fail(M, argv[1]);

    RAND_SEED_TIME;

    register STATSmeasures sm = STATScalculate_statistics(n_generated, M);

    STATSsummary_print(sm, "===== Results, M = %zu =====", M);

    return EXIT_SUCCESS;
}

double n_generated(void) {
    static bool seen[MAX_NUM];

    for (register size_t i = 0; i < MAX_NUM; i++) seen[i] = false;
    register size_t n_gen = 0;
    register size_t n_seen = 0;
    for (; n_seen < MAX_NUM; n_gen++) {
        register size_t i = RANDUINT(MAX_NUM);
        if (!seen[i]) {
            seen[i] = !seen[i];
            n_seen++;
        }
    }
    n_seen--;    // accounts for the fact we stop when we find them all so
                 // subtract one to get the number before we saw them all.
    return CAST(double) n_gen;
}