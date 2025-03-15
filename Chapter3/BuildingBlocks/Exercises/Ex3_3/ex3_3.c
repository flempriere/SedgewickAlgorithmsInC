/*
Exercise 3.3

Test the random number generator ny generating N
random numbers of type double between 0 and 1
and transforming to them to integers between 0 and r - 1
by multiplying by r and truncating.

Calc. avg, std.dev and use the same r and N cases
as Exercise 3.2
*/
#include <tgmath.h>
#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include "../Ex3_2/num.h"

/**
 * @brief Number of test cases for N
 * 
 */
#define N_CASES 4
/**
 * @brief Number of test cases for r
 * 
 */
#define R_CASES 3

/**
 * @brief Starting value for N
 * 
 */
#define N_INIT 10000

/**
 * @brief Starting value for R
 * 
 */
#define R_INIT 10

/**
 * @brief Test the random number generator by
 * generating doubles between 0 and 1 using
 * rand() then expanding to integers in the interval
 * 0 and r - 1 by multiplying by r and truncating.
 * 
 * Generates N times and compute the avg
 * and std. dev.
 * 
 * Starts and R = R_INIT, and N = N_INIT, and
 * each successive case is 10x larger.
 * 
 * @return EXIT_SUCCESS
 */
int main(int argc, char* argv[argc + 1]) {

    int n = N_INIT;
    int r = R_INIT;
    srand(time(nullptr));

    for (size_t i = 0; i < N_CASES; n *= 10, i++) { //iterate over N values
        for (size_t j = 0; j < R_CASES; r *= 10, j++) { //iterate over r values
            double m1 = 0.0;
            double m2 = 0.0;
            Number x;
            for (size_t k = 0; k < n; k++) {
                x = randNum(r);
                m1 += ((double) x)/ n;
                m2 += ((double) x*x)/ n;
            }
            printf("Results for N: %d, R: %d\n", n, r);
            printf("       Average: %f\n", m1);
            printf("Std. deviation: %f\n", sqrt(m2 - m1*m1));
        }
        printf("\n");
        r = R_INIT;
    }

    return EXIT_SUCCESS;
}