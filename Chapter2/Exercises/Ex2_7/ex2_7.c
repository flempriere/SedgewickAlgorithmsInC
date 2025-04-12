/**
 * @file ex2_7.c
 * @author Felix Lempriere
 * @brief Solution to Exercise 2-7 from Chapter 2 of Sedgewick's Algorithms in
 * C.
 *
 * This program determines the range of values for N where the inequality
 * 2N*H_n - N < Nlg(N) + 10N holds, where H_n is the n-th harmonic number.
 * Newtons method is used to solve the inequality.
 *
 * The harmonic number H_n is approximated as:
 * H_n ≈ ln(N) + 0.57721 (Euler-Mascheroni constant) + 1/(12N).
 *
 * Analysis:
 * We estimate the root of 2N*H_n - N - (Nlg(N) + 10(N)) as
 * - 2N*H_n - N ≈ 2Nln(N) + N - N = 2Nln(N).
 * - The inequality becomes approximately:
 *   2Nln(N) < Nlg(N) + 10N.
 * - Simplifying further:
 *   Nln(N) < 10N.
 * - ln(N) ≈ 10 when N ≈ 2^10.
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
 * @brief Evaluates the expression 2N*H_n - N - (NlgN + 10N).
 *
 * @param x Input value for the function.
 * @return long double Result of the evaluation.
 */
static inline long double fn(long double const x);

/**
 * @brief Determines the range of values for N where the inequality
 * 2N*H_n - N < Nlg(N) + 10N holds.
 *
 * This function uses Newton's method to approximate the roots of the function
 * 2N*H_n - N - (Nlg(N) + 10N), which represents the boundary of the inequality.
 * The results are printed as the range of N values satisfying the condition.
 *
 * @return EXIT_SUCCESS on successful execution.
 */
int main(int argc, char* argv[argc + 1]) {
    long double N_0 = 0.0L;
    long double N_1 = 2e+10L;
    N_0 = MATHnewtons_method(fn, N_0);
    N_1 = MATHnewtons_method(fn, N_1);
    printf("solution: %Lf ~< N ~< %Lf\n", N_0, N_1);

    return EXIT_SUCCESS;
}

/**
 * @brief Computes the nth harmonic number.
 *
 * The nth harmonic number is defined as the sum of the reciprocals of the first
 * n natural numbers: H(n) = 1 + 1/2 + 1/3 + ... + 1/n.
 *
 * @note This function uses as approximation to calculate the nth harmonic
 * number: H(n) ≈ ln(n) + 0.57721 + 1/(12n).
 *
 * @param x Index of the Harmonic number ( > 0).
 * @return The nth harmonic number as a long double.
 */
static inline long double n_harmonic(long double const x) {
    return log(x) + MATHEULER_CONSTANT + 1.0L / (12.0L * x);
}

/**
 * @brief Evaluates the expression 2N*H_n - N - (NlgN + 10N).
 *
 * This function is fed into Newton's Method to evaluate the inequality.
 *
 * @param x input value to the function.
 * @return long double Result of the evaluation.
 */
static long double fn(long double const x) {
    return 2 * x * n_harmonic(x) - 11 * x - x * log2(x);
}