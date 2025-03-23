/*
Exercise 2-2:
    Determine the runtime of the inner triple loop for N = 10, 100, 1000
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/**
 * @brief Number of different N values to use.
 *
 */
constexpr size_t N_SCALES = 3u;

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
        register size_t count = 0;

        register clock_t tic = clock();
        for (register size_t j = 0; j < LIMITS[i]; j++) {
            for (register size_t k = 0; k < LIMITS[i]; k++) {
                for (register size_t l = 0; l < LIMITS[i]; l++) { count++; }
            }
        }
        register clock_t toc = clock();

        printf("N: %zu, time: %lf seconds\n", LIMITS[i],
               (double) (toc - tic) / CLOCKS_PER_SEC);
    }
    return EXIT_SUCCESS;
}