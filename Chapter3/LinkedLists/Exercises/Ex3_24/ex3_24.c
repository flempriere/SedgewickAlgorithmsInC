/*
Exercise 3.24
Write a function that returns the number of nodes on a circular list,
given a pointer to one of the nodes on the list
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
 * @brief Counts the number of nodes
 * on a given linkedlist @t.
 *
 * @param t - node
 * @return size_t
 */
size_t count_nodes(node const* const t);

/**
 * @brief Test driver for count nodes,
 * generates a linkedlist of length @N
 * and starts the counts nodes from the
 * @M-th node.
 *
 * @param argv[0] - number of nodes in list
 * @param argv[1] - node to start count from.
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

    register node* const t = CALLOC_FAILS_EXIT(*t);
    register node* x = t;
    register node const* s = t;    // pointer to start count from.

    t->item = 1, t->next = t;
    for (register key i = 2; i <= N; i++) {
        x = (x->next = CALLOC_FAILS_EXIT(*x));
        x->item = i;
        x->next = t;
        if (i == s_idx) s = x;
    }
    printf("%zu\n", count_nodes(s));
    return EXIT_SUCCESS;
}

size_t count_nodes(node const* const t) {
    size_t sz = 1;
    for (register node const* s = t->next; s != t; s = s->next, sz++);
    return sz;
}