/**
 * @file ex2_14.c
 * @author Felix Lempriere
 * @brief Determines how many digits there are in the representation of 1
 * million factorial using the fact that lg(n!) = sum_{m=2}^{n}lg(m) and the
 * number of digits to represent n is given by floor(lg(n!)) + 1.
 * @version 0.1
 * @date 2025-04-08
 *
 * @copyright Copyright (c) 2025
 *
 */

#include "MacroLibrary/Utility.h"

#include <stdio.h>
#include <stdlib.h>
#include <tgmath.h>
/**
 * @brief Size of the factorial to compute the number of digits of.
 *
 */
constexpr size_t N = 1000000u;

/**
 * @brief Calculates the number of digits in the representation of N!
 *
 * @param argc
 * @param argv
 * @return EXIT_SUCCESS
 */
int main(int argc, char* argv[argc + 1]) {
    for (register size_t i = 1; i <= N; i *= 10) {
        register long double sum_lg = 0.0;
        for (register size_t j = 1; j <= i; j++) {
            sum_lg += log10(CAST(long double) j);
        }
        printf("N: %zu, digits: %Lf\n", i, floor(sum_lg) + 1);
    }
    return EXIT_SUCCESS;
}