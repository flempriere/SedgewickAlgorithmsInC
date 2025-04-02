/*
Exercise 3.30
Run Program 3.9 for M = 2,3,5,10 and N = 10^3, 10^4, 10^5, 10^6.
*/

#include "List/Node/Node.h"

#include <stdio.h>
#include <stdlib.h>

/**
 * @brief Number of distinct M values to test
 *
 */
constexpr size_t M_CASES = 4u;

/**
 * @brief Number of distinct N values to test
 *
 */
constexpr size_t N_CASES = 4u;

static inline NODEKey label_josephus_node(void) {
    return NODEgen_key_idx() + 1;
}
/**
 * @brief Determines the value of the Josephus function
 * for a precompiled array of N and M values.
 *
 * @return EXIT_SUCCESS on completion
 */
int main(int argc, char* argv[argc + 1]) {
    constexpr size_t mArray[] = { 2, 3, 5, 10 };
    constexpr size_t nArray[] = { 10000, 100000, 1000000, 10000000 };

    for (register size_t i = 0; i < N_CASES; i++) {
        register size_t N = nArray[i];
        for (register size_t j = 0; j < M_CASES; j++) {
            register size_t M = mArray[j];

            register NODENode* x =
                NODEbuild_circular_list(N, label_josephus_node);
            if (!x) return EXIT_FAILURE;
            printf("N: %zu, M: %zu, Result: %zu\n", N, M,
                   NODEcalculate_josephus(x, M));
        }
    }
    return EXIT_SUCCESS;
}