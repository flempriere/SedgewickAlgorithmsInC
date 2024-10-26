/*
Exercise 2.33: Give a table of the values of C_n for 1 <= N <= 32,
interpreting N/2 as ceil(N/2) for the formula

C_N = C_(N/2) + N for N >= 2 with C_1 = 1
*/

#include <stddef.h>
#include <stdio.h>

#define N 32
#define IS_EVEN(x) !((x) % 2)

size_t coefficient_N(size_t n);

int main(int argc, char* argv[argc + 1]) {
    for (size_t i = 1; i <= N; i++) {
        printf("n: %zu, C_n: %zu\n", i, coefficient_N(i));
    }
    return 0;
}

size_t coefficient_N(size_t n) {
    size_t sum = 0;
    for (size_t i = n; i != 1; i = (i + 1) / 2) {
        sum += i;
    }
    return sum;
}


