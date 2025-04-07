/**
 * @file ex1_5.c
 * @author Felix Lempriere
 * @brief Solution to Exercise 1-5 from Chapter 1 of Sedgewick's
 * Algorithms in C.
 *
 * This program demonstrates the [Quick
 * Union](../../Examples/Program1_2/UnionFind_1_2.c) algorithm by:
 * - Showing the state of the `id` array after processing each input pair
 * - Counting the total number of array accesses (overall and per edge).
 *
 * @version 0.1
 * @date 2025-04-07
 * @copyright Copyright (c) 2025
 */

#include "MacroLibrary/Array.h"
#include "MacroLibrary/Defaultfgets.h"
#include "MacroLibrary/Utility.h"

#include <stdio.h>
#include <stdlib.h>

/**
 * @brief Maximum number of elements in the union-find structure. All valid
 * input pairs must be non-negative integers less than N.
 *
 */
constexpr size_t N = 10u;

/**
 * @brief Maximum number of characters, including the null terminator,
 * that can be read into the input buffer for fgets.
 *
 */
constexpr size_t MAXLINE = 100u;

/**
 * @brief Reads input pairs `p` and `q` from standard input and performs union
 * operations using the Quick Union algorithm showing the array state and number
 * of array accesses after each pair is processed.
 *
 *
 * @exception Pairs where either `p` or `q` is greater than or equal to `N` are
 * ignored.
 * @return EXIT_SUCCESS if the program completes successfully, or EXIT_FAILURE
 * if an error occurs while reading input.
 */
int main(void) {
    size_t p;
    size_t q;
    size_t id[N];
    register size_t tot_accesses = 0;
    char line[MAXLINE];

    /* Initialize the id array with each element in its own component */
    for (register size_t i = 0; i < N; i++) id[i] = i;

    while (FGETS(line) && sscanf(line, "%zu %zu", &p, &q) == 2) {
        if (p >= N || q >= N) continue;

        register size_t i;
        register size_t j;
        register size_t n_acc = 0;

        /* Find the roots of p and q */
        for (i = p; n_acc++, i != id[i]; i = id[i], n_acc++);
        for (j = q; n_acc++, j != id[j]; j = id[j], n_acc++);

        if (i == j) goto updateArrayAccesses;

        /* Perform the union */
        id[i] = j;
        n_acc++;

        printf(" %zu %zu\n", p, q);
        ARRAYPRINT(N, id);
    updateArrayAccesses:
        printf("array accesses for (%zu, %zu): %zu\n", p, q, n_acc);
        tot_accesses += n_acc;
    }
    printf("Total accesses: %zu\n", tot_accesses);

    return read_reached_feof(stdin) ? EXIT_SUCCESS : EXIT_FAILURE;
}
