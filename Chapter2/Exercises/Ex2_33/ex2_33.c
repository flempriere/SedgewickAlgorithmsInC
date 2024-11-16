/*
Exercise 2.33: Give a table of the values of C_n for 1 <= N <= 32,
interpreting N/2 as floor(N/2) for the formula

C_N = C_(N/2) + 1 for N >= 2 with C_1 = 1
*/

#include <stdlib.h>
#include <stdio.h>

/**
 * @brief max N to determine the
 * coefficient for.
 * 
 */
#define N 32

/**
 * @brief check if x is even
 * @return true if even, else false
 */
#define IS_EVEN(x) !((x) % 2)

/**
 * @brief Calculate C_N
 * 
 */
size_t coefficient_N(size_t n);

/**
 * @brief Calculate the coefficients C_N
 * for n = 1 up to 32.
 * 
 * @return EXIT_SUCCESS
 */
int main(int argc, char* argv[argc + 1]) {
    for (size_t i = 1; i <= N; i++) {
        printf("n: %zu, C_n: %zu\n", i, coefficient_N(i));
    }
    return EXIT_SUCCESS;
}

size_t coefficient_N(size_t n) {
    size_t i;
    for (i = 0; n != 0; n /= 2, i++);
    return i;
}


