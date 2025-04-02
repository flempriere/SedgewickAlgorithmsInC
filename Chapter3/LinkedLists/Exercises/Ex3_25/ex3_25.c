/*
Exercise 3.25
Write a function that returns the number of nodes between two pointers x and
t on a circular linked list.
*/

#include "List/Node/Node.h"
#include "MacroLibrary/NumberParse.h"

#include <stdio.h>
#include <stdlib.h>

/**
 * @brief Counts the number of nodes between
 * @x and @t, including @t if @t != @x.
 * The call is directed i.e. the number
 * of nodes is counted from @x to @t, which may be
 * different than those from @t to @x.
 *
 * @param x starting Node
 * @param t terminating Node
 * @return size_t, 0 if @x == @t else > 0
 */
size_t count_nodes_between(NODENode const x[static 1],
                           NODENode const t[static 1]);

/**
 * @brief Set the up list objects
 *
 * @param n
 * @param srt_idx
 * @param srt
 * @param stp_idx
 * @param stp
 * @return Node* head of the list on success, else
 * @return nullptr
 */
NODENode* setup_list(size_t const n, size_t const srt_idx,
                     NODENode const* srt[static 1], size_t const stp_idx,
                     NODENode const* stp[static 1]);

/**
 * @brief Test driver for countNodesBetween
 * reads @N, @x, @t from the command line, then
 * generates a list of size @N, and calls
 * countNodesBetween to determine the number
 * of nodes between the @x-th and @t-th Node.
 *
 * @param argv[1] N, number of nodes
 * @param argv[2] x, Node to start count from
 * @param argv[3] t, Node to count until.
 * @return EXIT_SUCCESS on successful completion else
 * @return EXIT_FAILURE
 */
int main(int argc, char* argv[argc + 1]) {
    if (argc != 4) {
        fprintf(stderr, "Error: call structure ./%s N x t\n", argv[0]);
        return EXIT_FAILURE;
    }

    register size_t const N = NUMPARSEexit_on_fail(N, argv[1]);
    register size_t const x_idx = NUMPARSEexit_on_fail(x_idx, argv[2]);
    register size_t const t_idx = NUMPARSEexit_on_fail(t_idx, argv[3]);

    if (!(N && x_idx && t_idx)) {
        fprintf(stderr, "Error: N, x and t must all be > 0\n");
        return EXIT_FAILURE;
    }
    if (x_idx > N || t_idx > N) {
        fprintf(stderr, "Error: N must be >= x and t");
        return EXIT_FAILURE;
    }

    NODENode const* srt;
    NODENode const* stp;
    register NODENode* t = setup_list(N, x_idx, &srt, t_idx, &stp);
    if (!t) return EXIT_FAILURE;
    printf("%zu\n", count_nodes_between(srt, stp));

    NODEdelete_circular_list(t);
    return EXIT_SUCCESS;
}

size_t count_nodes_between(NODENode const x[static 1],
                           NODENode const t[static 1]) {
    register size_t sz = 0;
    for (; x != t; x = x->next, sz++);
    return sz;
}

NODENode* setup_list(size_t const n, size_t const srt_idx,
                     NODENode const* srt[static 1], size_t const stp_idx,
                     NODENode const* stp[static 1]) {
    register NODENode* t = NODEmake_node(1, nullptr);
    if (!t) return nullptr;
    t->next = t;
    *srt = t;
    *stp = t;

    register NODENode* x = t;
    for (register size_t i = 2; i <= n; i++) {
        x = (x->next = NODEmake_node(i, t));
        if (!x) {
            NODEdelete_circular_list(t);
            return nullptr;
        }
        if (i == srt_idx) *srt = x;
        if (i == stp_idx) *stp = x;
    }
    return t;
}