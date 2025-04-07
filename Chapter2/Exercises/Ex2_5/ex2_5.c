/**
 * @file ex2_5.c
 * @author Felix Lempriere
 * @brief Solution to Exercise 2-5 from Chapter 2 of Sedgewick's Algorithms in
 * C.
 *
 * This program determines for what values of N the inequality 10Nlg(N) > 2N^2
 * holds true. Newtons method is used to solve the inequality, and the results
 * are printed on stdout.
 *
 * @note We estimate the roots as 2 and 36, based on the analysis of the
 * function. 10*2*lg(2) = 20 2*(2**2) = 8 -> first root < 2 10*32*lg(32) =
 * 320*(5) = 1600 2*(36*36) = 2500+ second root < 36. These initial estimates
 * are then fed into Newton's method.
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
 * @brief Evaluates the function 10xlg(x) - 2x^2.
 *
 * This function represents the inequality being analyzed to determine
 * the range of values for which 10Nlg(N) > 2N^2 holds true.
 *
 * @param x The input value for the function.
 * @return long double The result of the function evaluation.
 */
static inline long double fn(long double const x);
static inline long double quadraticTerm(long double const x);
static inline long double logTerm(long double const x);

/**
 * @brief Computes the two roots of the function 10Nlg(N) - 2N^2 using Newton's
 * method.
 *
 * These roots define the range of values for N where the inequality
 * 10Nlg(N) > 2N^2 holds true. The first root is found starting with an
 * initial guess near the lower bound of the range, and the second root
 * is found starting with an initial guess near the upper bound.
 *
 * The results are printed to stdout in the format:
 * "10Nlg(N) > 2N^2 for <lower_bound> ~< N ~< <upper_bound>".
 *
 * @return EXIT_SUCCESS on successful computation and output.
 */
int main(int argc, char* argv[argc + 1]) {
    long double N_0 = 2.0L;
    long double N_1 = 36.0L;
    N_0 = MATHnewtons_method(fn, N_0);
    N_1 = MATHnewtons_method(fn, N_1);
    printf("10Nlg(N) > 2N^2 for %Lf ~< N ~< %Lf\n", N_0, N_1);

    return EXIT_SUCCESS;
}

static inline long double logTerm(long double const x) {
    return 10.0L * x * log2(x);
}

static inline long double quadraticTerm(long double const x) {
    return 2 * pow(x, 2);
}

static inline long double fn(long double const x) {
    return logTerm(x) - quadraticTerm(x);
}