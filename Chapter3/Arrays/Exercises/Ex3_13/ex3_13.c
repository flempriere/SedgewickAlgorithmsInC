/*
Program 3.13
Using the sieve of eratosthenes determine the number of primes less than
N for N = 10^3, 10^4, 10^5, 10^6.
*/
#include <stdio.h>
#include <stdlib.h>

/**
 * @brief largest number to check for primality
 * 
 */
#define N 10000000u
/**
 * @brief Initial N value for testing multiple cases
 * 
 */
#define N_INIT 10000u
/**
 * @brief Number of times to iterate N
 * 
 */
#define N_CASES 4u

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

    size_t n = N_INIT;
    size_t nPrimes = 0;
    size_t curIdx = 2;

    //perform the sieve
    for (size_t i = 2; i < N; i++) a[i] = true;

    for (size_t i = 2; i < N; i++) {
        if (a[i]) {
            for (size_t j = i; i*j < N; j++) a[i*j] = 0;
        }
    }
    //count for each of the cases
    for (size_t i = 0; i < N_CASES; i++, n *= 10) {
        for (; curIdx < n; curIdx++) {
            if (a[curIdx]) nPrimes++;
        }
        printf("There are %zu primes less than %zu\n", nPrimes, n);
    }
    return EXIT_SUCCESS;
}