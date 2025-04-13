/**
 * @file ex2_40.c
 * @author Felix Lempriere
 * @brief Solution to Exercise 2-40 from Chapter 2 of Sedgewick's Algorithms in
 * C.
 *
 * This program calculates and displays a table of the values of C_N for
 * 1 <= N <= 32, and N = 2^i for some integer i, where C_N is defined
 * recursively as: C_N = C_(N/2) + N^2 for N >= 2, with C_1 = 0.
 *
 * We compare a direct computation from the recurance with a "solved" version
 * of the recurrence.
 *
 * @date 2025-04-13
 * @version 0.1
 * @copyright Copyright (c) 2025
 */
#include "MacroLibrary/Utility.h"

#include <stdio.h>
#include <stdlib.h>
/**
 * @brief Maximum value of N for which
 * coefficients will be calculated.
 *
 */
constexpr size_t N = 32u;

size_t coefficient_N_geometric(size_t n);
/**
 * @brief Calculate the value of the coefficient C_N.
 *
 * The Nth coefficient is given by the formula:
 * C_N = C_(N/2) + N^2 for N >= 2, with C_1 = 0.
 *
 * @param n The index of the coefficient to compute. Must be greater than 0.
 *
 * @pre n > 0.
 *
 * @return The computed value of C_N.
 */
size_t coefficient_N(size_t n);

/**
 * @brief Calculate and display the coefficients C_N
 * for values of n that are poweres of 2 ranging from 1 to 32.
 *
 * This function iterates through all integers n in the range [1, 32] that are
 * powers of two, computes the corresponding coefficient C_N using the recursive
 * formula: C_N = C_(N/2) + N^2 for N >= 2, with C_1 = 0, and prints the results
 * in a tabular format.
 *
 * @return EXIT_SUCCESS upon successful execution of the program.
 */
int main(int argc, char* argv[argc + 1]) {
    for (register size_t i = 1; i <= N; i <<= 1u) {
        printf("n: %zu, By formula: %zu, C_n: %zu\n", i, coefficient_N_geometric(i),coefficient_N(i));
    }
    return EXIT_SUCCESS;
}

size_t coefficient_N_geometric(size_t n) {
    register long double const ndbl = CAST(n);
    register long double const nsqrd = ndbl * ndbl;
    return CAST(size_t) ((4 * nsqrd) * (1 - 1.0/nsqrd) / 3);
}

size_t coefficient_N(size_t n) {
    register size_t sum;
    for (sum = 0; n != 1; sum += n*n, n /= 2);
    return sum;
}
