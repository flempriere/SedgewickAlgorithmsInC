/*
Program 3.15
Determine the effect of removing the if (a[i]) test in the inner loop of
Program 3.5.

The approaches agree, but the program runs slower
*/
#include "../../../../MacroLibrary/Utility.h"

#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
/**
 * @brief Largest number to test for
 * primality
 *
 */
constexpr size_t N = 10000000u;

/**
 * @brief N value for the first test case
 *
 */
constexpr size_t N_INIT = 10000u;

/**
 * @brief Number of N values to test
 * Each is 10x larger than the previous
 *
 */
constexpr size_t N_CASES = 4u;

/**
 * @brief Sieve of Eratosthenes Array (Guarded)
 *
 */
bool a[N];

/**
 * @brief Sieve of Eratosthenes Array (Unguarded)
 *
 */
bool b[N];

/**
 * @brief Perform the sieve_of_eratosthenes using a guard
 * statement for k = 2 up to n (exclusive).
 *
 * @param n maximum number to check for primality.
 */
static inline void sieve_of_eratosthenes_guarded(size_t n) {
    for (register size_t k = 2; k < n; k++) {
        if (a[k]) {
            for (register size_t j = k; k * j < n; j++) a[k * j] = 0;
        }
    }
}

/**
 * @brief Perform the sieve_of_eratosthenes without a guard
 * statement for k = 2 up to n (exclusive).
 *
 * @param n maximum number to check for primality.
 */
static inline void sieve_of_eratosthenes_unguarded(size_t n) {
    for (register size_t k = 2; k < n; k++) {
        for (register size_t j = k; k * j < n; j++) b[k * j] = 0;
    }
}

long double time_function(void (*const f)(size_t), size_t n) {
    register clock_t const tic = clock();
    (*f)(n);
    register clock_t const toc = clock();

    return CAST(long double)(toc - tic) / CLOCKS_PER_SEC;
}

/**
 * @brief Compare the run time of the Sieve of
 * Eratosthenes with and without an if guard
 * for N = 10^3, 10^4, 10^5, 10^6.
 *
 * @return EXIT_SUCCESS
 */
int main(int argc, char* argv[argc + 1]) {
    register size_t n = N_INIT;
    for (register size_t i = 0; i < N_CASES; n *= 10, i++) {
        for (register size_t j = 2; j < n; j++) {
            a[j] = true;
            b[j] = true;
        }

        printf("N: %zu, Time for guarded: %Lf, Time for unguarded: %Lf\n", n,
               time_function(sieve_of_eratosthenes_guarded, n),
               time_function(sieve_of_eratosthenes_unguarded, n));

        // check both methods agree
        for (register size_t k = 0; k < n; k++) {
            assert(a[k] == b[k] && "Approaches disagree!\n");
        }
    }
    printf("===Approaches Agree===\n");
    return EXIT_SUCCESS;
}