/**
 * @file ex2_13.c
 * @author Felix Lempriere
 * @brief Solution to Exercise 2-13 from Chapter 2 of Sedgewick's Algorithms in
 * C.
 *
 * This program efficiently computes ceil(lg(lg(N))) without the use of a
 * library function. The algorithm leverages the mathematical property:
 *
 * 2^(2^i) = 2^(2^(i - 1)) * 2^(2^(i - 1)),
 *
 * to efficiently calculate the next possible term in the sequence.
 *
 * @date 2025-04-07
 * @version 0.1
 * @copyright Copyright (c) 2025
 */
#include "MacroLibrary/Utility.h"

#include <stdio.h>
#include <stdlib.h>
#include <tgmath.h>

/**
 * @brief Maximum value of N for which ceil(lg(lg(N))) is computed.
 */
constexpr size_t MAX_N = 20u;

/**
 * @brief Computes the ceiling of the double logarithm (base 2) of a given
 * number N.
 *
 * @param n Positive integer.
 * 
 * @pre n >= 2.
 */
unsigned int ceil_lglg(size_t const n);

/**
 * @brief Demonstrates the calculation of ceil(lg(lg(N))) using both the custom
 * implementation (ceil_lglg) and the standard mathematical library functions.
 *
 * This function iterates over a range of values from 2 to MAX_N, computes the
 * ceiling of the double logarithm (base 2) of each value using the custom
 * ceil_lglg function, and compares it with the result obtained using the
 * standard math library functions (log2 and ceil). The results are printed
 * to the console for verification and comparison.
 *
 * @return EXIT_SUCCESS upon successful execution of the program.
 */
int main(int argc, char* argv[argc + 1]) {
    for (register size_t i = 2; i <= MAX_N; i++) {
        printf("N: %zu, By approx: %u, By math Library: %Lf\n", i, ceil_lglg(i),
               ceil(log2(log2(CAST(long double) i))));
    }
    return EXIT_SUCCESS;
}

unsigned int ceil_lglg(size_t const n) {
    register size_t lglgN = 0;
    for (register size_t t = 2; t < n; lglgN++, t *= t);
    return CAST(unsigned) lglgN;
}
