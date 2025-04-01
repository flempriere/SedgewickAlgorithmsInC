/*
Exercise 3.24
Write a function that returns the number of nodes on a circular list,
given a pointer to one of the nodes on the list
*/

#include "../../../../MacroLibrary/NumberParse.h"
#include "src/Node.h"

#include <stdio.h>
#include <stdlib.h>

/**
 * @brief builds the list for the count nodes returning the pointer set at
 * s_idx for counting on a circular list.
 *
 * @param n
 * @param s_idx
 * @return Node*
 */
NODENode* build_list(size_t const n, size_t const s_idx);

/**
 * @brief Delete the circular list pointed to by h
 *
 * @param h
 */
void delete_list(NODENode* h);
/**
 * @brief Counts the number of nodes
 * on a given linkedlist @t.
 *
 * @param t - Node
 * @return size_t
 */
size_t count_nodes(NODENode const t[const static 1]);

/**
 * @brief Test driver for count nodes,
 * generates a linkedlist of length @N
 * and starts the counts nodes from the
 * @M-th Node.
 *
 * @param argv[0] - number of nodes in list
 * @param argv[1] - Node to start count from.
 * @return EXIT_SUCCESS on completion else
 * @return EXIT_FAILURE
 */
int main(int argc, char* argv[argc + 1]) {
    if (argc != 3) {
        fprintf(stderr, "Missing arguments N M\n");
        return EXIT_FAILURE;
    }
    register size_t const N = NUMPARSEexit_on_fail(N, argv[1]);
    register size_t const s_idx = NUMPARSEexit_on_fail(s_idx, argv[2]);

    if (!(N && s_idx)) {
        fprintf(stderr, "Error: N and M must be > 0\n");
        return EXIT_FAILURE;
    }

    if (s_idx > N) {
        fprintf(stderr, "Error: N must be greater than M\n");
        return EXIT_FAILURE;
    }

    NODENode* s = build_list(N, s_idx);
    printf("%zu\n", count_nodes(s));

    NODEdelete_circular_list(s);
    return EXIT_SUCCESS;
}

size_t count_nodes(NODENode const t[const static 1]) {
    size_t sz = 1;
    for (register NODENode const* s = t->next; s != t; s = s->next, sz++);
    return sz;
}

NODENode* build_list(size_t const n, size_t const s_idx) {
    register NODENode* t = NODEmake_node(1, nullptr);
    t->next = t;
    register NODENode* s = t;
    register NODENode* x = t;
    for (register NODEKey i = 2; i <= n; i++) {
        x = (x->next = NODEmake_node(i, t));
        if (i == s_idx) s = x;
    }
    return s;
}