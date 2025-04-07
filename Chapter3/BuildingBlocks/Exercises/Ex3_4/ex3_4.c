/**
 * @file Ex3-4
 * @author Felix Lempriere
 * @brief Solution to Exercise 3.4.
 * 
 * Compares the random number generation strategies used in Exercise 3.2
 * and Exercise 3.3.
 *
 * @date 2025-04-07
 * @version 0.1
 *
 * @copyright Copyright (c) 2025
 */

#include "MacroLibrary/Random.h"
#include "MacroLibrary/Statistics.h"
#include "MacroLibrary/Utility.h"
#include "include/Number_v2.h"

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
 * @brief Number of test cases for R. Each successive test case is the square
 * of the previous test case.
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
constexpr Number R_INIT = 2u;


/**
 * @brief Size of the results array.
 * 
 */
constexpr size_t RESULTS_ARR_SIZE = N_CASES * R_CASES;

/**
 * @brief Wraps the random number by modulus function in the interface
 * for the calculate_statistics function from Statistics.h.
 *
 * @param d
 * @return double
 */
static inline double rand_mod_to_double(double const d);

/**
 * @brief Wraps the random number by truncation function in the interface
 * for calculate_statistics function from Statistics.h.
 *
 * @param d
 * @return double
 */
static inline double rand_trunc_to_double(double const d);

/**
 * @brief Calculate the statistics using a given rng. Bool flag notes if
 * we want to add this to our stats array or subtract it if we want to
 * calculate the difference.
 *
 * @param rng Number generation function.
 * @param results array of STATSmeasures to store the results in.
 * @param subtract Marks if we subtract the results from existing statistics
 * in the array.
 */
void run_rng_experiment(double rng(double ub),
                        STATSmeasures results[static RESULTS_ARR_SIZE],
                        bool subtract);
/**
 * @brief Test the random number generator
 * using both the methods given in Exercise 3.2
 * and Exercise 3.3.
 *
 * Starts and R = R_INIT, and N = N_INIT, and
 * each successive N case is 10x larger. Each
 * successive R case is squared.
 *
 * @return EXIT_SUCCESS
 */
int main(int argc, char* argv[argc + 1]) {
    register size_t n = N_INIT;
    register Number r = R_INIT;

    STATSmeasures resA[RESULTS_ARR_SIZE];

    RAND_SEED_TIME;

    printf("Testing rand() with modulus\n");
    run_rng_experiment(rand_mod_to_double, resA, false);

    printf("Testing rand() via rescaled doubles\n");
    run_rng_experiment(rand_trunc_to_double, resA, true);

    printf("Comparing the difference: \n");

    n = N_INIT;
    for (register size_t i = 0; i < N_CASES; i++, n *= 10) {
        r = R_INIT;
        for (register size_t j = 0; j < R_CASES; j++, r *= r) {
            STATSsummary_print(resA[ARRAY_2D_IDX(i, j, R_CASES)],
                               "Difference for N: %zu, R: %u", n, r);
        }
    }
    return EXIT_SUCCESS;
}

void run_rng_experiment(double rng(double ub),
                        STATSmeasures results[static RESULTS_ARR_SIZE],
                        bool subtract) {
    register size_t n = N_INIT;
    for (register size_t i = 0; i < N_CASES; n *= 10, i++) {
        register Number r = R_INIT;

        for (register size_t j = 0; j < R_CASES; r *= r, j++) {
            register STATSmeasures sm = STATScalculate_statistics(rng, n, r);

            STATSsummary_print(sm, "Results for N: %zu, R: %u", n, r);

            size_t idx = ARRAY_2D_IDX(i, j, R_CASES);
            if (subtract) {
                results[idx] = STATSmeasures_difference(results[idx], sm);
            } else {
                results[idx] = sm;
            }
        }
        printf("\n");
        r = R_INIT;
    }
}

static inline double rand_mod_to_double(double const d) {
    return CAST(double) NUMBERrandom_modulus(CAST(Number) d);
}

static inline double rand_trunc_to_double(double const d) {
    return CAST(double) NUMBERrandom_truncate(CAST(Number) d);
}