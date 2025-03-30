/*
Exercise 2-13:
    Efficiently compute ceil(lg(lg(N))) without the use of a library function

    Utilises the fact that 2^(2^i) = 2^(2^(i - 1)) * 2^(2^(i - 1))
    to efficiently calculate the next possible term.
*/
#include "../../../MacroLibrary/Utility.h"

#include <stdio.h>
#include <stdlib.h>
#include <tgmath.h>

/**
 * @brief maximum N for which to
 * compute ceil(lg(lg(N)))
 */
constexpr size_t MAX_N = 20u;

/**
 * @brief Calculate ceil(lg(lg(N)))
 */
unsigned int ceil_lglg(unsigned long long const n);

/**
 * @brief Calculate ceil(lg(lg(N)))  via our
 * function and by direct calculation
 *
 * @return EXIT_SUCCESS
 */
int main(int argc, char* argv[argc + 1]) {
    for (register size_t i = 2; i <= MAX_N; i++) {
        printf("N: %zu, By approx: %u, By math Library: %Lf\n", i, ceil_lglg(i),
               ceil(log2(log2(CAST(long double) i))));
    }
    return EXIT_SUCCESS;
}

unsigned int ceil_lglg(unsigned long long const n) {
    register size_t lglgN = 0;
    for (register size_t t = 2; t < n; lglgN++, t *= t);
    return CAST(unsigned) lglgN;
}
