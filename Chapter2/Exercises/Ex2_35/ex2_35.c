/*
Exercise 2.35: Give a table of the values of C_n for 1 <= N <= 32,
interpreting N/2 as ceil(N/2) for the formula

C_N = C_(N/2) + N for N >= 2 with C_1 = 1
*/
#include <stdio.h>

/**
 * @brief max N to determine the
 * coefficient for.
 *
 */
constexpr size_t N = 32u;

/**
 * @brief Calculate C_N
 *
 */
unsigned long long coefficient_N(size_t n);

/**
 * @brief Calculate the coefficients C_N
 * for n = 1 up to 32.
 *
 * @return EXIT_SUCCESS
 */
int main(int argc, char* argv[argc + 1]) {
    for (register size_t i = 1; i <= N; i++) {
        printf("n: %zu, C_n: %llu\n", i, coefficient_N(i));
    }
    return 0;
}

unsigned long long coefficient_N(size_t n) {
    register size_t sum = 0;
    for (register size_t i = n; i != 1; i = (i + 1) / 2) { sum += i; }
    return sum;
}
