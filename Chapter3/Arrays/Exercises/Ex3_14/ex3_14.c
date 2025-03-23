/*
Program 3.14
Using the sieve of eratosthenes print out the number of
primes less than N for for 1 <= N <= 1000
*/
#include <stdio.h>
#include <stdlib.h>

/**
 * @brief Largest N to check for primality
 *
 */
constexpr size_t N = 1001u;

/**
 * @brief Sieve of Eratosthenes Array
 *
 */
bool a[N];
/**
 * @brief Number of primes array
 *
 */
size_t n_primes[N];

/**
 * @brief Calculates the number of primes less
 * than N using the sieve of Eratosthenes and
 * then prints out the Number less than n
 * for 1 < n < N
 *
 * @return EXIT_SUCCESS
 */
int main(int argc, char* argv[argc + 1]) {
    for (register size_t i = 2; i < N; i++) a[i] = true;

    for (register size_t i = 2; i < N; i++) {
        if (a[i]) {
            for (register size_t j = i; i * j < N; j++) a[i * j] = false;
        }
    }
    // dynamic programming using the fact that n_primes array
    // is zero initialised
    for (register size_t i = 2; i < N; i++) {
        n_primes[i] = n_primes[i - 1] + ((a[i - 1]) ? 1 : 0);
        printf("%4zu: %zu\n", i, n_primes[i]);
    }

    return EXIT_SUCCESS;
}