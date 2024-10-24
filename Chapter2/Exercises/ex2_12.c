/*
Exercise 2-12:
    Using the standard maths library implement an algorithm to compute
    the harmonic numbers.
*/

#include <tgmath.h>
#include <stdio.h>

#define N_HARMONICS 20
long double Harmonic_N(size_t x); 

int main(int argc, char *argv[argc + 1]) {
    for (size_t i = 1; i <= N_HARMONICS; i++) {
        printf("N: %zu, H_n : %Lf\n", i, Harmonic_N(i));
    }
}

long double Harmonic_N(size_t x) {
    const long double EULER_CONSTANT = 0.57721L;
    return log(x) + EULER_CONSTANT + 1.0L/(12.0L*x);
}
