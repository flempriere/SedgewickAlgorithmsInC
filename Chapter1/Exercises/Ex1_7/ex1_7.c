/**
 * @file ex1_7.c
 * @author Felix Lempriere
 * @brief Solution to Exercise 1-7 from Chapter 1 of Sedgewick's
 * Algorithms in C.
 *
 * This program demonstrates the [Weighted Quick
 * Union](../../Examples/Program1_3/UnionFind_1_3.c) algorithm by:
 * - Showing the state of the `id` array after procesing each input pair.
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
constexpr size_t N = 10000u;

/**
 * @brief Maximum number of characters, including the null terminator,
 * that can be read into the input buffer for fgets.
 *
 */
constexpr size_t MAXLINE = 100u;

/**
 * @brief Reads input pairs `p` and `q` from standard input and performs union
 * operations using the Weighted Quick Union algorithm showing the array state
 * and number of array accesses after each pair is processed..
 *
 * For each valid pair of integers `p` and `q` (both less than `N`):
 * - If `p` and `q` are not connected, it connects them and prints the pair.
 * - After each union operation, the program prints the current state of the
 * `id[]` array.
 * - Tracks and displays the number of array accesses for each pair and the
 * cumulative total of array accesses.
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
    register size_t tot_acc = 0;
    char line[MAXLINE];

    /* Initialize the id and sz arrays with each element in its own component of
     * size 1s */
    for (register size_t i = 0; i < N; i++) {
        id[i] = i;
        sz[i] = 1;
    }
    while (FGETS(line) && sscanf(line, "%zu %zu", &p, &q) == 2) {
        if (p >= N || q >= N) continue;

        register size_t n_acc = 0;

        size_t i;
        size_t j;
        /* Find the roots of p and q */
        for (i = p; n_acc++, i != id[i]; i = id[i], n_acc++);
        for (j = q; n_acc++, j != id[j]; j = id[j], n_acc++);

        if (i == j) goto updateArrayAccesses;

        /* Weighted Quick Union - Connect the smaller tree to the larger one to
         * reduce tree height*/
        if (sz[i] < sz[j]) SWAP(i, j);
        id[j] = i;
        sz[i] += sz[j];
        n_acc += 5;
        printf(" %zu %zu\n", p, q);
        ARRAYPRINT(N, id);
    updateArrayAccesses:
        printf("array acceses for (%zu, %zu): %zu\n", p, q, n_acc);
        tot_acc += n_acc;
    }
    printf("Total accesses: %zu\n", tot_acc);
    return read_reached_feof(stdin) ? EXIT_SUCCESS : EXIT_FAILURE;
}
