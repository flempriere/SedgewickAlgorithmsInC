/*
Exercise 3_2

Test the random number generator on your system by generating
N random integers from 0 to r-1 with rand() % r and computing
the avg and std. dev. for r = 10, 100, 1000, N = 10^3, 10^4,
10^5, 10^6.
*/
#include "../../../../MacroLibrary/Random.h"
#include "../../../../MacroLibrary/Utility.h"
#include "src/NumberInt.h"

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
constexpr unsigned int R_INIT = 10u;

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

            register double m1 = 0.0;
            register double m2 = 0.0;

            for (register size_t k = 0; k < n; k++) {
                register Number x = NUMBERrandom(r);
                m1 += x / CAST(double) n;
                m2 += (CAST(double) x * x) / CAST(double) n;
            }
            printf("Results for N: %zu, R: %d\n", n, r);
            printf("       Average: %f\n", m1);
            printf("Std. deviation: %f\n", sqrt(m2 - m1 * m1));
        }
        printf("\n");
        r = R_INIT;
    }

    return EXIT_SUCCESS;
}