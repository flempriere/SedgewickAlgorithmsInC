/*
Exercise 3.5. Implement a version of Program 3.2 that supports bit types
(values that can be zero or one)
*/
#include <tgmath.h>
#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include "num_bit.h"

/**
 * @brief Performs avg and std. dev calculations
 * on random bits.
 * 
 * @return EXIT_SUCCESS on success else EXIT_FAILURE.
 */
int main(int argc, char* argv[argc + 1]) {

    if (argc != 2) {
        fprintf(stderr, "Usage: ./app N\n");
        return EXIT_FAILURE;
    }
    int N = atoi(argv[1]);
    double m1 = 0.0;
    double m2 = 0.0;
    srand(time(nullptr));

    Number x;

    for (size_t i = 0; i < N; i++) {
        x = randNum();
        m1 += ((double) x)/N;
        m2 += ((double) x*x) / N; 
    }
    printf("       Average: %f\n", m1);
    printf("Std. deviation: %f\n", sqrt(m2 - m1*m1));

    return 0;
}