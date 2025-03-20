/*
Program 3.5
Sieve of Eratosthemes, determines the primes up to N using an array.

a[i] is set to true to indicate i being prime else 0.
First we assume each number is prime, then we get the smallest prime p we have
yet to examine and set all a[j*p] to 0 for all j > 2 s.t jp <= N 

*/
#include <stdio.h>
#include <stdlib.h>

/**
 * @brief largest number to check for primality.
 * 
 */
#define N 10000u

/**
 * @brief Determines all the primes up to N
 * 
 * @return EXIT_SUCCESS
 */
int main(int argc, char* argv[argc + 1]) {

    bool a[N+1];
    for (size_t i = 2; i <= N; i++) a[i] = true;

    for (size_t i = 2; i <= N; i++) {
        if (a[i]) {
            for (size_t j = i; i*j <= N; j++) a[i*j] = false;
        }
    }
    for (size_t i = 2; i <= N; i++) {
        if (a[i]) printf("%4zu ", i);
    }
    printf("\n");
    return EXIT_SUCCESS;
}