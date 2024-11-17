/*
Function definition demonstration.

Observe that the program is seperated into the function declaration

int lg(int x) which declares a function returning an int, which operates on
an int. 

and the function definition which provides a concrete implementation.
*/

#include <stdio.h>
#include <stdlib.h>

/**
 * @brief Computes log2(x) for integer
 * arguments
 * 
 */
size_t lg(size_t x);

/**
 * @brief Tabulate N, lg(N) and Nlg(N)
 * for N = 1 to 6.
 *
 * @return EXIT_SUCCESS
 */
int main(int argc, char* argv[argc + 1]) {
    int N = 10;
    for (size_t i = 1; i <= 6; i++, N *= 10) {
        printf("%7zu %2zu %9zu\n", N, lg(N), N*lg(N));
    }
    return EXIT_SUCCESS;
}

size_t lg(size_t N) {
    
    size_t i;
    for (i = 0; N > 0; i++, N /= 2);
    return i;
}