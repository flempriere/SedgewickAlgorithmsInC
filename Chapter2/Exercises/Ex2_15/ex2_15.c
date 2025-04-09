/**
 * @file ex2_15.c
 * @author Felix Lempriere
 * @brief Demonstrates the growth rate of the number of digits in the
 * binary representation of the integer truncation of lg(N!).
 *
 * @version 0.1
 * @date 2025-04-10
 *
 * @copyright Copyright (c) 2025
 *
 */

#include "MacroLibrary/Utility.h"

#include <stdio.h>
#include <stdlib.h>
#include <tgmath.h>
/**
 * @brief index N of the largest factorial to compute lg(N!).
 *
 */
constexpr size_t N = 1000000000u;

/**
 * @brief Calculates the number of digits in the binary representation of the
 * integer truncation of lg(N!) and compares this with the estimated growth
 * rate of lg(N).
 *
 * @param argc
 * @param argv
 * @return EXIT_SUCCESS
 */
int main(int argc, char* argv[argc + 1]) {
    for (register size_t i = 1; i <= N; i *= 10) {
        register long double sum_lg = 0.0;
        for (register size_t j = 1; j <= i; j++) {
            sum_lg += log2(CAST(long double) j);
        }
        register long double const digits = ceil(log2(sum_lg));
        printf("N: %zu, digits: %Lf, lg(N): %Lf\n", i, digits + 1,
               log2(CAST(long double) i));
    }
    return EXIT_SUCCESS;
}