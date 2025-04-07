/**
 * @file UnionFind_1_3.c
 * @author Felix Lempriere
 * @brief Weighted Quick Union algorithm for dynamic connectivity.
 *
 * @details
 * This program implements the Weighted Quick Union algorithm to solve the
 * dynamic connectivity problem. It reads a sequence of pairs of non-negative
 * integers from standard input, where each pair `p q` represents a connection
 * between `p` and `q`.
 *
 * The algorithm optimizes the union operation by maintaining a size array
 * to ensure smaller trees are always attached under larger trees, reducing
 * the height of the trees and improving performance.
 *
 * - **Complexity**:
 *   - Union and find operations have logarithmic time complexity in the worst
 * case.
 *   - The weighted approach ensures efficient performance even for large
 * datasets.
 * - **Key Features**:
 *   - Uses an array `id[]` to represent the parent links of the union-find
 * structure.
 *   - Maintains a `size[]` array to track the size of each tree for weighted
 * union.
 *
 * @note This implementation is more efficient than the Quick-Find and
 * Quick-Union approaches, especially for large datasets.
 *
 * @version 0.1
 * @date 2025-04-07
 *
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
 * @brief Perform the Weighted Quick Union algorithm.
 *
 * @param argc Number of command-line arguments.
 * @param argv Array of command-line arguments.
 *
 * @exception If `p` or `q` is not less than `N`, the input pair is ignored.
 *
 * @return Returns `EXIT_SUCCESS` on successful execution, or `EXIT_FAILURE` if
 * an error occurs.
 *
 */
int main(int argc, char* argv[argc + 1]) {
    size_t id[N];
    size_t sz[N];
    size_t p, q;
    char line[MAXLINE];

    /*
     *Initialise the id and sz array. Each element is initially in
     *its own component of size 1. */
    for (register size_t i = 0; i < N; i++) {
        id[i] = i;
        sz[i] = 1;
    }

    while (FGETS(line) && sscanf(line, "%zu %zu", &p, &q) == 2) {
        size_t i;
        size_t j;

        if (p >= N || q >= N) continue;
        /* Find the roots of the trees containing p and q. */
        for (i = p; i != id[i]; i = id[i]);
        for (j = q; j != id[j]; j = id[j]);
        if (i == j) continue;

        /* Perform union by attaching the smaller tree to the larger tree to
         * maintain balance. */
        if (sz[i] < sz[j]) SWAP(i, j);
        id[j] = i;
        sz[i] += sz[j];

        printf(" %zu %zu\n", p, q);
    }

    return read_reached_feof(stdin) ? EXIT_SUCCESS : EXIT_FAILURE;
}