/*
Program 3.13
Using the sieve of eratosthenes determine the number of primes less than
N for N = 10^3, 10^4, 10^5, 10^6.
*/
#include <stdio.h>

#define N 1000
#define N_CASES 4

bool a[N];
size_t n_primes[N];

int main(int argc, char* argv[argc + 1]) {

    for (size_t i = 2; i < N; i++) a[i] = true;

    for (size_t i = 2; i < N; i++) {
        if (a[i]) {
            for (size_t j = i; i*j < N; j++) a[i*j] = 0;
        }
    }

    for (size_t i = 2; i < N; i++) {
        n_primes[i] = n_primes[i - 1] + ((a[i - 1]) ? 1 : 0);
        printf("%4zu: %zu\n", i, n_primes[i]); 
    }

    return 0;
}