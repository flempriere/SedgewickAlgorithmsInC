/*
Exercise 3.28

Modify Program 3.9 to reduce the number of excessive circular loops it makes.
*/

#include "List/Node/Node.h"
#include "MacroLibrary/NumberParse.h"

#include <stdio.h>
#include <stdlib.h>

/**
 * @brief Builds a josephus list of size n and returns a pointer to the head
 * of the list.
 *
 * @param n
 * @return Node*
 */
NODENode* build_list(size_t const n);

/**
 * @brief Improves the efficiency of Program 3.9
 * by relaxing the requirement that the list is
 * always circular to "the list is circular after
 * construction ends".
 *
 * Otherwise identical to Program 3.9
 * @param argv[1] N, number of nodes
 * @param argv[2] M, number of nodes to count per elimination
 *
 * @return EXIT_SUCCESS on successful completion else
 * @return EXIT_FAILURE
 */
int main(int argc, char* argv[argc + 1]) {
    if (argc != 3) {
        fprintf(stderr, "Requires arguments N M\n");
        return EXIT_FAILURE;
    }

    register size_t const N = NUMPARSEexit_on_fail(N, argv[1]);
    register size_t const M = NUMPARSEexit_on_fail(M, argv[2]);

    if (!(N && M)) {
        fprintf(stderr, "N and M must both be > 0\n");
        return EXIT_FAILURE;
    }

    register NODENode* t = build_list(N);
    if (!t) return EXIT_FAILURE;
    printf("%zu\n", NODEcalculate_josephus(t, M));

    return EXIT_SUCCESS;
}

NODENode* build_list(size_t const n) {
    NODENode* t = NODEmake_node(1, nullptr);
    if (!t) return nullptr;
    register NODENode* x = t;

    for (register NODEKey i = 2; i <= n; i++) {
        x = (x->next = NODEmake_node(i, nullptr));
        if (!x) return NODEclean_failed_build(t);
    }
    x->next = t;
    return x;
}