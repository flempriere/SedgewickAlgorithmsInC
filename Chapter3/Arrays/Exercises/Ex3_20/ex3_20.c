/*
Exercise 3.20

Modify program 3.7 to generate a heads with probability p and then test the
results for p = 1/6.
*/

#include "MacroLibrary/DefaultCalloc.h"
#include "MacroLibrary/NumberParse.h"
#include "MacroLibrary/Random.h"

#include <stdio.h>
#include <stdlib.h>

/**
 * @brief Probability of heads
 *
 */
constexpr double P_HEADS = 1.0 / 6.0;

/**
 * @brief performs a coin toss
 *
 * @return true if result is heads,
 * @return false if result is tails
 */
static inline bool heads(double const p);

/**
 * @brief Performs M experiments each consisting
 * of N coin tosses with probability of heads
 * P_HEADS and counts the number of heads
 * in each run.
 *
 * The final distribution is plotted.
 *
 * @param argc[1] N
 * @param argc[2] M
 * @return EXIT_SUCCESS if completes, else
 * @return EXIT_FAILURE if there is an error
 *
 * @see P_HEADS
 */
int main(int argc, char* argv[argc + 1]) {
    if (argc != 3) {
        fprintf(stderr, "Error: requires arguments N and M\n");
        return EXIT_FAILURE;
    }
    register size_t const N = NUMPARSEexit_on_fail(N, argv[1]);
    register size_t const M = NUMPARSEexit_on_fail(M, argv[2]);

    RAND_SEED_TIME;

    size_t* const f = CALLOC_FAILS_EXIT(N + 1, *f);

    for (register size_t i = 0; i < M; i++) {
        register size_t cnt = 0;
        for (register size_t j = 0; j <= N; j++) {
            if (heads(P_HEADS)) cnt++;
        }
        f[cnt]++;
    }
    for (register size_t i = 0; i <= N; i++) {
        printf("%2zu ", i);
        for (register size_t j = 0; j < f[i]; j += 10) printf("*");
        printf("\n");
    }

    free(f);
    return EXIT_SUCCESS;
}

static inline bool heads(double const p) { return RANDCOIN_TOSS(p); }
