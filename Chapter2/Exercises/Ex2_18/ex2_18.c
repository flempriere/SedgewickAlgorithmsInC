/**
 * @file ex2_18.c
 * @author Felix Lempriere
 * @brief Solution to Exercise 2-18 from Chapter 2 of Sedgewick's Algorithms in
 * C.
 *
 * This program calculates the smallest values of N such that floor(H_n) = i
 * for 1 <= i <= 10, where H_n is the N-th harmonic number. The program uses
 * both an approximation formula and the exact definition of harmonic numbers
 * for comparison. It highlights slight discrepancies between the two methods
 * for small values of N.
 *
 * The harmonic number H_n is defined as:
 *   H_n = 1 + 1/2 + 1/3 + ... + 1/n.
 *
 * The approximation used is:
 *   H_n ≈ ln(n) + γ + 1/(12n),
 * where γ is the Euler-Mascheroni constant (approximately 0.57721).
 *
 * The program outputs the smallest N for each i, along with the corresponding
 * harmonic number H_n, calculated using both methods.
 *
 * @date 2025-04-07
 * @version 0.1
 * @copyright Copyright (c) 2025
 */

#include "MacroLibrary/Utility.h"
#include "MacroLibrary/Mathematics.h"

#include <stdio.h>
#include <stdlib.h>
#include <tgmath.h>

/**
 * @brief The maximum harmonic number to compute.
 *
 */
constexpr size_t N = 10u;

/**
 * @brief Maximum harmonic number for which results are cached.
 */
constexpr size_t MAX_CACHE = 15000u;

/**
 * @brief Calculates the N-th harmonic number approximately.
 *
 * The N-th harmonic number is defined as the sum of the reciprocals of the
 * first N natural numbers: H(N) = 1 + 1/2 + 1/3 + ... + 1/N.
 *
 * The approximation used is:
 *   H_n ≈ ln(n) + γ + 1/(12n),
 * where γ is the Euler-Mascheroni constant (approximately 0.57721).
 *
 * @param x The index of the harmonic number to calculate. Must be a positive
 * integer.
 * @return An approximation of the N-th harmonic number
 */
long double Harmonic_N(size_t const x);

/**
 * @brief Calculates the N-th harmonic number exactly.
 *
 * The N-th harmonic number is defined as the sum of the reciprocals of the
 * first N natural numbers: H(N) = 1 + 1/2 + 1/3 + ... + 1/N.
 *
 * A static cache is used to improve efficiency.
 *
 * @param x The index of the harmonic number to calculate. Must be a positive
 * integer.
 *
 * @pre x > 0.
 *
 * @return The exact value of the N-th harmonic number.
 */
long double Harmonic_N_Exact(size_t const x);

/**
 * @brief Finds the smallest value of i such that floor(f(i)) = N for each N
 * in the range [1, max_n].
 *
 * This function iterates through values of i, applying the provided function f
 * to compute the harmonic number (or its approximation) for each i. It checks
 * whether the floored result of f(i) matches the current target value N. Once
 * a match is found, it records the value of i and the corresponding harmonic
 * number H_i, then moves to the next target value of N. The process continues
 * until all values of N in the range [1, max_n] are processed.
 *
 * The function outputs the results in a tabular format, displaying the target
 * value N, the smallest i that satisfies floor(f(i)) = N, and the computed
 * harmonic number H_i.
 *
 * @param f A pointer to the function that computes the harmonic number. The
 *          function must take a single size_t argument and return a long
 * double. Must be non null.
 * @param max_n The maximum value of N for which to find the corresponding i.
 *              Must be a positive integer.
 *
 *@pre f is not null.
 *@pre max_n > 0.
 */
void find_i_st_f_i_is_n(long double f(size_t const n), size_t const max_n);

/**
 * @brief Calculates and displays the smallest values of N such that floor(H_n)
 * = i for each i in the range [1, 10].
 *
 * This section of the program is responsible for finding the smallest integer N
 * such that the floored value of the harmonic number H_n equals the target
 * value i, where i ranges from 1 to 10. The harmonic number H_n can be computed
 * either using an approximation formula or the exact definition, depending on
 * the function passed to the `find_i_st_f_i_is_n` function.
 *
 * The results are displayed in a tabular format, showing:
 * - The target value i.
 * - The smallest value of N that satisfies floor(H_n) = i.
 * - The computed harmonic number H_n for the corresponding N.
 *
 * This process is performed twice in the main function:
 * 1. Using the approximation formula for H_n.
 * 2. Using the exact definition of H_n.
 *
 * The output highlights any discrepancies between the two methods for small
 * values of N.
 *
 * @param argc The number of command-line arguments.
 * @param argv The array of command-line arguments.
 *
 * @return EXIT_SUCCESS if the program completes successfully.
 */
int main(int argc, char* argv[argc + 1]) {
    printf("Calculating by approximation\n");
    find_i_st_f_i_is_n(Harmonic_N, N);
    printf("Calculating from the definition\n");
    find_i_st_f_i_is_n(Harmonic_N_Exact, N);

    return EXIT_SUCCESS;
}

long double Harmonic_N(size_t const x) {
    if (x == 1) return 1.0L;
    return log(CAST(double) x) + MATHEULER_CONSTANT + 1.0L / (12.0L * x);
}

long double Harmonic_N_Exact(size_t const x) {
    static long double cache[MAX_CACHE + 1] = {};
    static size_t max_N = 0;
    if (x <= max_N) return cache[x];
    while (++max_N <= x) cache[max_N] = cache[max_N - 1] + 1.0L / x;
    --max_N;
    return cache[x];
}

void find_i_st_f_i_is_n(long double f(size_t const n), size_t const max_n) {
    register size_t n = 1;
    for (register size_t i = 1; i <= max_n; i++) {
        for (; floor(f(n)) != i; n++);
        printf("i: %10zu\tn: %10zu:\tH_n: %Lf\n", i, n, f(n));
    }
}