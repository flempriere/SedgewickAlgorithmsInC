/*
Program 3.7

This program runs a coin flipping experiment M times with each runc consisting
of N flips. An array f keeps track of the frequency of occurance of 0 <= i <= N
where i is the number of heads.

A histogram is then printed out, with one asterisk corresponding to 10
occurences.

The operation on which this program is based -- indexing an array with computed
value -- is critical to the efficiency of many computational procedures

utilises C23 bool, use _Bool or <stdbool.h> for older standards
*/
#include "../../../../MacroLibrary/DefaultCalloc.h"
#include "../../../../MacroLibrary/NumberParse.h"
#include "../../../../MacroLibrary/Random.h"

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/**
 * @brief performs a coin toss
 *
 * @return true if result is heads,
 * @return false if result is tails
 */
static inline bool heads(void) { return RAND_COIN_TOSS(); }

/**
 * @brief Performs M experiments each consisting
 * of N coin tosses and counts the number of heads
 * in each run.
 *
 * The final distribution is plotted.
 *
 * @param argc[1] N
 * @param argc[2] M
 * @return EXIT_SUCCESS if completes, else
 * @return EXIT_FAILURE if there is an error
 */
int main(int argc, char* argv[argc + 1]) {
    if (argc != 3) {
        fprintf(stderr, "Error: requires arguments N and M\n");
        return EXIT_FAILURE;
    }
    register size_t const N = NUMPARSEexit_on_fail(N, argv[1]);

    register size_t const M = NUMPARSEexit_on_fail(M, argv[2]);

    RAND_SEED_TIME;

    size_t* const f = DEFAULTCallocNVAR(N + 1, f);
    if (!f) {
        fprintf(stderr, "Failed to initialise frequency array\n");
        return EXIT_FAILURE;
    }

    for (register size_t i = 0; i < M; i++) {
        register size_t cnt = 0;
        for (register size_t j = 0; j < N; j++) {
            if (heads()) cnt++;
        }
        f[cnt]++;
    }
    for (register size_t j = 0; j <= N; j++) {
        printf("%2zu ", j);
        for (register size_t i = 0; i < f[j]; i += 10) printf("*");
        printf("\n");
    }
    free(f);
    return EXIT_SUCCESS;
}
