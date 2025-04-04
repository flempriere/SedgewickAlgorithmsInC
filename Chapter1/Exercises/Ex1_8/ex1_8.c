/**
 * @file ex1_8.c
 * @author Felix Lempriere
 * @brief Implementation of Exercise 1-8 from Chapter 1 of Sedgewick's
 * Algorithms in C.
 *
 * This program demonstrates the [Path Compression by
 * Halving](../../Examples/Program1_4/UnionFind_1_4.c) algorithm by:
 * - Showing the state of the `id` array after processing each input pair.
 * - Counting the total number of array accesses (overall and per edge).
 *
 * @details For each valid pair of integers `p` and `q` (both less than `N`):
 * - If `p` and `q` are not connected, it connects them and prints the pair.
 * - After each union operation, the program prints the current state of the
 *   `id[]` array.
 * - Tracks and displays the number of array accesses for each pair and the
 *   cumulative total of array accesses.
 *
 * @version 0.1
 * @date 2025-03-28
 * @copyright Copyright (c) 2025
 */

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
 * @brief Outputs the specified number of elements from an array to the standard
 * output.
 *
 * @param len length of the array, should be greater than zero.
 * @param a An array with a minimum size of `len`.
 */
void print_array(size_t const len, size_t const a[static len]);

/**
 * @brief Reads input pairs `p` and `q` from standard input and performs union
 * operations using the Weighted Quick Union with path compression by halving
 * algorithm showing the array state and number of array accesses
 * after each pair is processed..
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
    register size_t tot_access = 0;
    char line[MAXLINE];

    for (register size_t i = 0; i < N; i++) {
        id[i] = i;
        sz[i] = 1;
    }
    while (fgets(line, sizeof(line), stdin) &&
           sscanf(line, "%zu %zu", &p, &q) == 2) {
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
        print_array(N, id);
    updateArrayAccesses:
        printf("array acceses for (%zu, %zu): %zu\n", p, q, n_access);
        tot_access += n_access;
    }
    printf("Total accesses: %zu\n", tot_access);
    return read_reached_feof(stdin) ? EXIT_SUCCESS : EXIT_FAILURE;
}

void print_array(size_t const len, size_t const a[static len]) {
    for (register size_t i = 0; i < len; i++) printf(" %zu", a[i]);
    printf("\n");
}
