/*
Exercise 3_2

Test the random number generator on your system by generating
N random integers from 0 to r-1 with rand() % r and computing
the avg and std. dev. for r = 10, 100, 1000, N = 10^3, 10^4,
10^5, 10^6.
*/
#include <tgmath.h>
#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include "num.h"

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