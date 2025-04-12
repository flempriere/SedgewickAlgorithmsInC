/**
 * @file ex2_27.c
 * @author Felix Lempriere
 * @brief Solution to Exercise 2-27 from Chapter 2 of Sedgewick's Algorithms in
 * C.
 *
 * @details
 * Calculates the inverse of the base-2 logarithm of the factorial function
 *derived with Stirlings approximation.
 *
 * ```math
 *\begin{align}
 * \frac{1}{e}\left(\ln\left(2\right)N - \frac{1}{2}\ln\left(2\pi
 *e\right)\right) &\approx \frac{k + 1/2}{e}\ln\left(\frac{k + 1/2}{e}\right) -
 *\frac{1}{2e}\\
 * \implies \ln\left(\frac{k + 1/2}{e}\right) &=
 *W\left(\frac{1}{e}\left(\ln\left(2\right)N - \frac{1}{2}\ln\left(2\pi e\right)
 *+ \frac{1}{2}\right)\right)\\
 * \implies k &= \frac{\left(\ln\left(2\right)N -
 *\frac{1}{2}\ln\left(2\pi\right)\right)}{W\left(\frac{1}{e}\left(\ln\left(2\right)N
 *- \frac{1}{2}\ln\left(2\pi\right)\right)\right)} - \frac{1}{2}
 * \end{align}
 * ```
 *
 * @version 0.1
 * @date 2025-04-12
 *
 * @copyright Copyright (c) 2025
 *
 */

#include "MacroLibrary/Mathematics.h"
#include "MacroLibrary/Utility.h"

#include <stdio.h>
#include <stdlib.h>
#include <tgmath.h>

/**
 * @brief Determine the inverse of log(k!) = N.
 *
 * Calculates the inverse f(n) = k s.t ln(k!) = N, is calculated using an
 * approxmation derived from Stirlings approximation
 *
 * ```math
 *\begin{align}
 * \frac{1}{e}\left(\ln\left(2\right)N - \frac{1}{2}\ln\left(2\pi
 *e\right)\right) &\approx \frac{k + 1/2}{e}\ln\left(\frac{k + 1/2}{e}\right) -
 *\frac{1}{2e}\\
 * \implies \ln\left(\frac{k + 1/2}{e}\right) &=
 *W\left(\frac{1}{e}\left(\ln\left(2\right)N - \frac{1}{2}\ln\left(2\pi e\right)
 *+ \frac{1}{2}\right)\right)\\
 * \implies k &= \frac{\left(\ln\left(2\right)N -
 *\frac{1}{2}\ln\left(2\pi\right)\right)}{W\left(\frac{1}{e}\left(\ln\left(2\right)N
 *- \frac{1}{2}\ln\left(2\pi\right)\right)\right)} - \frac{1}{2}
 * \end{align}
 * ```
 *
 * @param n
 * @return size_t
 */
size_t inverse_lg_factorial(long double n) {
    register long double const discrim = log(2) * n - log(sqrt(2 * MATHPI));
    return CAST(size_t) ceil((discrim / MATHLambert_W0(discrim / MATHe)) - 0.5);
}

int main(int argc, char* argv[argc + 1]) {
    /**
     * @brief K values to calculate lg(k!) and the inverses of. */
    constexpr size_t K = 10u;

    register size_t factorial = 1;
    for (register size_t k = 1; k <= K; k++) {
        // calculate factorial
        factorial *= k;
        register long double const n = log2(CAST(long double) factorial);
        register size_t const invlgf = inverse_lg_factorial(n);
        printf(
            "k: %4zu\tlgk: %8Lf\tInvFactorial(lgk):%4zu\n",
            k, n, invlgf);
    }

    return EXIT_SUCCESS;
}