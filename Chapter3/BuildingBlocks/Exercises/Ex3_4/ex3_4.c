/*
Exercise 3_4 implementation utilising num.c and num.h from Program 3.2
based on the implementations in exercise 3.2 and exercise 3.3
*/
#include "../../../../MacroLibrary/Random.h"
#include "../../../../MacroLibrary/Utility.h"
#include "Number_v2.h"

#include <stdio.h>
#include <stdlib.h>
#include <tgmath.h>

/**
 * @brief Number of test cases for N
 *
 */
constexpr size_t N_CASES = 4u;
/**
 * @brief Number of test cases for r
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
    RAND_SEED_TIME;

    printf("Testing rand() with modulus\n");
    for (register size_t i = 0; i < N_CASES;
         n *= 10, i++) {    // iterate over N values
        for (register size_t j = 0; j < R_CASES;
             r *= r, j++) {    // iterate over r values
            register double m1 = 0.0;
            register double m2 = 0.0;
            register Number x;
            for (register size_t k = 0; k < n; k++) {
                x = NUMBERrandom_modulus(r);
                m1 += (x) / CAST(double) n;
                m2 += (CAST(double) x * x) / CAST(double) n;
            }
            printf("Results for N: %zu, R: %u\n", n, r);
            printf("       Average: %f\n", m1);
            printf("Std. deviation: %f\n", sqrt(m2 - m1 * m1));
        }
        printf("\n");
        r = R_INIT;
    }
    n = N_INIT;

    printf("Testing rand() via rescaled doubles\n");
    for (register size_t i = 0; i < N_CASES;
         n *= 10, i++) {    // iterate over N values
        for (register size_t j = 0; j < R_CASES;
             r *= r, j++) {    // iterate over r values
            register double m1 = 0.0;
            register double m2 = 0.0;
            register Number x;
            for (register size_t k = 0; k < n; k++) {
                x = NUMBERrandom_truncate(r);
                m1 += (x) / CAST(double) n;
                m2 += ((double) x * x) / CAST(double) n;
            }
            printf("Results for N: %zu, R: %u\n", n, r);
            printf("       Average: %f\n", m1);
            printf("Std. deviation: %f\n", sqrt(m2 - m1 * m1));
        }
        printf("\n");
        r = R_INIT;
    }

    return EXIT_SUCCESS;
}