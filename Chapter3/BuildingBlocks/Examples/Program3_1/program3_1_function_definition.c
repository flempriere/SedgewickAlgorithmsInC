/*
Function definition demonstration.

Observe that the program is seperated into the function declaration

size_t lg(size_t x) which declares a function returning an int, which operates
on an int.

and the function definition which provides a concrete implementation.
*/

#include <stdio.h>
#include <stdlib.h>

/**
 * @brief Computes log2(x) for integer
 * arguments
 *
 */
size_t lg(size_t n);

/**
 * @brief Tabulate N, lg(N) and Nlg(N)
 * for N = 1 to 6.
 *
 * @return EXIT_SUCCESS
 */
int main(int argc, char* argv[argc + 1]) {
    register size_t N = 10u;
    for (register size_t i = 1; i <= 6; i++, N *= 10) {
        printf("%7zu %2zu %9zu\n", N, lg(N), N * lg(N));
    }
    return EXIT_SUCCESS;
}

size_t lg(size_t n) {
    register size_t i;
    for (i = 0; n > 0; i++, n /= 2);
    return i;
}