/**
 * @file ex1_4.c
 * @author Felix Lempriere
 * @brief Implementation of Exercise 1-4 from Chapter 1 of Sedgewick's
 * Algorithms in C.
 *
 * This program demonstrates the [Quick
 * Find](../../Examples/Program1_1/UnionFind_1_1.c) algorithm from by:
 * - Showing the state of the `id` array after processing each input pair.
 * - Counting the total number of array accesses (overall and per edge).
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
constexpr size_t N = 10u;

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
 * @brief Processes input pairs `p, q < N` from standard input to perform union
 * operations.
 *
 * This program reads pairs of integers `p` and `q` from standard input, where
 * both values must be less than `N`. For each pair:
 * - If `p` and `q` are not already connected, it performs a union operation and
 * prints the pair.
 * - After each union operation, the contents of the `id[]` array are printed.
 * - The program also tracks and prints the number of array accesses for each
 * input pair and the total number of array accesses during the program's
 * execution.
 *
 * If either `p` or `q` is greater than or equal to `N`, the input pair is
 * ignored.
 *
 * @exception if p or q is not less than N the input
 * pair is ignored
 *
 * @return Returns `EXIT_SUCCESS` upon successful execution or EXIT_FAILURE if
 * an error occurs while reading input..
 */
int main(void) {
    size_t p;
    size_t q;
    size_t id[N];
    register size_t tot_accesses = 0;
    char line[MAXLINE];

    /* initialise id array so each element is its own component.*/
    for (register size_t i = 0; i < N; i++) id[i] = i;

    while (FGETS(line) && sscanf(line, "%zu %zu", &p, &q) == 2) {
        if (p >= N || q >= N) continue;    // bounds checking

        register size_t n_accesses = 0;
        n_accesses += 2;
        if (id[p] == id[q]) {
            goto updateArrayAccesses;
        }
        /* Perform union operations */
        register size_t t = id[p];
        for (register size_t i = 0; i < N; i++) {
            n_accesses += 1;
            if (id[i] == t) {
                id[i] = id[q];
                n_accesses += 2;
            }
        }
        printf(" %zu %zu\n", p, q);
    updateArrayAccesses:
        print_array(N, id);
        printf("array accesses for (%zu, %zu): %zu\n", p, q, n_accesses);
        tot_accesses += n_accesses;
    }
    printf("Total accesses: %zu\n", tot_accesses);
    return read_reached_feof(stdin) ? EXIT_SUCCESS : EXIT_FAILURE;
}

void print_array(size_t const len, size_t const a[static len]) {
    for (register size_t i = 0; i < len; i++) printf(" %zu", a[i]);
    printf("\n");
}
