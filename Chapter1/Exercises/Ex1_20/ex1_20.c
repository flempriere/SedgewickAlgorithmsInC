/**
 * @file ex1_20.c
 * @author Felix Lempriere
 * @brief Solution to Exercise 1-20 from Chapter 1 of Sedgewick's
 * Algorithms in C.
 *
 * This program modifies the Weighted Union algorithm to use the height
 * of the tree instead of the size for balancing. It also compares the
 * timing of this modified algorithm with the original implementation
 * from [Program 1.3](../../Examples/Program1_3/UnionFind_1_3.c).
 *
 * @version 0.1
 * @date 2025-04-07
 * @copyright Copyright (c) 2025
 */
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
 * @brief Implements the Weighted Quick Union algorithm with height-based
 * balancing.
 *
 * @exception Pairs where either `p` or `q` is greater than or equal to `N` are
 * ignored.
 * @return EXIT_SUCCESS if the program completes successfully, or EXIT_FAILURE
 * if an error occurs while reading input.
 */
int main(int argc, char* argv[argc + 1]) {
    size_t id[N];
    size_t sz[N]; /* height of the tree rooted at i */
    size_t p, q;
    register size_t n_acc = 0;    // number of array accesses.
    char line[MAXLINE];

    /* Initialize the id and sz arrays with each element in its own component
     * of height 0 */
    for (register size_t i = 0; i < N; i++) {
        id[i] = i;
        sz[i] = 0;
    }
    while (FGETS(line) && sscanf(line, "%zu %zu", &p, &q) == 2) {
        size_t i;
        size_t j;

        /* Perform find on p and q */
        for (i = p; n_acc++, i != id[i]; i = id[i], n_acc++);
        for (j = q; n_acc++, j != id[j]; j = id[j], n_acc++);

        if (i == j) continue;

        /* Perform the Weighted Quick Union using tree height */
        if (sz[i] < sz[j]) SWAP(i, j);
        id[j] = i;
        sz[i] = MAX(sz[i], sz[j] + 1);
        n_acc++;
        printf(" %zu %zu\n", p, q);
    }
    return read_reached_feof(stdin) ? EXIT_SUCCESS : EXIT_FAILURE;
}