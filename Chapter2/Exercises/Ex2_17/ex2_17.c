/**
 * @file ex2_17.c
 * @author Felix Lempriere
 * @brief Solution to Exercise 2-17 from Chapter 2 of Sedgewick's Algorithms in
 * C.
 *
 * This program provides a simple expression for calculating the floor of the
 * base-2 logarithm of the Fibonacci number F_n, denoted as floor(lg(F_n)).
 *
 * The Fibonacci number approximation is defined as:
 * F_n = round(phi^N / sqrt(5)),
 * where phi is the golden ratio (approximately 1.618).
 *
 * The base-2 logarithm of F_n can be expressed as:
 * lg(F_n) = lg(phi^N) - lg(sqrt(5))
 *         = N * lg(phi) - 0.5 * lg(5).
 *
 * For small values of n (n = 0, 1, 2, 3), an exact table is used. For invalid
 * inputs or cases where the result is undefined, the program returns `SIZE_MAX`
 * to signify negative infinity (-inf).
 *
 * @date 2025-04-07
 * @version 0.1
 * @copyright Copyright (c) 2025
 */
#include "MacroLibrary/Utility.h"

#include <assert.h>
#include <limits.h>
#include <stdio.h>
#include <stdlib.h> 
#include <tgmath.h>

/**
 * @brief Maximum Fibonacci number index to compute.
 */
constexpr size_t MAX_FIB = 93u;

/**
 * @brief Calculates the N-th Fibonacci number.
 *
 * This function computes the N-th number in the Fibonacci sequence,
 * where the sequence is defined as:
 *   F(0) = 0,
 *   F(1) = 1,
 *   F(n) = F(n-1) + F(n-2) for n > 1.
 *
 * @param n The position (0-based) in the Fibonacci sequence to calculate.
 *
 * @note Overflows for n > 93.
 * @return The N-th Fibonacci number.
 */
static inline size_t fibonacci_number(size_t const n);

/**
 * @brief Approximates the base-2 logarithm of the Nth Fibonacci number
 * (lg(F_N)).
 *
 * @param n The index of the Fibonacci number for which the logarithm is to be
 * approximated. Must be a non-negative integer.
 *
 * @pre n > 0.
 * @return The approximate value of lg(F_N).
 */
static inline unsigned int approx_floor_lg_fib(size_t const n);

/**
 * @brief Calculates the exact value of the base-2 logarithm of the Nth
 * Fibonacci number (lg(F_N)).
 *
 * @param n The index of the Fibonacci number for which the logarithm is to be
 * calculated. Must be a non-negative integer.
 * @return The exact value of lg(F_N) as a double.
 */
static inline unsigned int exact_floor_lg_fib(size_t const n);

/**
 * @brief Calculates the floor of the base-2 logarithm of the n-th Fibonacci
 * Number comparing an approximation vs an exact calculation.
 *
 * This function computes the mathematical operation floor(log2(F_N)),
 * where F_N is a given input. The implementation ensures precision
 * and simplicity in the calculation.
 *
 * @return int Returns EXIT_SUCCESS upon successful execution.
 */
int main(int argc, char* argv[argc + 1]) {
    for (register size_t i = 0; i <= MAX_FIB; i++) {
        printf("N: %zu, F_n: %zu, approx: %u, exact: %u\n", i,
               fibonacci_number(i), approx_floor_lg_fib(i),
               exact_floor_lg_fib(i));
    }
    return EXIT_SUCCESS;
}

static inline size_t fibonacci_number(size_t const n) {
    // cache for calculated values
    static size_t FIB_NUM[MAX_FIB + 1] = { 0, 1 };
    static size_t MAX_N = 1;    // max calculated fib num;

    while (++MAX_N <= n) {
        FIB_NUM[MAX_N] = FIB_NUM[MAX_N - 1] + FIB_NUM[MAX_N - 2];
    }
    --MAX_N;
    return FIB_NUM[n];
}

static inline unsigned int approx_floor_lg_fib(size_t const n) {
    constexpr long double GOLDEN_RATIO = 1.61803L;
    static unsigned int exact_sln[] = { UINT_MAX, 0, 0, 1 };
    if (n <= 3) return exact_sln[n];

    return CAST(unsigned int) floor(n * log2(GOLDEN_RATIO) - 0.5L * log2(5.0L));
}

static inline unsigned int exact_floor_lg_fib(size_t const n) {
    return CAST(unsigned int)
        floor(log2(CAST(long double) fibonacci_number(n)));
}
