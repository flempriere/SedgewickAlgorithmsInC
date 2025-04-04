/**
 * @file UnionFind_1_2.c
 * @author Felix Lempriere
 * @brief Quick Union solution to the connectivity problem.
 *
 * This program implements the Quick Union algorithm to solve the
 * connectivity problem. It provides a way to determine whether
 * two elements are in the same connected component and to merge
 * two components.
 *
 * @details
 * - **Complexity**:
 *   - **Union Operations**: Performed in constant time by connecting
 *     the root of one tree to another.
 *   - **Find Operations**: Performed in linear time by traversing
 *     the tree to find the root.
 *
 * @note
 * - Unions are achieved by building trees, where one element's
 *   root points to another.
 * - Find operations require traversing the tree to locate the root.
 * - Quick Union is generally faster than Quick Find because it
 *   avoids traversing the entire array during union operations.
 *
 * @version 0.1
 * @date 2025-03-28
 * @copyright Copyright (c) 2025
 */

#include "MacroLibrary/Defaultfgets.h"
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
 * @brief Implements the Quick Union algorithm to solve the connectivity
 * problem.
 *
 * @details
 * - Initializes an array `id` where each element points to itself.
 * - Reads pairs of non-negative integers `p` and `q` from standard input.
 * - For each pair, determines the root of `p` and `q` by following parent
 * links.
 * - If the roots of `p` and `q` are different, performs a union operation by
 *   connecting the root of `p` to the root of `q` and prints the pair.
 *
 * @exception Input pairs where either `p` or `q` is not less than `N` are
 * ignored.
 *
 * @return EXIT_SUCCESS if the program completes successfully, or EXIT_FAILURE
 * if an error occurs while reading input.
 */
int main(int argc, char* argv[argc + 1]) {
    size_t p;
    size_t q;
    size_t id[N];
    char line[MAXLINE];

    // Initialize the id array where each element is its own component
    for (register size_t i = 0; i < N; i++) id[i] = i;
    while (FGETS(line) && sscanf(line, "%zu %zu", &p, &q) == 2) {
        if (p >= N || q >= N) continue;    // bounds checking
        register size_t i;
        register size_t j;

        // Find the roots of p and q
        for (i = p; i != id[i]; i = id[i]);
        for (j = q; j != id[j]; j = id[j]);
        if (i == j) continue;
        // Perform the union operation
        id[i] = j;

        printf(" %zu %zu\n", p, q);
    }
    return read_reached_feof(stdin) ? EXIT_SUCCESS : EXIT_FAILURE;
}