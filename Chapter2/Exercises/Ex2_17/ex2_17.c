/*
Give a simple expression for floor(lg(F_n))

F_n = round(phi^N/sqrt(5)) -> goes up or down by 0.5 small term
lg(F_n) = lg(phi^N) - lg(sqrt(5))
= N*lg(phi) - 0.5*lg(5)

This program will overflow on the calculating the 94th Fibonnaci number
with a 64bit size_t type.

use exact table for n = 0, 1, 2, 3 and return SIZE_MAX to signify -inf.
*/

#include "MacroLibrary/Utility.h"

#include <limits.h>
#include <stdio.h>
#include <stdlib.h>
#include <tgmath.h>

/**
 * @brief Largest order Fibonnaci
 * number to calculate.
 */
constexpr size_t MAX_INT = 50u;

/**
 * @brief Calculates the N-th Fibonacchi number
 *
 */
unsigned long long FIBONACCHI_NUMBER(size_t const n);

/**
 * @brief approximates lg(F_N)
 *
 */
unsigned int APPROX_FLOOR_LG_FIB(size_t const n);

/**
 * @brief Calculates lg(F_N) exactly.
 *
 */
unsigned int EXACT_FLOOR_LG_FIB(size_t const n);

/**
 * @brief Calculates floor(lg(F_N)) using
 * an exact and simple approach.
 *
 * @return EXIT_SUCCESS
 */
int main(int argc, char* argv[argc + 1]) {
    for (register size_t i = 1; i < MAX_INT; i++) {
        printf("N: %zu, F_n: %llu, approx: %u, exact: %u\n", i,
               FIBONACCHI_NUMBER(i), APPROX_FLOOR_LG_FIB(i),
               EXACT_FLOOR_LG_FIB(i));
    }
    return EXIT_SUCCESS;
}

unsigned long long FIBONACCHI_NUMBER(size_t const n) {
    // cache for calculated values
    static size_t FIB_NUM[MAX_INT] = { 0, 1 };
    static size_t MAX_N = 1;    // max calculated fib num;

    while (++MAX_N <= n) {
        FIB_NUM[MAX_N] = FIB_NUM[MAX_N - 1] + FIB_NUM[MAX_N - 2];
    }
    --MAX_N;
    return FIB_NUM[n];
}

unsigned int APPROX_FLOOR_LG_FIB(size_t const n) {
    constexpr long double GOLDEN_RATIO = 1.61803L;
    static unsigned int exact_sln[] = { INT_MAX, 0, 0, 1 };
    if (n <= 3) return exact_sln[n];

    return CAST(unsigned int) floor(n * log2(GOLDEN_RATIO) - 0.5L * log2(5.0L));
}

unsigned int EXACT_FLOOR_LG_FIB(size_t const n) {
    return CAST(unsigned int)
        floor(log2(CAST(long double) FIBONACCHI_NUMBER(n)));
}
