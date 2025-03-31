/*
Program 3.2

Computes the average and standard deviation of sequence of numbers
x_1,x_2,...,x_N of integers generated by rand.

Note we use a modified definition of the variance to avoid a double pass
over the data.

typedef localises the reference to the datatype being used for the underlying
computation.

For future statistical exercises we have extracted this to the Statistics.h
header in the MacroLibrary folder.
*/

#include "../../../../MacroLibrary/NumberParse.h"
#include "../../../../MacroLibrary/Random.h"
#include "../../../../MacroLibrary/Utility.h"

#include <limits.h>
#include <stdio.h>
#include <stdlib.h>
#include <tgmath.h>

/**
 * @brief Typedef to obscure underlying numerical type.
 *
 */
typedef unsigned short Number;
/**
 * @brief largest number we can generate
 *
 */
constexpr unsigned short NUM_MAX = USHRT_MAX;

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
    register size_t const N = NUMPARSEexit_on_fail(N, argv[1]);

    RAND_SEED_TIME;

    register double m1 = 0.0;
    register double m2 = 0.0;

    for (register size_t i = 0; i < N; i++) {
        register Number x = CAST(Number) RANDuint(NUM_MAX);
        m1 += (x) / CAST(double) N;
        m2 += (CAST(double) x * x) / CAST(double) N;
    }
    printf("       Average: %f\n", m1);
    printf("Std. deviation: %f\n", sqrt(m2 - m1 * m1));

    return EXIT_SUCCESS;
}