/**
 * @file ex2_18.c
 * @author Felix Lempriere
 * @brief Solution to Exercise 2-26 from Chapter 2 of Sedgewick's Algorithms in
 * C.
 *
 *
 * This program approximates the inverse of H_k = N. i.e. given the Harmonic
 * number equal to N, compute the index.
 *
 * Using the approximation
 * ```math
 * \begin{align}
 *      H_k &\approx \ln k + \gamma + \frac{1}(12k) &\appprox \ln k + \gamma \\
 *      N       &\approx \ln k + 0.57721... \\
 * \implies k   &\approx e^{-0.57721}e^{N} \\
 *              &\approx 2.14e^{N}
 *\end{align}
 *```
 * We use our results from Ex2-18 to test this result for N = 1 to 10.
 *
 * @date 2025-04-10
 * @version 0.1
 * @copyright Copyright (c) 2025
 */

#include "MacroLibrary/Utility.h"

#include <stdio.h>
#include <stdlib.h>
#include <tgmath.h>

/**
 * @brief Approximates the inverse to H_k = N, using k = 2.14e^{N}
 * 
 * @details
  * The approximate inverse is derived using the approximation
 * ```math
 * \begin{align}
 *      H_k &\approx \ln k + \gamma + \frac{1}(12k) &\appprox \ln k + \gamma \\
 *      N       &\approx \ln k + 0.57721... \\
 * \implies k   &\approx e^{-0.57721}e^{N} \\
 *              &\approx 2.14e^{N}
 *\end{align}
 *```
 * @param y value to compute the inverse of. Must be greater than 1.
 * @return long double 
 */
long double inverse_harmonic(long double y) {
    static long double inverse_tol = 1e-6;

    if (fabs(y - 1.0)/fabs(y) < inverse_tol) return 1.0;
    if (fabs(y - 1.5)/fabs(y) < inverse_tol) return 2.0;

    return 2.14*exp(y);
}

int main(int argc, char* argv[argc + 1]) {
    /**
     * @brief Maximum value to compute the inverse harmonic number for. Will
     * compute, from i = 1 up to i = N inclusive. Need to supply exact solutions
     * up to the provided N value in the EXACT_SOLUTION array.
     *
     * @see EXACT_SOLUTION
     */
    constexpr size_t N = 10u;
    /**
     * @brief Exact k values for H_k = i for 1 <= i <= 10, precomputed in
     * Ex2-18.
     *
     * size of this array should be configured with N
     *
     * @see N
     */
    constexpr size_t EXACT_SOLUTION[N] = { 1,   4,   11,   31,   83,
                                           227, 616, 1674, 4550, 12367 };

    for (register size_t i = 1; i <= N; i++) {
        printf("H_k: %4zu\t(H_k)^(-1): %8Lf\tPrecalculated: %zu\n", i,
               inverse_harmonic(CAST(long double) i), EXACT_SOLUTION[i - 1]);
    }
    return EXIT_SUCCESS;
}