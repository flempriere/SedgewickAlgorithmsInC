/*
Multifile implementation of Program 3.2 that utilises a client file (avg.c)
an interface file (num.h) and an implementation file (num.c)
*/
#include "../../../../../MacroLibrary/Random.h"
#include "../../../../../MacroLibrary/Utility.h"
#include "num.h"

#include <stdio.h>
#include <stdlib.h>
#include <tgmath.h>
#include <time.h>

/**
 * @brief Calculate the average and standard deviation
 * of a collection of random numbers.
 *
 * @param argv[1] number of random numbers to generate
 *
 * @return EXIT_SUCCESS on success, else EXIT_FAILURE
 *
 */
int main(int argc, char* argv[argc + 1]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: ./app N\n");
        return EXIT_FAILURE;
    }

    register size_t const N = strtoull(argv[1], nullptr, 0);
    register double m1 = 0.0;
    register double m2 = 0.0;
    RAND_SEED_TIME;

    register Number x;

    for (register size_t i = 0; i < N; i++) {
        x = NUMBERrandom();
        m1 += (x) / CAST(double) N;
        m2 += (CAST(double) x * x) / CAST(double) N;
    }
    printf("       Average: %f\n", m1);
    printf("Std. deviation: %f\n", sqrt(m2 - m1 * m1));

    return EXIT_SUCCESS;
}