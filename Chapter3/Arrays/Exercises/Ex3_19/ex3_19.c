/*
Exercise 3.19

Empirically determine the number of random positive integers less than 1000
that you can expect to generate before getting all values.

This implementation repeats the experiment M times where M is a command line
argument.

*/
#include "../../../../MacroLibrary/NumberParse.h"
#include "../../../../MacroLibrary/Random.h"

#include <stdio.h>
#include <stdlib.h>
#include <tgmath.h>

/**
 * @brief largest number we can generate
 *
 */
constexpr size_t MAX_NUM = 1000u;

/**
 * @brief Generates random positive integers
 * up to MAX_NUM until all values are generated.
 *
 * This process is repeated @M times and the
 * average and std. dev computed.
 *
 * @param argv[1] M
 * @return EXIT_SUCCESS on successful execution else
 * @return EXIT_FAILURE
 *
 * @see MAX_NUM
 */
int main(int argc, char* argv[argc + 1]) {
    if (argc != 2) {
        fprintf(stderr, "Error: call structure is ./ex3_18 M\n");
        return EXIT_FAILURE;
    }
    size_t a[MAX_NUM];

    register size_t const M = NUMPARSEexit_on_fail(M, argv[1]);

    RAND_SEED_TIME;

    register double m1 = 0.0;
    register double m2 = 0.0;

    for (register size_t k = 0; k < M; k++) {
        register size_t nGen = 0;
        for (register size_t i = 0; i < MAX_NUM; i++) a[i] = 0;
        register size_t nSeen = 0;
        while (nSeen < MAX_NUM) {
            register size_t i = RAND_NUM(MAX_NUM);
            if (!(a[i]++)) { nSeen++; }
            nGen++;
        }
        m1 += ((double) nGen) / CAST(double) M;
        m2 += ((double) (nGen * nGen)) / CAST(double) M;
    }
    printf("===== Results, M = %zu =====\n", M);
    printf("       Average: %f\n", m1);
    printf("Std. deviation: %f\n", sqrt(m2 - m1 * m1));

    return EXIT_SUCCESS;
}