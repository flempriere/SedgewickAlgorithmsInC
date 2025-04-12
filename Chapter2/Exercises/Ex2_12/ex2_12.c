/**
 * @file ex2_12.c
 * @author Felix Lempriere
 * @brief Solution to Exercise 2-12 from Chapter 2 of Sedgewick's Algorithms in
 * C.
 *
 * This program implements an algorithm to compute harmonic numbers using the
 * standard math library. The harmonic number H_n is defined as the sum of the
 * reciprocals of the first n natural numbers:
 *
 * H(n) = 1 + 1/2 + 1/3 + ... + 1/n.
 * The harmonic number H_n is approximated as:
 * H_n ≈ ln(N) + 0.57721 (Euler-Mascheroni constant) + 1/(12N).
 *
 *
 * @date 2025-04-07
 * @version 0.1
 * @copyright Copyright (c) 2025
 */
#include "MacroLibrary/Mathematics.h"
#include "MacroLibrary/Utility.h"

#include <stdio.h>
#include <stdlib.h>
#include <tgmath.h>

/**
 * @brief Defines the number of harmonic numbers to compute.
 *
 */
constexpr size_t N_HARMONICS = 20u;

/**
 * @brief Approximates the n-th harmonic number
 * using the formula
 *
 * H_n ≈ ln(N) + 0.57721 (Euler-Mascheroni constant) + 1/(12N).
 *
 * @param x The order of the harmonic number to compute.
 *
 * @pre x > 0.
 *
 * @return The approximated harmonic number as a long double.
 */
static inline long double Harmonic_N(size_t const x);

/**
 * @brief Calculate the first N harmonics using a fast approximation.
 *
 * This function computes the first N harmonic numbers, where N is defined
 * by the constant @N_HARMONICS.
 *
 * @return Returns EXIT_SUCCESS upon successful computation of the harmonic
 * numbers.
 */
int main(int argc, char* argv[argc + 1]) {
    for (register size_t i = 1; i <= N_HARMONICS; i++) {
        printf("N: %zu, H_n : %Lf\n", i, Harmonic_N(i));
    }
    return EXIT_SUCCESS;
}

static inline long double Harmonic_N(size_t const x) {
    if (x == 1)
        return 1.0L;
    else if (x == 2)
        return 1.5L;

    return log(CAST(long double) x) + MATHEULER_CONSTANT + 1.0L / (12.0L * x);
}
