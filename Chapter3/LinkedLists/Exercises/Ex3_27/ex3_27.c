/*
Exercise 3.27
Write a function that given two pointers x and t to elements in a list,
moves the Node following t to the Node following x.
*/

#include "../../../../MacroLibrary/NumberParse.h"
#include "../Ex3_24/src/Node.h"

#include <stdio.h>
#include <stdlib.h>

/**
 * @brief Moves the Node following @t to the position
 * following the Node following @x.
 *
 * i.e. if t' = t->next and x' = x->next pre function
 * call, post function call x'->next = t'.
 *
 * Note we preseve the rest of the list ordering, i.e.
 * t->next becomes equivalent to t->next->next before the
 * function call, and t'->next = x'->next before the call.
 * @param x Node such that x->next->next becomes t->next
 * @param t Node such that t->next becomes x->next->next
 */
void move_node(NODENode x[const static 1], NODENode t[const static 1]);

NODENode* setup_list(size_t const n, size_t const srt_idx, NODENode* srt[static 1],
                 size_t const stp_idx, NODENode* stp[static 1]);
/**
 * @brief Test driver code for moveNodes. Creates
 * a list of size @N, and then calls @moveNode to
 * move @t->next to @x->next->next.
 *
 * @param argv[0] N, number of nodes in the list
 * @param argv[1] x, Node such that after the fn call
 * x->next->next = t' (where t' is the original t->next)
 * @param argv[2] t, Node such that the current t->next
 * becomes x->next->next
 *
 * @return EXIT_SUCCESS on sucessful completion else
 * @return EXIT_FAILURE
 *
 * @see moveNode
 */
int main(int argc, char* argv[argc + 1]) {
    if (argc != 4) {
        fprintf(stderr, "Missing arguments N x t\n");
        return EXIT_FAILURE;
    }

    register size_t const N = NUMPARSEexit_on_fail(N, argv[1]);
    register size_t const x_idx = NUMPARSEexit_on_fail(x_idx, argv[2]);
    register size_t const t_idx = NUMPARSEexit_on_fail(t_idx, argv[3]);

    if (!(N && x_idx && t_idx)) {
        fprintf(stderr, "Error: N, x, t must all be > 0\n");
        return EXIT_FAILURE;
    }

    if (!(0 < x_idx && x_idx <= N)) {
        fprintf(stderr, "Error: x must be between 1 and N\n");
        return EXIT_FAILURE;
    }

    if (!(0 < t_idx && t_idx <= N)) {
        fprintf(stderr, "Error: t must be between N+1 and 2N\n");
        return EXIT_FAILURE;
    }
    NODENode* srt;
    NODENode* stp;

    setup_list(N, x_idx, &srt, t_idx,
               &stp);    // need to cast since can't convert to const

    printf("List premove: \n");
    NODEprint_circular_list(srt);
    move_node(srt, stp);
    printf("List postmove: \n");
    NODEprint_circular_list(srt);

    NODEdelete_circular_list(srt);

    return EXIT_SUCCESS;
}

void move_node(NODENode x[const static 1], NODENode t[const static 1]) {
    // edge case: (x == t)
    // t->(t_nxt_nxt)->(t_nxt)->...
    if (x == t) {
        register NODENode* t_nxt = t->next;
        t->next = t_nxt->next;
        t_nxt->next = t->next->next;
        t->next->next = t_nxt;
    } else {
        register NODENode* t_nxt = t->next;
        register NODENode* x_nxt = x->next;

        t->next = t_nxt->next;
        t_nxt->next = x_nxt->next;
        x_nxt->next = t_nxt;
    }
}

NODENode* setup_list(size_t const n, size_t const srt_idx, NODENode* srt[static 1],
                 size_t const stp_idx, NODENode* stp[static 1]) {
    register NODENode* t = NODEmake_node(1, nullptr);
    *srt = t;
    *stp = t;

    t->next = t;

    register NODENode* x = t;
    for (register size_t i = 2; i <= n; i++) {
        x = (x->next = NODEmake_node(i, t));
        if (i == srt_idx) *srt = x;
        if (i == stp_idx) *stp = x;
    }
    return t;
}