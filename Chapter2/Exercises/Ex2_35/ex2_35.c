/**
 * @file ex2_35.c
 * @author Felix Lempriere
 * @brief Solution to Exercise 2-35 from Chapter 2 of Sedgewick's Algorithms in
 * C.
 *
 * This program calculates and displays a table of the values of C_N for
 * 1 <= N <= 32, where C_N is defined recursively as:
 *   C_N = C_(N/2) + N for N >= 2, with C_1 = 0.
 *
 * The program interprets N/2 as ceil(N/2) in the formula. It iterates through
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
 * @brief Calculate the value of the coefficient C_N.
 *
 * The Nth coefficient is given by the formula:
 * C_N = C_(N/2) + N for N >= 2, with C_1 = 0.
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
 * for values of n ranging from 1 to 32.
 *
 * This function iterates through all integers n in the range [1, 32],
 * computes the corresponding coefficient C_N using the recursive formula:
 *   C_N = C_(N/2) + N for N >= 2, with C_1 = 0,
 * and prints the results in a tabular format.
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
    register size_t sum = 0;
    for (register size_t i = n; i != 1; i = (i + 1) / 2) { sum += i; }
    return sum;
}
