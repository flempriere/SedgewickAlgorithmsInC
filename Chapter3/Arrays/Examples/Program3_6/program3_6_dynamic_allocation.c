/**
 * @file program3_6_dynamic_allocation.c
 * @author Felix Lempriere
 * @brief Program 3.6: Dynamic Allocation of an Array.
 *
 * Demonstrates dynamically allocating an array.
 *
 * @date 2025-04-07
 * @version 0.1
 *
 * @copyright Copyright (c) 2025
 */

#include "MacroLibrary/DefaultCalloc.h"
#include "MacroLibrary/NumberParse.h"

#include <stdio.h>
#include <stdlib.h>

/**
 * @brief Dyamically allocates an array of size N
 *
 * @param argv[1] N
 * @return EXIT_SUCCESS if successful else EXIT_FAILURE
 */
int main(int argc, char* argv[argc + 1]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: ./app N\n");
        return EXIT_FAILURE;
    }

    register size_t const N = NUMPARSEexit_on_fail(N, argv[1]);

    size_t* const a = CALLOCEXIT_ON_FAIL(N, *a);

    printf("Allocated array of %zu bytes\n", N * sizeof(*a));
    free(a);
    return EXIT_SUCCESS;
}
