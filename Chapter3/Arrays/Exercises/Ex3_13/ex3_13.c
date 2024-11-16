/*
Program 3.13
Using the sieve of eratosthenes determine the number of primes less than
N for N = 10^3, 10^4, 10^5, 10^6.
*/
#include <stdio.h>

#define N 10000000
#define N_INIT 10000
#define N_CASES 4

bool a[N];

int main(int argc, char* argv[argc + 1]) {


    size_t n = N_INIT;
    size_t nPrimes = 0;
    size_t curIdx = 2;

    for (size_t i = 2; i < N; i++) a[i] = true;

    for (size_t i = 2; i < N; i++) {
        if (a[i]) {
            for (size_t j = i; i*j < N; j++) a[i*j] = 0;
        }
    }
    for (size_t i = 0; i < N_CASES; i++, n *= 10) {
        for (; curIdx < n; curIdx++) {
            if (a[curIdx]) nPrimes++;
        }
        printf("There are %zu primes less than %zu\n", nPrimes, n);
    }
    printf("\n");
    return 0;
}