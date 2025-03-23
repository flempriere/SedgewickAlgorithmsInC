/*
Exercise 3.21

Modify program 3.7 to generate a heads with probability lambda/N
*/

#include "../../../../MacroLibrary/Random.h"

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/**
 * @brief Probability of heads factor.
 * P(HEADS) = LAMBDA/N
 *
 */
constexpr double LAMBDA = 10.0;

/**
 * @brief performs a coin toss
 *
 * @return true if result is heads,
 * @return false if result is tails
 */
bool heads(double const lambda, size_t const N);

/**
 * @brief Performs M experiments each consisting
 * of N coin tosses with probability of heads
 * LAMBDA/N and counts the number of heads
 * in each run.
 *
 * The final distribution is plotted.
 *
 * @param argc[1] N
 * @param argc[2] M
 * @return EXIT_SUCCESS if completes, else
 * @return EXIT_FAILURE if there is an error
 *
 * @see LAMBDA
 */
int main(int argc, char* argv[argc + 1]) {
    if (argc != 3) {
        fprintf(stderr, "Error: requires arguments N and M\n");
        return EXIT_FAILURE;
    }
    register size_t const N = strtoull(argv[1], NULL, 0);
    register size_t const M = strtoull(argv[2], NULL, 0);

    RAND_SEED_TIME;

    size_t* f = malloc((N + 1) * sizeof(typeof_unqual(*f)));
    for (register size_t j = 0; j <= N; j++) f[j] = 0;

    for (register size_t i = 0; i < M; i++) {
        register size_t cnt = 0;
        for (register size_t j = 0; j <= N; j++) {
            if (heads(LAMBDA, N)) cnt++;
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

bool heads(double const lambda, size_t const N) {
    return rand() < (RAND_MAX * (lambda) / CAST(double) N);
}
