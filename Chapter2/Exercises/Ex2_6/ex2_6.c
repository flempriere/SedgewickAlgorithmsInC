/**
 * @file ex2_6.c
 * @author Felix Lempriere
 * @brief Solution to Exercise 2-6 from Chapter 2 of Sedgewick's Algorithms in
 * C.
 *
 * This program determines the range of values for N where the inequality
 * N^(3/2) lies between N(lg(N)^2)/2 and 2N(lg(N)^2). The analysis involves
 * identifying the crossover points of the functions using Newton's method.
 *
 * @note For N < 1, N^(3/2) is a small positive value. At N = 1, the functions
 * begin to interact. The first crossover point is near N = 1. For larger N,
 * the second crossover point is estimated around N = 4, based on calculations:
 * - For N = 4:
 *   - N^(3/2) = 8
 *   - N(lg(N)^2)/2 = 8
 *   - 2N(lg(N)^2) = 16
 *
 * @date 2025-04-07
 * @version 0.1
 * @copyright Copyright (c) 2025
 */

#include "MacroLibrary/Mathematics.h"

#include <stdio.h>
#include <stdlib.h>
#include <tgmath.h>

/**
 * @brief Computes the difference: N(lg(N)^2)/2 - N^(3/2)
 *
 * @param x Input value
 * @return long double Result of the computation
 */
static inline long double fn1(long double const x);

/**
 * @brief Computes the value of 2N(lg(N)^2).
 *
 * @param x Input value
 * @return long double Result of the computation
 */
static long double fn2(long double const x);

/**
 * @brief Identifies the intervals of N where the inequality
 * N^(3/2) lies between N(lg(N)^2)/2 and 2N(lg(N)^2).
 *
 * This involves finding the crossover points of the functions
 * N^(3/2), N(lg(N)^2)/2, and 2N(lg(N)^2) using Newton's method.
 *
 * @return EXIT_SUCCESS upon successful completion of the program.
 */
int main(int argc, char* argv[argc + 1]) {
    register long double const N_0 = 1.0L;
    register long double const N_1 = 8.0L;

    register long double const f1N_0 = MATHnewtons_method(fn1, N_0);
    register long double const f1N_1 = MATHnewtons_method(fn1, N_1);

    printf("N^(3/2) > Nlg(N)^2/2 for %Lf ~< N ~< %Lf\n", f1N_0, f1N_1);

    register long double const f2N_0 = MATHnewtons_method(fn2, N_0);
    register long double const f2N_1 = MATHnewtons_method(fn2, N_1);

    printf("N^(3/2) > 2Nlg(N)^2 for %Lf ~< N ~< %Lf\n", f2N_0, f2N_1);

    printf("N^(3/2) between Nlg(N)^2/2 and 2Nlg(N)^2"
           " in the intervals:\n(%Lg, %Lg) and (%Lg, %Lg)\n",
           f1N_0, f2N_0, f2N_1, f1N_1);

    return EXIT_SUCCESS;
}

static inline long double fn1(long double const x) {
    return x * pow(log2(x), 2) / 2.0 - pow(x, 3.0L / 2.0L);
}

static inline long double fn2(long double const x) {
    return 2.0 * x * pow(log2(x), 2) - pow(x, 3.0L / 2.0L);
}