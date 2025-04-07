/**
 * @file ex1_22.c
 * @author Felix Lempriere
 * @brief Solution to Exercise 1-22 from Chapter 1 of Sedgewick's
 * Algorithms in C.
 *
 * This program generates random pairs of integers between 0 and N - 1 and
 * performs unions until N - 1 unions are completed. It then prints the total
 * number of edges processed.
 *
 * The program repeats for different values of N, specifically:
 * - N = 10^3
 * - N = 10^4
 * - N = 10^5
 * - N = 10^6
 *
 * @date 2025-04-07
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
constexpr size_t MAX_VERTEX = 1000000u;

/**
 * @brief Number of distinct values of N to test
 *
 */
constexpr size_t N_CASES = 4u;

/**
 * @brief ID array for union find of size MAX_VERTEX
 *
 */
static size_t id[MAX_VERTEX];
/**
 * @brief sz array for union find of size MAX_VERTEX
 */
static size_t sz[MAX_VERTEX];

/**
 * @brief Evaluates the performance of Weighted Union-Find with Path
 * Compression.
 *
 * @details
 * This function tests the efficiency of the union-find algorithm by iterating
 * through different values of N: 10^3, 10^4, 10^5, and 10^6. For each value of
 * N:
 * - Random pairs of integers between 0 and N - 1 are generated.
 * - Unions are performed until exactly N - 1 unions are completed.
 * - The total number of edges processed is recorded and displayed.
 *
 * The algorithm uses path compression by halving during the find operation
 * and weighted quick union by size during the union operation.
 *
 * @return EXIT_SUCCESS upon successful execution.
 */
int main(int argc, char* argv[argc + 1]) {
    // loop through test cases
    for (register unsigned n = 1000, n_cases = 0u; n_cases < N_CASES;
         n *= 10, n_cases++) {
        /* Initialise the id and sz trees so each element is in its own
         * component of size 1*/
        for (register size_t i = 0; i < n; i++) {
            id[i] = i;
            sz[i] = 1;
        }
        RAND_SEED_TIME;

        register size_t p = RANDUINT(n);
        register size_t q = RANDUINT(n);

        register size_t n_edges = 1;
        for (register size_t n_unions = 0; n_unions < n - 1;
             p = RANDUINT(n), q = RANDUINT(n), n_edges++) {
            size_t i;
            size_t j;

            /* Perform find on p and q with path compression by halving */
            for (i = p; i != id[i]; i = id[i]) { id[i] = id[id[i]]; }
            for (j = q; j != id[j]; j = id[j]) { id[j] = id[id[j]]; }

            if (i == j) continue;
            n_unions++;
            /* Perform Weighted Quick Union by size */
            if (sz[i] < sz[j]) SWAP(i, j);
            id[j] = i;
            sz[i] += sz[j];
        }
        printf("N: %8u\tEdges: %8zu\n", n, n_edges);
    }
    return EXIT_SUCCESS;
}