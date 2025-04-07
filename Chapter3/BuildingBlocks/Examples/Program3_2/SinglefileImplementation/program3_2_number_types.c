/**
 * @file program3_2_number_types.c
 * @author Felix Lempriere
 * @brief Program 3.2: Computes the average and standard deviation of a sequence
 * of random integers.
 *
 * This program calculates the average and standard deviation of a sequence of
 * integers x_1, x_2, ..., x_N generated using the `rand` function. A modified
 * definition of variance is used to avoid a double pass over the data,
 * improving efficiency.
 *
 * The program uses a `typedef` to localize the reference to the underlying
 * numerical type used for computation. For future statistical exercises, this
 * functionality has been extracted to the `Statistics.h` header in the
 * MacroLibrary folder.
 *
 * @note The largest number that can be generated is defined by `NUM_MAX`.
 *
 * @date 2025-04-07
 * @version 0.1
 *
 * @copyright Copyright (c) 2025
 */

#include "MacroLibrary/NumberParse.h"
#include "MacroLibrary/Random.h"
#include "MacroLibrary/Utility.h"

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
        register Number x = CAST(Number) RANDUINT(NUM_MAX);
        m1 += (x) / CAST(double) N;
        m2 += (CAST(double) x * x) / CAST(double) N;
    }
    printf("       Average: %f\n", m1);
    printf("Std. deviation: %f\n", sqrt(m2 - m1 * m1));

    return EXIT_SUCCESS;
}