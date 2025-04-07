/**
 * @file UnionFind_1_1.c
 * @author Felix Lempriere
 * @brief Quick-find solution to the connectivity problem.
 *
 * @details
 * This program reads a sequence of pairs of non-negative integers less than N
 * from standard input. Each pair `p q` represents a connection between `p` and
 * `q`.
 *
 * The array `id[N]` maintains the property that `id[p]` and `id[q]` are equal
 * if and only if `p` and `q` are connected.
 *
 * - **Complexity**:
 *   - Each union operation is linear in length because all entries need to be
 * updated.
 *   - Each find operation is constant time, as it only involves testing
 * equality.
 *
 * @note This implementation is a simple and direct approach to solving the
 * connectivity problem but is not efficient for large datasets due to its
 * linear-time union operation.
 *
 * @version 0.1
 * @date 2025-04-07
 *
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
 * @brief Processes input pairs of integers `p` and `q` (both less than N)
 * from standard input, checks their connectivity, and performs a union
 * operation if they are not already connected.
 *
 * @exception Input pairs where either `p` or `q` is not less than `N` are
 * ignored.
 *
 * @return EXIT_SUCCESS if the program completes successfully, or EXIT_FAILURE
 * if an error occurs while reading input.
 */
int main(int argc, char* argv[argc+1]) {
    size_t p;
    size_t q;
    size_t id[N];
    char line[MAXLINE];    // input buffer

    // Initialize the id array where each element is its own component.
    for (register size_t i = 0; i < N; i++) id[i] = i;
    while (FGETS(line) && sscanf(line, "%zu %zu", &p, &q) == 2) {
        if (p >= N || q >= N) continue;    // bounds checking
        if (id[p] == id[q]) continue;

        // Perform union operation
        register size_t t = id[p];
        for (register size_t i = 0; i < N; i++) {
            if (id[i] == t) id[i] = id[q];
        }

        printf(" %zu %zu\n", p, q);
    }
    return read_reached_feof(stdin) ? EXIT_SUCCESS : EXIT_FAILURE;
}