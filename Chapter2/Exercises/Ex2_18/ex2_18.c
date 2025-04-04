/*
Generates the smallest values of N such that floor(H_n) = i for 1 <= i <= 10

This uses both sedgewick's approximation and the definition for comparison,
there are slight discrepancies between the two for low n.
*/

#include "MacroLibrary/Utility.h"

#include <stdio.h>
#include <stdlib.h>
#include <tgmath.h>

/**
 * @brief Harmonic number to calculate up to.
 *
 */
constexpr size_t N = 10u;

/**
 * @brief largest harmonic number to cache results
 * for.
 */
constexpr size_t MAX_CACHE = 15000u;

/**
 * @brief Calculates the N-th harmonic approximately.
 */
long double Harmonic_N(size_t const x);

/**
 * @brief Calculates the N-th harmonic exactly.
 *
 */
long double Harmonic_N_Exact(size_t const x);

/**
 * @brief find the value of i such that floor(f(i)) = N for
 * N = 0 up to max_n (inclusive).
 *
 * @param f
 * @param max_n
 */
void find_i_st_f_i_is_n(long double (*const f)(size_t n), size_t max_n);

/**
 * @brief Calculate the smallest values of
 * N such that floor(H_n) = i for 1 <= N <= 10
 *
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
    long double const EULER_CONSTANT = 0.57721L;
    return log(CAST(double) x) + EULER_CONSTANT + 1.0L / (12.0L * x);
}

long double Harmonic_N_Exact(size_t const x) {
    static long double cache[MAX_CACHE + 1] = {};
    static size_t max_N = 0;
    if (x <= max_N) return cache[x];
    while (++max_N <= x) cache[max_N] = cache[max_N - 1] + 1.0L / x;
    --max_N;
    return cache[x];
}

void find_i_st_f_i_is_n(long double (*const f)(size_t n), size_t max_n) {
    register size_t n = 1;
    for (register size_t i = 1; i <= max_n; i++) {
        for (; floor((*f)(n)) != i; n++);
        printf("i: %10zu\tn: %10zu:\tH_n: %Lf\n", i, n, (*f)(n));
    }
}