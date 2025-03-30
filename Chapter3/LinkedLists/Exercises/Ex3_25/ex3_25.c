/*
Exercise 3.25
Write a function that returns the number of nodes between two pointers x and
t on a circular linked list.
*/

#include "../../../../MacroLibrary/DefaultCalloc.h"
#include "../../../../MacroLibrary/NumberParse.h"

#include <stdio.h>
#include <stdlib.h>

/**
 * @brief Key type for node structure
 *
 */
typedef size_t key;
/**
 * @brief LinkedList node
 * consisting of a @key
 * and next node.
 *
 * @see key
 */
typedef struct node node;
struct node {
    key item;
    node* next;
};

/**
 * @brief Counts the number of nodes between
 * @x and @t, including @t if @t != @x.
 * The call is directed i.e. the number
 * of nodes is counted from @x to @t, which may be
 * different than those from @t to @x.
 *
 * @param x starting node
 * @param t terminating node
 * @return size_t, 0 if @x == @t else > 0
 */
size_t count_nodes_between(node const* x, node const* t);

/**
 * @brief Test driver for countNodesBetween
 * reads @N, @x, @t from the command line, then
 * generates a list of size @N, and calls
 * countNodesBetween to determine the number
 * of nodes between the @x-th and @t-th node.
 *
 * @param argv[1] N, number of nodes
 * @param argv[2] x, node to start count from
 * @param argv[3] t, node to count until.
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

    register node* const t = CALLOC_FAILS_EXIT(*t);
    register node* x = t;
    register node const* srt = t;
    register node const* stp = t;

    t->item = 1, t->next = t;
    for (register key i = 2; i <= N; i++) {
        x = (x->next = CALLOC_FAILS_EXIT(*x));
        x->item = i;
        x->next = t;
        if (i == x_idx) srt = x;
        if (i == t_idx) stp = x;
    }
    printf("%zu\n", count_nodes_between(srt, stp));

    for (register node* h = t->next; h != t;) {
        register node* tmp = h->next;
        free(h);
        h = tmp;
    }
    free(t);
    return EXIT_SUCCESS;
}

size_t count_nodes_between(node const* x, node const* t) {
    register size_t sz = 0;
    for (; x != t; x = x->next, sz++);
    return sz;
}