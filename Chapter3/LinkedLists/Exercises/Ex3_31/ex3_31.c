/*
Exercise 3.31
Run Program 3.9 plot the results for M = 10, with N = 2 to 1000.
*/

#include "List/Node/Node.h"

#include <stdio.h>
#include <stdlib.h>

/**
 * @brief Maximum value of N to run the Josephus
 * function for.
 */
constexpr size_t N_MAX = 1000u;

static inline NODEKey label_josephus_node(void) {
    return NODEgen_key_idx() + 1;
}
/**
 * @brief Records the value of the Josephus function
 * varying N from 2 to 1000 with M fixed equal to 10.
 *
 * @return EXIT_SUCCESS
 */
int main(int argc, char* argv[argc + 1]) {
    constexpr size_t M = 10;

    for (register size_t N = 2; N < N_MAX; N++) {
        register NODENode* t = NODEbuild_circular_list(N, label_josephus_node);
        if (!t) return EXIT_FAILURE;
        printf("N: %zu, f(N): %zu\n", N, NODEcalculate_josephus(t, M));
    }
    return EXIT_SUCCESS;
}