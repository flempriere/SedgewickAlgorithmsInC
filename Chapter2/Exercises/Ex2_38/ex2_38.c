/**
 * @file ex2_38.c
 * @author Felix Lempriere
 * @brief Calculates the values of the coefficient C_N =  2C_(N/2) + N for 1 <=
 * N <= 32. With C_1 = 0.
 *
 * Repeats the exercise, interpreting N/2 as ceil(N/2), floor(N/2) and 2C_(N/2)
 * = C_ceil(N/2) + C_floor(N/2)
 * @version 0.1
 * @date 2025-04-07
 *
 * @copyright Copyright (c) 2025
 *
 */
#include <stdio.h>
#include <stdlib.h>

constexpr size_t N = 32u;

/**
 * @brief Calculates the values of the coefficient C_N =  2C_(N/2) + N for 1 <=
 * N <= 32. With C_1 = 0. Makes N/2 equal to ceil(N/2).
 *
 * @param n Index of the coefficient to calculate.
 *
 * @return The value of the coefficient.
 */
size_t coefficient_N_ceil(size_t n);

/**
 * @brief Calculates the values of the coefficient C_N =  2C_(N/2) + N for 1 <=
 * N <= 32. With C_1 = 0. Makes N/2 equal to floor(N/2).
 *
 * @param n Index of the coefficient to calculate.
 *
 * @return The value of the coefficient.
 */
size_t coefficient_N_floor(size_t n);

/**
 * @brief Calculates the values of the coefficient C_N =  2C_(N/2) + N for 1 <=
 * N <= 32. With C_1 = 0. Uses a hybrid 2C_(N/2) = C_(floor(N/2)) +
 * C_(ceil(N/2)).
 *
 * @param n Index of the coefficient to calculate.
 *
 * @return The value of the coefficient.
 */
size_t coefficient_N_hybrid(size_t n);

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
        printf("N: %zu\tC_floor(N): %zu\tC_ceil(N): %zu\tC_hybrid: %zu\n", i,
               coefficient_N_floor(i), coefficient_N_ceil(i),
               coefficient_N_hybrid(i));
    }
    return EXIT_SUCCESS;
}

size_t coefficient_N_ceil(size_t n) {
    if (n == 1) return 0;
    register size_t sum = n;
    n = (n + 1) / 2;
    for (register size_t i = 0; n != 1; n = (n + 1) / 2, i++) {
        sum += (2ull << i) * n;
    }
    return sum;
}

size_t coefficient_N_floor(size_t n) {
    if (n == 1) return 0;
    register size_t sum = n;
    n /= 2;
    for (register size_t i = 0; n != 1; n /= 2, i++) { sum += (2ull << i) * n; }
    return sum;
}

size_t coefficient_N_hybrid(size_t n) {
    if (n == 1) return 0;
    return coefficient_N_hybrid(n / 2) + coefficient_N_hybrid((n + 1) / 2) + n;
}