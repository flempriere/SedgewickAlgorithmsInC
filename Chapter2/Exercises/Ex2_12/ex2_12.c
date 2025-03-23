/*
Exercise 2-12:
    Using the standard maths library implement an algorithm to compute
    the harmonic numbers.
*/

#include "../../../MacroLibrary/Utility.h"

#include <stdio.h>
#include <stdlib.h>
#include <tgmath.h>

/**
 * @brief Number of harmonic numbers to calculate
 *
 */
constexpr size_t N_HARMONICS = 20u;

/**
 * @brief Calculates the n-th harmonic number
 * through an approximation using ln(N)
 *
 * @param x order of the harmonic
 * @return long double
 */
long double Harmonic_N(size_t const x);

/**
 * @brief Calculate the first @N_HARMONICS
 * using our function.
 *
 * @return EXIT_SUCCESS
 */
int main(int argc, char* argv[argc + 1]) {
    for (register size_t i = 1; i <= N_HARMONICS; i++) {
        printf("N: %zu, H_n : %Lf\n", i, Harmonic_N(i));
    }
    return EXIT_SUCCESS;
}

long double Harmonic_N(size_t const x) {
    if (x == 1)
        return 1.0L;
    else if (x == 2)
        return 1.5L;

    const long double EULER_CONSTANT = 0.57721L;
    return log(CAST(long double) x) + EULER_CONSTANT + 1.0L / (12.0L * x);
}
