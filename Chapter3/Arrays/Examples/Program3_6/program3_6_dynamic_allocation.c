/*
Program 3.6
Demonstrates dynamic memory allocation to have a variably sized array for use
in programs such as the sieve of eratosthenes.

This takes in the size of the array to allocate as a command line argument

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

    size_t* const a = CALLOC_FAILS_EXIT(N, *a);

    printf("Allocated array of %zu bytes\n", N * sizeof(*a));
    free(a);
    return EXIT_SUCCESS;
}
