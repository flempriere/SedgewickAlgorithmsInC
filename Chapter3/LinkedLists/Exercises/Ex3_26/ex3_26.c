/*
Exercise 3.26
Write a function that given two pointers x and t to disjoint circular lists,
insert the list pointed to by t into the list pointed to by x at the point
after x

The driver code here will make one list with elements 1...N and one with
elements N + 1... 2N, x should be a number in the first list and t a
number in the second.
*/

#include "../../../../MacroLibrary/NumberParse.h"
#include "../Ex3_24/src/Node.h"

#include <stdio.h>
#include <stdlib.h>

/**
 * @brief Given a list containing @x and a seperate list
 * containing @t. the list containing @t is inserted
 * in the list containing @x after @x with @t being
 * treated as the head of the second list.
 *
 * @param x representative Node of the first list
 * @param t representative Node of the second list
 *
 * @exception if the @x and @t are in the same
 * list, the function terminates without merging.
 */
void merge_lists(NODENode x[static 1], NODENode t[static 1]);

/**
 * @brief Builds a list for testing. Has nodes labelled srt_key up to n
 * inclusive, and sets the pointer idx to point to the x_idx labelled Node.
 *
 * @param n
 * @param srt_key
 * @param x_idx
 * @param idx
 * @return Node*
 */
NODENode* build_list(size_t const n, size_t const srt_key, size_t x_idx,
                 NODENode* idx[static 1]);
/**
 * @brief Test driver code for merge_lists. Creates
 * two lists of size @N, and then merges the list
 * containing @x and @t together where @N, @x and @t
 * are all command line arguments.
 *
 * Nodes in the first list are numbered 1 ... N
 * Nodes in the second list are numbered N+1 ... 2N
 *
 * @param argv[0] N, number of nodes in each list
 * @param argv[1] x, Node in the first list to insert
 * the second list after, 0 < x <= N
 * @param argv[2] t, Node from the second list to treat
 * as the head, N < x <= 2N
 *
 * @return EXIT_SUCCESS on sucessful completion else
 * @return EXIT_FAILURE
 */
int main(int argc, char* argv[argc + 1]) {
    if (argc != 4) {
        fprintf(stderr, "Error: Call structure is ./%s N x t\n", argv[0]);
        return EXIT_FAILURE;
    }
    register size_t const N = NUMPARSEexit_on_fail(N, argv[1]);
    register NODEKey const x_idx = NUMPARSEexit_on_fail(x_idx, argv[2]);
    register NODEKey const t_idx = NUMPARSEexit_on_fail(t_idx, argv[3]);

    if (!(N && x_idx && t_idx)) {
        fprintf(stderr, "Error: N, x, t must all be > 0\n");
        return EXIT_FAILURE;
    }

    if (!(0 < x_idx && x_idx <= N)) {
        fprintf(stderr, "Error: x must be between 1 and N\n");
        return EXIT_FAILURE;
    }

    if (!(N < t_idx && t_idx <= 2 * N)) {
        fprintf(stderr, "Error: t must be between N+1 and 2N\n");
        return EXIT_FAILURE;
    }

    NODENode* xp;
    build_list(N, 1, x_idx, &xp);

    NODENode* tp;
    build_list(2 * N, N + 1, t_idx, &tp);

    NODEprint_circular_list(xp);
    NODEprint_circular_list(tp);
    merge_lists(xp, tp);
    NODEprint_circular_list(xp);

    NODEdelete_circular_list(xp);
    return EXIT_SUCCESS;
}

void merge_lists(NODENode xp[static 1], NODENode tp[static 1]) {
    register NODENode* t_prev;
    for (t_prev = tp; t_prev->next != tp; t_prev = t_prev->next) {
        if (t_prev == xp) return;    // x and t in the same list
    }    // find the Node linking to tp

    t_prev->next = xp->next;
    xp->next = tp;
}

NODENode* build_list(size_t n, size_t srt_key, size_t x_idx, NODENode* idx[static 1]) {
    register NODENode* t = NODEmake_node(1, nullptr);
    t->next = nullptr;

    register NODENode* x = t;
    *idx = t;

    t->k = srt_key++, t->next = t;
    for (register size_t i = srt_key; i <= n; i++) {
        x = (x->next = CALLOC_FAILS_EXIT(*x));
        x->k = i;
        x->next = t;
        if (i == x_idx) *idx = x;
    }
    return t;
}