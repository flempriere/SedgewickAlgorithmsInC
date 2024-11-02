/*
Exercise 3_4 implementation utilising num.c and num.h from Program 3.2
based on the implementations in exercise 3.2 and exercise 3.3
*/
#include <tgmath.h>
#include <stdlib.h>
#include <stdio.h>
#include "num.h"

#define N_CASES 4
#define R_CASES 3

#define N_INIT 10000
#define R_INIT 2

int main(int argc, char* argv[argc + 1]) {

    int n = N_INIT;
    int r = R_INIT;

    printf("Testing rand() with modulus\n");
    for (size_t i = 0; i < N_CASES; n *= 10, i++) { //iterate over N values
        for (size_t j = 0; j < R_CASES; r *= r, j++) { //iterate over r values
            double m1 = 0.0;
            double m2 = 0.0;
            Number x;
            for (size_t k = 0; k < n; k++) {
                x = randNumModulus(r);
                m1 += ((double) x)/ n;
                m2 += ((double) x*x)/ n;
            }
            printf("Results for N: %d, R: %d\n", n, r);
            printf("       Average: %f\n", m1);
            printf("Std. deviation: %f\n", sqrt(m2 - m1*m1));
        }
        printf("\n");
        r = R_INIT;
    }
    n = N_INIT;

    printf("Testing rand() via rescaled doubles\n");
    for (size_t i = 0; i < N_CASES; n *= 10, i++) { //iterate over N values
        for (size_t j = 0; j < R_CASES; r *= r, j++) { //iterate over r values
            double m1 = 0.0;
            double m2 = 0.0;
            Number x;
            for (size_t k = 0; k < n; k++) {
                x = randNumTruncate(r);
                m1 += ((double) x)/ n;
                m2 += ((double) x*x)/ n;
            }
            printf("Results for N: %d, R: %d\n", n, r);
            printf("       Average: %f\n", m1);
            printf("Std. deviation: %f\n", sqrt(m2 - m1*m1));
        }
        printf("\n");
        r = R_INIT;
    }

    return 0;
}