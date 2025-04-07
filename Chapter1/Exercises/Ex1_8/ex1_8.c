/**
 * @file ex1_8.c
 * @author Felix Lempriere
 * @brief Solution to Exercise 1-8 from Chapter 1 of Sedgewick's
 * Algorithms in C.
 *
 * This program demonstrates the [Path Compression by
 * Halving](../../Examples/Program1_4/UnionFind_1_4.c) algorithm by:
 * - Showing the state of the `id` array after processing each input pair.
 * - Counting the total number of array accesses (overall and per edge).
 *
 * @version 0.1
 * @date 2025-04-07
 * @copyright Copyright (c) 2025
 */

#include "MacroLibrary/Array.h"
#include "MacroLibrary/Defaultfgets.h"
#include "MacroLibrary/Generic.h"
#include "MacroLibrary/Utility.h"

#include <stdio.h>
#include <stdlib.h>

/**
 * @brief Maximum number of elements in the union-find structure. All valid
 * input pairs must be non-negative integers less than N.
 *
 */
constexpr size_t N = 16u;

/**
 * @brief Maximum number of characters, including the null terminator,
 * that can be read into the input buffer for fgets.
 *
 */
constexpr size_t MAXLINE = 100u;

/**
 * @brief Reads input pairs `p` and `q` from standard input and performs union
 * operations using the Weighted Quick Union with path compression by halving
 * algorithm showing the array state and number of array accesses
 * after each pair is processed..
 *
 * @exception Pairs where either `p` or `q` is greater than or equal to `N` are
 * ignored.
 * @return EXIT_SUCCESS if the program completes successfully, or EXIT_FAILURE
 * if an error occurs while reading input.
 */
int main(int argc, char* argv[argc + 1]) {
    size_t id[N];
    size_t sz[N];
    size_t p, q;
    register size_t tot_access = 0;
    char line[MAXLINE];

    for (register size_t i = 0; i < N; i++) {
        id[i] = i;
        sz[i] = 1;
    }
    while (FGETS(line) && sscanf(line, "%zu %zu", &p, &q) == 2) {
        if (p >= N || q >= N) continue;
        register size_t n_access = 0;

        size_t i;
        size_t j;
        for (i = p; n_access += 1, i != id[i]; i = id[i], n_access += 1) {
            id[i] = id[id[i]];
            n_access += 3;
        }
        for (j = q; n_access += 1, j != id[j]; j = id[j], n_access += 1) {
            id[j] = id[id[j]];
            n_access += 3;
        }
        if (i == j) goto updateArrayAccesses;

        if (sz[i] < sz[j]) SWAP(i, j);
        id[j] = i;
        sz[i] += sz[j];
        n_access += 5;
        printf(" %zu %zu\n", p, q);
        ARRAYPRINT(N, id);
    updateArrayAccesses:
        printf("array acceses for (%zu, %zu): %zu\n", p, q, n_access);
        tot_access += n_access;
    }
    printf("Total accesses: %zu\n", tot_access);
    return read_reached_feof(stdin) ? EXIT_SUCCESS : EXIT_FAILURE;
}