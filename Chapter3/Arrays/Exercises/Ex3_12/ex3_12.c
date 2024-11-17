/*
Exercise 3.12

Implement the seive of eratosthenes using an array of char and an array of bits.
Compare the differences in time and space.

Bool has the same size as a char, so we'll only focus on a bit implementation

Our bit implementation is slower!
*/

/*
Program 3.5
Sieve of Eratosthemes, determines the primes up to N using an array.

a[i] is set to true to indicate i being prime else 0.
First we assume each number is prime, then we get the smallest prime p we have
yet to examine and set all a[j*p] to 0 for all j > 2 s.t jp <= N 

*/
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <time.h>

/**
 * @brief Largest Number we check for primality
 * 
 */
#define N 100000

/**
 * @brief Sieve of Eratosthenes array
 * 
 */
bool a[N];
/**
 * @brief Compares a bit-indexed implementation of
 * the sieve with a bool based implementation.
 * 
 * @return EXIT_SUCCESS
 */
int main(int argc, char* argv[argc + 1]) {

    for (size_t i = 2; i < N; i++) a[i] = true;

    clock_t tic = clock();
    for (size_t i = 2; i < N; i++) {
        if (a[i]) {
            for (size_t j = i; i*j < N; j++) a[i*j] = 0;
        }
    }
    clock_t toc = clock();
    double time_spent = (double)(toc - tic) / CLOCKS_PER_SEC;
    for (size_t i = 2; i < N; i++) {
        if (a[i]) printf("%4zu ", i);
    }
    printf("\n");
    printf("Time taken for char array: %f\n", time_spent);

    //using bit array
    size_t nComponents = N / CHAR_BIT;
    if (N % CHAR_BIT) nComponents += 1;
    unsigned char mask = 0x01u;

    unsigned char* bitArray = malloc(nComponents*sizeof(typeof(*bitArray)));

    //turn on all bits
    // i = 8 -> component 1, shift 0
    // i = 9 -> component 1, shift 1
    for (size_t i = 0; i < nComponents; i++) {
        for (size_t j = 0; j < CHAR_BIT; j++) {
            bitArray[i] |= (mask << j);
        }
    }

    tic = clock();
    for (size_t i = 2; i < N; i++) {
        if (bitArray[i/CHAR_BIT] & (mask << (i % CHAR_BIT))) {
            for (size_t j = i; i*j < N; j++) {
                bitArray[(i*j) / CHAR_BIT] &= ~(mask << ((i*j) % CHAR_BIT));
            }
        }
    }
    toc = clock();
    time_spent = (double)(toc - tic) / CLOCKS_PER_SEC;
    for (size_t i = 2; i < N; i++) {
        if (bitArray[i/CHAR_BIT] & (mask << (i % CHAR_BIT))) printf("%4zu ", i);
    }
    printf("\n");
    printf("Time taken for bit implementation array: %f\n", time_spent);

    return EXIT_SUCCESS;
}