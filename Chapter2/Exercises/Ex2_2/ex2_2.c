/*
Exercise 2-2:
    Determine the runtime of the inner triple loop for N = 10, 100, 1000
*/

#include "MacroLibrary/Utility.h"

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/**
 * @brief Number of different N values to use.
 *
 */
constexpr size_t N_SCALES = 3u;

/**
 * @brief Iterates a nested set of three loops each from 0 up to N (exclusive).
 *
 * @param n
 * @return size_t sum.
 */
static inline size_t triple_loop(size_t const n);
/**
 * @brief times the runtime of a triple nested
 * for loop each iterating N = 10, 100, 1000
 * times. The results printed to stdout.
 *
 * @return EXIT_SUCCESS on success completion
 */
int main(int argc, char* argv[argc + 1]) {
    size_t LIMITS[N_SCALES] = { 10, 100, 1000 };

    for (register size_t i = 0; i < N_SCALES; i++) {
        register clock_t const tic = clock();
        triple_loop(LIMITS[i]);
        register clock_t const toc = clock();

        printf("N: %zu, time: %.6lf seconds\n", LIMITS[i],
               CAST(double)(toc - tic) / CLOCKS_PER_SEC);
    }
    return EXIT_SUCCESS;
}

static inline size_t triple_loop(size_t const n) {
    size_t cnt = 0;
    for (register size_t j = 0; j < n; j++) {
        for (register size_t k = 0; k < n; k++) {
            for (register size_t l = 0; l < n; l++) { cnt++; }
        }
    }
    return cnt;
}