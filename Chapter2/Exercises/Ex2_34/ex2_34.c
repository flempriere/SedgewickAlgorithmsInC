/**
 * @file ex2_34.c
 * @author Felix Lempriere
 * @brief Solution to Exercise 2-34 from Chapter 2 of Sedgewick's Algorithms in
 * C.
 *
 * This program calculates and displays a table of the values of C_N for
 * 1 <= N <= 32, where C_N is defined recursively as:
 *   C_N = C_(N/2) + 1 for N >= 2, with C_1 = 1.
 *
 * Unlike Exercise 2-33, this program interprets N/2 as ceil(N/2) in the
 * formula. It iterates through values of N from 1 to 32, computes the
 * corresponding C_N values, and outputs the results in a tabular format.
 *
 * @date 2025-04-07
 * @version 0.1
 * @copyright Copyright (c) 2025
 */
#include <stdio.h>
#include <stdlib.h>

/**
 * @brief Maximum value of N for which
 * coefficients will be calculated.
 *
 */
constexpr size_t N = 32u;

/**
 * @brief Calculate the n-th coefficient C_N.
 *
 * Calculates C_N for 1 <= N <= 32, where C_N is defined recursively as:
 *   C_N = C_(N/2) + 1 for N >= 2, with C_1 = 1.
 *N/2 is interpreted as ceil(N/2).
 *
 * @param n The index of the coeefficient to compute. Must be greater than 0.
 * 
 * @pre n > 0.
 *
 * @return The computed value of C_N.
 */
size_t coefficient_N(size_t n);

/**
 * @brief Computes the coefficients C_N for values of n ranging from 1 to 32.
 * where C_N is defined recursively as: C_N = C_(N/2) + 1 for N >= 2, with C_1 =
 * 1 and N/2 is interpreted as ceil(N/2).
 *
 * @return EXIT_SUCCESS on successful execution of the program.
 */
int main(int argc, char* argv[argc + 1]) {
    for (register size_t i = 1; i <= N; i++) {
        printf("n: %zu, C_n: %zu\n", i, coefficient_N(i));
    }
    return EXIT_SUCCESS;
}

size_t coefficient_N(size_t n) {
    register size_t i;
    for (i = 1; n != 1; n = (n + 1) / 2, i++);
    return i;
}
