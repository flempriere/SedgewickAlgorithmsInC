/**
 * @file ex2_44.c
 * @author Felix Lempriere
 * @brief Solution to Exercise 2-44 from Chapter 2 of Sedgewick's Algorithms in
 * C.
 *
 * Compares the coefficients of the recurrence relation
 * ```math
 * \begin{align}
 * C_N &= \left(1 + \frac{1}{\lg\left(N\right)}\right)
 * \end{align}
 * ```
 * generating from definition vs from an explicit solution given by
 *
 * ```math
 * \begin{align}
 *  C_{2^n} &= \frac{1}{n!}\frac{\left(2n + 1\right)!}{2^n\left(n\right)!}
 * \implies C_{N} &= \frac{\left(2\lg\left(N\right) +
 * 1\right)!}{N\left[\lg\left(N\right)!\right]^2}
 * \end{align}
 * ```
 *
 * @version 0.1
 * @date 2025-04-13
 *
 * @copyright Copyright (c) 2025
 *
 */

#include "MacroLibrary/Mathematics.h"
#include "MacroLibrary/Utility.h"

#include <stdio.h>
#include <stdlib.h>

/**
 * @brief Returns the actual value of lg(n).
 *
 * @param n
 */
static inline size_t truelg(size_t n) { return MATHlg(n) - 1; }

/**
 * @brief Calculates the value of the coefficient C_n in the reccurence
 * C_n = (1 + 1/lg(n))C_(n/2) from the definition.
 *
 * @param n
 * @return size_t
 */
long double calculate_cn_by_definition(size_t n) {
    register long double c_n = 1;
    for (; n > 1; n /= 2) { c_n *= 2 + 1.0L / CAST(long double)(truelg(n)); }
    return c_n;
}

/**
 * @brief Calculates the value of the coefficient c_n in the recurrence
 * C_n = (1 + 1/lg(n))C_(n/2) using an explicit solution.
 *
 * @details
 * The solution to the recurrence is given by
 * ```math
 * \begin{align}
 *  C_{2^n} &= \frac{1}{n!}\frac{\left(2n + 1\right)!}{2^n\left(n\right)!}
 * \implies C_{N} &= \frac{\left(2\lg\left(N\right) +
 * 1\right)!}{N\left[\lg\left(N\right)!\right]^2}
 * \end{align}
 * ```
 *
 * @param n
 * @return long double
 */
long double calculate_cn_by_solution(size_t n) {
    register size_t const lgn = truelg(n);
    register size_t const numerator = MATHfactorial(2 * lgn + 1);
    register size_t lgfactorial = MATHfactorial(lgn);
    return (CAST(long double) numerator) / (n * lgfactorial * lgfactorial);
}

int main(int argc, char* argv[argc + 1]) {
    /**
     * @brief Largest exponent i to use for the test cases N = 2^i.
     *
     */
    constexpr size_t MAX_EXP = 8;

    for (register size_t i = 0; i <= MAX_EXP; i++) {
        register size_t const n = 1u << i;
        printf(
            "N: %8zu\ti: %4zu\tC_n (definition): %8Lf\tC_n (formula): %8Lf\n",
            n, i, calculate_cn_by_definition(n), calculate_cn_by_solution(n));
    }
    return EXIT_SUCCESS;
}