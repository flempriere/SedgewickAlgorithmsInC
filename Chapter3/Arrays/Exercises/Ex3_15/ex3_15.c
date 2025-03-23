/*
Program 3.15
Determine the effect of removing the if (a[i]) test in the inner loop of
Program 3.5.

The approaches agree, but the program runs slower
*/
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

        // time for with guard
        register clock_t toc = clock();
        for (register size_t k = 2; k < n; k++) {
            if (a[k]) {
                for (register size_t j = k; k * j < n; j++) a[k * j] = 0;
            }
        }
        register clock_t tic = clock();
        double const timeGuarded = (double) (tic - toc) / CLOCKS_PER_SEC;

        toc = clock();
        for (register size_t k = 2; k < n; k++) {
            for (register size_t j = k; k * j < n; j++) b[k * j] = 0;
        }
        tic = clock();
        double const timeUnguarded = (double) (tic - toc) / CLOCKS_PER_SEC;

        printf("N: %zu, Time for guarded: %f, Time for unguarded: %f\n", n,
               timeGuarded, timeUnguarded);

        // check both methods agree
        bool error_found = false;
        for (register size_t k = 0; k < n; k++) {
            if (a[k] != b[k]) {
                printf("Mismatch found for k: %4zu\n", k);
                error_found = true;
                break;
            }
        }
        if (!error_found) { printf("Approaches agree\n"); }
    }
    return EXIT_SUCCESS;
}