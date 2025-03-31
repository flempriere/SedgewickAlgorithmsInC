/*
Exercise 3.18

Empirically determine the number of random positive integers less than 1000
that you can expect to generate before getting a repeated value.

This implementation repeats the experiment M times where M is a command line
argument.

*/
#include "../../../../MacroLibrary/NumberParse.h"
#include "../../../../MacroLibrary/Random.h"
#include "../../../../MacroLibrary/Statistics.h"

#include <stdio.h>
#include <stdlib.h>
#include <tgmath.h>

/**
 * @brief Exclusive upper bound
 * for maximum number we can generate
 *
 */
constexpr size_t MAX_NUM = 1000u;

/**
 * @brief Returns the number of random positive integers generated before
 * a repeat.
 *
 * @return double
 */
double n_generated(void);
/**
 * @brief Generates random positive integers
 * up to MAX_NUM until a value is repeated.
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
    STATSsummary_print(sm, "===== Results for M = %zu =====", M);
    return EXIT_SUCCESS;
}

double n_generated(void) {
    static size_t seen[MAX_NUM];
    for (register size_t i = 0; i < MAX_NUM; i++) seen[i] = 0;
    register size_t n_gen = 0;
    for (;; n_gen++) {
        register size_t i = RANDuint(MAX_NUM);
        if (seen[i]++) { break; }
    }
    return CAST(double) n_gen;
}