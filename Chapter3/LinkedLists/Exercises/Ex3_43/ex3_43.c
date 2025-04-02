/*
Exercise 3.43

Implement a version of Program 3.9 that uses a head NODENode.
*/

#include "List/Node/Node.h"

#include <stdio.h>
#include <stdlib.h>

static inline NODEKey label_josephus_nodes(void) {
    return NODEgen_key_idx() + 1;
}
/**
 * @brief Calculate the Josephus function for a linear linked list with
 * a dummy head.
 *
 * @param h
 * @param m
 * @return NODEKey
 */
NODEKey calculate_josephus(NODENode h[static 1], size_t const m);
/**
 * @brief Determine the final person eliminated
 * in the Josephus problem consisting of N people
 * eliminating after M hops.
 *
 * @param argv[1] N - number of nodes > 0
 * @param argv[2] M - number of skips > 0
 *
 * If the list is empty then returns 0
 * @return EXIT_SUCCESS on successful termination else
 * @return EXIT_FAILURE
 */
int main(int argc, char* argv[argc + 1]) {
    if (argc != 3) {
        fprintf(stderr, "Usage is ./josephus N M\n");
        return EXIT_FAILURE;
    }
    size_t const N = strtoull(argv[1], nullptr, 0);
    size_t const M = strtoull(argv[2], nullptr, 0);
    if (!(N && M)) {
        fprintf(stderr, "Error: N and M must be > 0\n");
        return EXIT_FAILURE;
    }

    // initialise the list
    NODENode* const nodes =
        NODEbuild_lin_list_dummy_head(N, label_josephus_nodes);

    if (!nodes) return EXIT_FAILURE;

    printf("%zu\n", calculate_josephus(nodes, M));
    free(nodes);
    return EXIT_SUCCESS;
}

NODEKey calculate_josephus(NODENode h[static 1], size_t const m) {
    register NODENode* x = h;
    if (!h->next) return 0;
    while (h->next->next != nullptr) {
        for (register size_t i = 1; i < m; i++) {
            (x->next == nullptr) ? (x = h->next) : (x = x->next);
        }
        if (x->next)
            x->next = x->next->next;
        else { h->next = h->next->next; }
    }
    return h->next->k;
}