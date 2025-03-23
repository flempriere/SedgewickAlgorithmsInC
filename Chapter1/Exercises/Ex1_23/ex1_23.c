/*
Exercise 1-23: Generate random pairs of integers between 0 and N - 1
loop until N - 1 unions are performed. Print the total number of edges

This program repeats for N = 100 to 1000 and prints the total number of edges
generated each time.
*/

#include "../../../MacroLibrary/Generic.h"
#include "../../../MacroLibrary/Random.h"
#include "../../../MacroLibrary/Utility.h"

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/**
 * @brief maximum value of a vertex across all runs
 *
 */
constexpr size_t MAX_VERTEX = 1000u;

/**
 * @brief smallest maximum value for any run.
 * @see MAX_VERTEX
 *
 */
constexpr size_t MIN_VERTEX = 100u;

/**
 * @brief Plots the number of edges needed to connect N items
 * for start <= N < len
 *
 * @param start min value of N
 * @param len  max value of N
 * @param a array storing results, indexes start -> len must be
 * valid
 */
void printGraph(size_t start, size_t len, size_t a[len]);

/**
 * @brief Generates a table of the number of edges needed to connect
 * N items for 100 <= N <= 1000 using Weighted Union with path compression
 * by halving assuming random input pairs.
 *
 * @return EXIT_SUCCESS
 */
int main(int argc, char* argv[argc + 1]) {
    size_t id[MAX_VERTEX];
    size_t sz[MAX_VERTEX];
    size_t result[MAX_VERTEX + 1];

    srand(CAST(unsigned int) time(NULL));
    printf("N\t # Edges\n");

    for (register size_t N = MIN_VERTEX; N <= MAX_VERTEX; N++) {
        for (register size_t i = 0; i < N; i++) {
            id[i] = i;
            sz[i] = 1;
        }

        register size_t p = RAND_SIZE_T(N);
        register size_t q = RAND_SIZE_T(N);
        register size_t n_edges = 1;

        for (register size_t n_unions = 0; n_unions < N - 1;
             p = RAND_SIZE_T(N), q = RAND_SIZE_T(N), n_edges++) {
            register size_t i;
            register size_t j;
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

void printGraph(size_t start, size_t len, size_t a[len]) {
    for (register size_t i = start++; i < len; i++) {
        printf("%zu : %zu\n", i - 1, a[i - 1]);
    }
}