/*
Exercise 3.31
Run Program 3.9 plot the results for M = 10, with N = 2 to 1000.
*/

#include "../Ex3_24/src/Node.h"

#include <stdio.h>
#include <stdlib.h>

/**
 * @brief Maximum value of N to run the Josephus
 * function for.
 */
constexpr size_t N_MAX = 1000u;

/**
 * @brief Records the value of the Josephus function
 * varying N from 2 to 1000 with M fixed equal to 10.
 *
 * @return EXIT_SUCCESS
 */
int main(int argc, char* argv[argc + 1]) {
    constexpr size_t M = 10;

    for (register size_t N = 2; N < N_MAX; N++) {
        register NODENode* t = NODEbuild_josephus_list(N);
        printf("N: %zu, f(N): %zu\n", N, NODEcalculate_josephus(t, M));
    }
    return EXIT_SUCCESS;
}