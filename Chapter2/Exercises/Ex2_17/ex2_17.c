/*
Give a simple expression for floor(lg(F_n))

F_n = round(phi^N/sqrt(5)) -> goes up or down by 0.5 small term
lg(F_n) = lg(phi^N) - lg(sqrt(5))
= N*lg(phi) - 0.5*lg(5)

This program will overflow on the calculating the 94th Fibonnaci number
with a 64bit size_t type.

use exact table for n = 0, 1, 2, 3 and return SIZE_MAX to signify -inf.
*/

#include <stdlib.h>
#include <tgmath.h>
#include <stdio.h>
#include <stdint.h>

/**
 * @brief Largest order Fibonnaci
 * number to calculate.
 */
#define MAX_INT 50

/**
 * @brief Calculates the N-th Fibonacchi number
 * 
 */
size_t FIBONACCHI_NUMBER(size_t N);

/**
 * @brief approximates lg(F_N)
 * 
 */
size_t APPROX_LG_FIB(size_t N);

/**
 * @brief Calculates lg(F_N) exactly.
 * 
 */
size_t EXACT_LG_FIB(size_t N);

/**
 * @brief Calculates floor(lg(F_N)) using
 * an exact and simple approach.
 * 
 * @return EXIT_SUCCESS 
 */
int main(int argc, char* argv[argc + 1]) {

    for (size_t i = 1; i < MAX_INT; i++) {
        printf("N: %zu, F_n: %zu, approx: %zu, exact: %zu\n",
            i, FIBONACCHI_NUMBER(i), APPROX_LG_FIB(i), EXACT_LG_FIB(i));
    }
    return EXIT_SUCCESS;
}

size_t FIBONACCHI_NUMBER(size_t N)
{
    //cache for calculated values
    static size_t FIB_NUM[MAX_INT] = {0, 1};
    static size_t MAX_N = 1; //max calculated fib num;

    while(++MAX_N <= N) {
        FIB_NUM[MAX_N] = FIB_NUM[MAX_N - 1] + FIB_NUM[MAX_N - 2];
    }
    --MAX_N;
    return FIB_NUM[N];
}

size_t APPROX_LG_FIB(size_t N)
{
    #ifndef GOLDEN_RATIO
        #define GOLDEN_RATIO 1.61803L
    #endif
    static size_t exact_sln[] = {SIZE_MAX, 0, 0, 1};
    if (N <= 3) return exact_sln[N];

    return floor(N*log2(GOLDEN_RATIO) - 0.5L*log2(5.0L));
}

size_t EXACT_LG_FIB(size_t N) {
    return floor(log2(FIBONACCHI_NUMBER(N)));
}
