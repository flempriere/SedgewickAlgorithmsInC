/**
 * @file ex3_13.c
 * @author Felix Lempriere
 * @brief Solution to Exercise 3-13.
 *
 * Using the sieve of eratosthenes determine the number of primes less than
 * N for N = 10^3, 10^4, 10^5, 10^6.
 *
 * @date 2025-04-07
 * @version 0.1
 *
 * @copyright Copyright (c) 2025
 */

#include <stdio.h>
#include <stdlib.h>

/**
 * @brief largest number to check for primality
 *
 */
constexpr size_t N = 10000000u;
/**
 * @brief Initial N value for testing multiple cases
 *
 */
constexpr size_t N_INIT = 10000u;
/**
 * @brief Number of times to iterate N, each time N is 10x larger.
 *
 */
constexpr size_t N_CASES = 4u;

/**
 * @brief Sieve of Eratosthenes array
 *
 */
bool a[N];

/**
 * @brief Perform the Sieve of Eratosthenes for
 * N = 10^3, 10^4, 10^5, 10^6 and count the number
 * of primes less than each N
 *
 * @return EXIT_SUCCESS
 */
int main(int argc, char* argv[argc + 1]) {
    register size_t n = N_INIT;
    register size_t nPrimes = 0;
    register size_t curIdx = 2;

    // perform the sieve
    for (register size_t i = 2; i < N; i++) a[i] = true;

    for (register size_t i = 2; i < N; i++) {
        if (a[i]) {
            for (register size_t j = i; i * j < N; j++) a[i * j] = 0;
        }
    }
    // count for each of the cases
    for (register size_t i = 0; i < N_CASES; i++, n *= 10) {
        for (; curIdx < n; curIdx++) {
            if (a[curIdx]) nPrimes++;
        }
        printf("There are %zu primes less than %zu\n", nPrimes, n);
    }
    return EXIT_SUCCESS;
}