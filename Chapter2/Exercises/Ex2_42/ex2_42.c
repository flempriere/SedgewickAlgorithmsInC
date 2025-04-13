/**
 * @file ex2_42.c
 * @author Felix Lempriere
 * @brief Solution to Exercise 2-42 from Chapter 2 of Sedgewick's Algorithms in
 * C.
 *
 * Compares the coefficients for the recurrences
 * C_{N} = 2C_{N/2}
 * C_{N} = 4C_{N/2}
 * C_{N} = 8C_{N/2}
 *
 * The generalised solution is
 * C_{N} = log_{a}\left(N\right) + 1
 * Where alpha is the dividing factor in the recurrence and N is a power
 * of alpha.
 *
 * @version 0.1
 * @date 2025-04-13
 *
 * @copyright Copyright (c) 2025
 *
 */

#include <stdio.h>
#include <stdlib.h>

/**
 * @brief Calculates the n-th coefficient of C_n for the reccurence,
 * C_N = alpha C_{N/2}
 * where alpha = 2^i
 *
 * The general solution of such a reccurence is
 * C_N = alpha^lg(N) in the general case of alpha which reduces to
 * C_N = N^i where alpha = 2^i.
 * @param n Value to compute the coefficient of.
 * @param i exponent i, alpha is interpreted as 2^i.
 * @return size_t The coefficient C_N.
 */
size_t coefficient_N_alpha_is_two_i(size_t n, size_t i) {
    register size_t mul = 1;
    for (; i; mul *= n, i--);
    return mul;
}

/**
 * @brief Compares the coefficients generated by the recurrences
 * C_{N} = 2C_{N/2}
 * C_{N} = 4C_{N/2}
 * C_{N} = 8C_{N/2}
 * Using the generalised solution:
 *      C_{N} = alpha^log(N)
 * Which is reduced to the specialised case
 *     C_{N} = N^i
 * when alpha = 2^i.
 * For N = 1 <= N <= 32.
 *
 * The results are printed in a tabular format.
 * @param argc
 * @param argv
 * @return EXIT_SUCCESS on successful exectution.
 */
int main(int argc, char* argv[argc + 1]) {
    /**
     * @brief Largest value of N to compute the coefficient of.
     *
     */
    constexpr size_t N = 32u;

    for (register size_t i = 1; i <= N; i++) {
        printf("N: %4zu\t C_{N}^2:  %4zu\tC_{N}^4: %4zu\tC_{N}^8: %4zu\n", i,
               coefficient_N_alpha_is_two_i(i, 1),
               coefficient_N_alpha_is_two_i(i, 2),
               coefficient_N_alpha_is_two_i(i, 3));
    }

    return EXIT_SUCCESS;
}