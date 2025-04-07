/**
 * @file ex2_33.c
 * @author Felix Lempriere
 * @brief Solution to Exercise 2-33 from Chapter 2 of Sedgewick's Algorithms in
 * C.
 *
 * This program calculates and displays a table of the values of C_N for
 * 1 <= N <= 32, where C_N is defined recursively as:
 *   C_N = C_(N/2) + 1 for N >= 2, with C_1 = 1.
 *
 * The program interprets N/2 as floor(N/2) in the formula. It iterates through
 * values of N from 1 to 32, computes the corresponding C_N values, and outputs
 * the results in a tabular format.
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
 * @brief Calculate C_N
 *
 * This function computes the value of C_N for a given input n using an
 * iterative approach. The value of C_N is defined recursively as: C_N = C_(N/2)
 * + 1 for N >= 2, with C_1 = 1.
 *
 * The function interprets N/2 as floor(N/2) in the formula.
 *
 * @param n The input value for which C_N is to be calculated. Must be a
 * positive integer.
 *
 * @pre n > 0
 *
 * @return The computed value of C_N.
 */
size_t coefficient_N(size_t n);

/**
 * @brief Calculate and display the coefficients C_N
 * for values of n ranging from 1 to 32.
 *
 * This function iterates through all integers from 1 to the maximum value of N
 * (defined as 32). For each value of n, it computes the corresponding C_N
 * using the coefficient_N function, which implements the recursive formula
 * C_N = C_(N/2) + 1 for N >= 2, with C_1 = 1. The results are then printed
 * in a tabular format, showing the value of n alongside its computed C_N.
 *
 * @return EXIT_SUCCESS upon successful execution of the program.
 */
int main(int argc, char* argv[argc + 1]) {
    for (register size_t i = 1; i <= N; i++) {
        printf("n: %zu, C_n: %zu\n", i, coefficient_N(i));
    }
    return EXIT_SUCCESS;
}

size_t coefficient_N(size_t n) {
    register size_t i;
    for (i = 1; n != 1; n /= 2, i++);
    return i;
}
