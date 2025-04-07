/**
 * @file program3_1_function_definition.c
 * @author Felix Lempriere
 * @brief Program 3.1: Demonstration of function declaration and definition.
 *
 * This program demonstrates the separation of a function declaration and its
 * definition. The function `lg(size_t x)` computes the base-2 logarithm of an
 * integer argument. The program tabulates values of N, lg(N), and Nlg(N) for
 * N = 10, 100, 1000, ..., up to 10^6.
 *
 * @date 2025-04-07
 * @version 0.1
 *
 * @copyright Copyright (c) 2025
 */
#include <stdio.h>
#include <stdlib.h>

/**
 * @brief Computes the base-2 logarithm (lg) of an integer.
 *
 * @param x Integer to compute lg(x). Must be greater than 0.
 *
 * @pre x > 0.
 *
 * @return lg(x).
 */
size_t lg(size_t n);

/**
 * @brief Tabulates the values of N, log base 2 of N (lg(N)), and the product of
 * N and lg(N) for N = 10, 100, 1000, ..., up to 10^6.
 *
 * @return EXIT_SUCCESS upon successful execution of the program.
 */
int main(int argc, char* argv[argc + 1]) {
    register size_t N = 10u;
    for (register size_t i = 1; i <= 6; i++, N *= 10) {
        printf("%7zu %2zu %9zu\n", N, lg(N), N * lg(N));
    }
    return EXIT_SUCCESS;
}

size_t lg(size_t n) {
    register size_t i;
    for (i = 0; n > 0; i++, n /= 2);
    return i;
}