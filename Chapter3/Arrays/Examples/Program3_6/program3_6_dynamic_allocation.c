/*
Program 3.6
Demonstrates dynamic memory allocation to have a variably sized array for use
in programs such as the sieve of eratosthenes.

This takes in the size of the array to allocate as a command line argument

*/

#include <stdlib.h>
#include <stdio.h>

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

    size_t N = strtoull(argv[1], nullptr, 0);

    size_t* a = malloc(N*sizeof(typeof_unqual(*a)));
    return EXIT_SUCCESS;
}

