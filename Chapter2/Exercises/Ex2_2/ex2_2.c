/**
 * @file ex2_2.c
 * @author Felix Lempriere
 * @brief Implementation of Exercise 2-2 from Chapter 2 of Sedgewick's
 * Algorithms in C.
 *
 * This program analyzes the runtime of a triple nested loop for different
 * values of N (10, 100, 1000). The goal is to determine the computational
 * complexity and runtime behavior of the loop structure.
 *
 * The program outputs the results of the runtime analysis for each value of N.
 *
 * @date 2025-04-07
 * @version 0.1
 * @copyright Copyright (c) 2025
 */
#include "MacroLibrary/Utility.h"

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/**
 * @brief Defines the number of distinct N values to test.
 *
 */
constexpr size_t N_SCALES = 5u;

/**
 * @brief Executes three nested loops, each iterating from 0 to N (exclusive).
 *
 * @param n The upper limit for the loops.
 *
 * @return size_t The total count of iterations.
 */
static inline size_t triple_loop(size_t const n);

/**
 * @brief Measures and prints the runtime of a triple nested loop
 * for different values of N (10, 100, 1000). Outputs the results
 * to stdout.
 *
 * @return EXIT_SUCCESS upon successful execution.
 */
int main(int argc, char* argv[argc + 1]) {
    size_t LIMITS[N_SCALES] = { 10, 50, 100, 500, 1000 };

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