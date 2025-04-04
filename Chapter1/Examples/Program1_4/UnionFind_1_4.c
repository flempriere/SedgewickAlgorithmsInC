/**
 * @file UnionFind_1_4.c
 * @brief Weighted Quick Union with Path Compression by Halving.
 *
 * This program improves the Weighted Quick Union algorithm by implementing
 * path compression by halving during find operations. Path compression
 * ensures that every node touched during a find operation has its parent
 * replaced by its grandparent, effectively flattening the tree structure
 * and improving performance.
 *
 * @details
 * - **Weighted Quick Union**:
 *   - Maintains a tree structure where smaller trees are always attached
 *     under larger trees to keep the tree height minimal.
 * - **Path Compression by Halving**:
 *   - During find operations, every node touched has its parent replaced
 *     by its grandparent, further reducing the tree height.
 * - **Complexity**:
 *   - Union and find operations are nearly constant time, with an amortized
 *     time complexity of O(α(N)), where α(N) is the inverse Ackermann function.
 *
 * @note This implementation is highly efficient and suitable for large
 * datasets.
 *
 * @version 0.1
 * @date 2025-03-28
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
 * @brief Processes input pairs of integers `p` and `q` (both less than N)
 * from standard input, checks their connectivity, and performs a union
 * operation if they are not already connected.
 *
 * @details
 * - Reads pairs of non-negative integers `p` and `q` from standard input.
 * - If `p` and `q` are already connected (i.e., they have the same root), no
 * action is taken.
 * - If `p` and `q` are not connected, performs a union operation to merge
 * their components and prints the pair to the output.
 *
 * @exception Input pairs where either `p` or `q` is not less than `N` are
 * ignored.
 *
 * @return EXIT_SUCCESS if the program completes successfully, or EXIT_FAILURE
 * if an error occurs while reading input.
 */
int main(int argc, char* argv[argc + 1]) {
    size_t id[N];
    size_t sz[N];
    size_t p, q;
    char line[MAXLINE];

    /* Initialise the id and sz arrays so each element is initially in its
     * own component of size 1. */
    for (register size_t i = 0; i < N; i++) {
        id[i] = i;
        sz[i] = 1;
    }
    while (FGETS(line) && sscanf(line, "%zu %zu", &p, &q) == 2) {
        if (p >= N || q >= N) continue;

        size_t i;
        size_t j;
        /* Perform Find operation with path compression by halving. */
        for (i = p; i != id[i]; i = id[i]) { id[i] = id[id[i]]; }
        for (j = q; j != id[j]; j = id[j]) { id[j] = id[id[j]]; }

        if (i == j) continue;

        /* Perform Union operation.
         * Ensure the smaller tree is always attached under the larger tree. */
        if (sz[i] < sz[j]) SWAP(i, j);
        id[j] = i;
        sz[i] += sz[j];

        printf(" %zu %zu\n", p, q);
    }
    return read_reached_feof(stdin) ? EXIT_SUCCESS : EXIT_FAILURE;
}