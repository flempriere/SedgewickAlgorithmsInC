/**
 * @file ex1_23.c
 * @author Felix Lempriere
 * @brief Implementation of Exercise 1-23 from Chapter 1 of Sedgewick's
 * Algorithms in C.
 *
 * This program generates random pairs of integers between 0 and N - 1 and
 * performs unions until N - 1 unions are completed. It then prints the total
 * number of edges processed.
 *
 * The program iterates over different values of N, from 100 to 1000.
 *
 * For each value of N, the program outputs the total number of edges generated
 * during the process.
 *
 * @date 2025-03-28
 * @version 0.1
 * @copyright Copyright (c) 2025
 */

#include "MacroLibrary/Generic.h"
#include "MacroLibrary/Random.h"

#include <stdio.h>
#include <stdlib.h>

/**
 * @brief Maximum number of vertices (N) allowed in any test case
 *
 */
constexpr size_t MAX_VERTEX = 1000u;

/**
 * @brief Minimum allowable value for the maximum vertex count in any test case.
 *
 */
constexpr size_t MIN_VERTEX = 100u;

/**
 * @brief Displays the number of edges required to connect N items
 * for start <= N < len.
 *
 * @param start Minimum value of N.
 * @param len Maximum value of N.
 * @param a Array containing results; indexes from start to len must be valid.
 */
void printGraph(size_t const start, size_t const len, size_t a[static len]);

/**
 * @brief Main function to simulate the union-find algorithm with path
 * compression.
 *
 * The program initializes arrays to represent the union-find structure and
 * iterates over values of N from MIN_VERTEX to MAX_VERTEX. For each N:
 * - It initializes the union-find structure.
 * - It generates random pairs of integers and performs unions until N - 1
 * unions are completed.
 * - It counts the total number of edges processed during this process.
 *
 * The results are stored in an array and printed using the printGraph function.
 *
 * @param argc Number of command-line arguments (unused).
 * @param argv Array of command-line arguments (unused).
 * @return EXIT_SUCCESS on successful execution.
 */
int main(int argc, char* argv[argc + 1]) {
    size_t id[MAX_VERTEX];
    size_t sz[MAX_VERTEX];
    size_t result[MAX_VERTEX + 1];

    RAND_SEED_TIME;
    printf("N\t # Edges\n");

    for (register unsigned N = MIN_VERTEX; N <= MAX_VERTEX; N++) {
        for (register size_t i = 0; i < N; i++) {
            id[i] = i;
            sz[i] = 1;
        }

        register size_t p = RANDUINT(N);
        register size_t q = RANDUINT(N);
        register size_t n_edges = 1;

        for (register size_t n_unions = 0; n_unions < N - 1;
             p = RANDUINT(N), q = RANDUINT(N), n_edges++) {
            size_t i;
            size_t j;
            for (i = p; i != id[i]; i = id[i]) { id[i] = id[id[i]]; }
            for (j = q; j != id[j]; j = id[j]) { id[j] = id[id[j]]; }

            if (i == j) continue;
            n_unions++;

            if (sz[i] < sz[j]) SWAP(i, j);
            id[j] = i;
            sz[i] += sz[j];
        }
        result[N] = n_edges;
    }
    printGraph(MIN_VERTEX, MAX_VERTEX + 1, result);
    return EXIT_SUCCESS;
}

void printGraph(size_t const start, size_t const len, size_t a[static len]) {
    for (register size_t i = start + 1; i < len; i++) {
        printf("%zu : %zu\n", i - 1, a[i - 1]);
    }
}