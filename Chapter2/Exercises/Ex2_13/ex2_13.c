/*
Exercise 2-13:
    Efficiently compute ceil(lg(lg(N))) without the use of a library function

    Utilises the fact that 2^(2^i) = 2^(2^(i - 1)) * 2^(2^(i - 1))
    to efficiently calculate the next possible term.
*/
#include <stdio.h>
#include <stdlib.h>
#include <tgmath.h>

/**
 * @brief maximum N for which to
 * compute ceil(lg(lg(N)))
 */
#define MAX_N 20

/**
 * @brief Calculate ceil(lg(lg(N)))
 */
size_t ceil_lglg(size_t N);

/**
 * @brief Calculate ceil(lg(lg(N)))  via our
 * function and by direct calculation
 * 
 * @return EXIT_SUCCESS
 */
int main(int argc, char* argv[argc + 1]) {
    for (size_t i = 2; i <= MAX_N; i++) {
        printf("N: %zu, By approx: %zu, By math Library: %f\n", 
            i, ceil_lglg(i), ceil(log2(log2(i))));
    }
    return EXIT_SUCCESS;
}

size_t ceil_lglg(size_t N) {
    size_t lglgN = 0;
    for (size_t t = 2; t < N; lglgN++, t *= t);
    return lglgN;
}
