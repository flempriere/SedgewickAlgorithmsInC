/*
Exercise 2-2:
    Determine the runtime of the inner triple loop for N = 10, 100, 1000
*/

#include <time.h>
#include <stddef.h>
#include <stdio.h>

#define N_SCALES 3

int main(int argc, char *argv[argc + 1]) {
    size_t LIMITS[N_SCALES] = {10, 100, 1000};

    for (size_t i = 0; i < N_SCALES; i++) {
        size_t count = 0;

        clock_t tic = clock();
        for (size_t j = 0; j < LIMITS[i]; j++) {
            for (size_t k = 0; k < LIMITS[i]; k++) {
                for (size_t l = 0; l < LIMITS[i]; l++) {
                    count++;
                }
            }
        }
        clock_t toc = clock();

        printf("N: %zu, time: %lf seconds\n", LIMITS[i], (double)(toc - tic) / CLOCKS_PER_SEC);
    }
    return 0;
}