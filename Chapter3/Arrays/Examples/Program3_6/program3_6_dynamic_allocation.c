/*
Program 3.6
Demonstrates dynamic memory allocation to have a variably sized array for use
in programs such as the sieve of eratosthenes.

This takes in the size of the array to allocate as a command line argument

*/

#include <stdlib.h>
#include <stdio.h>

int main(int argc, char* argv[argc + 1]) {

    size_t N = strtoull(argv[1], NULL, 0);

    size_t* a = malloc(N*sizeof(typeof_unqual(*a)));
    return 0;
}

