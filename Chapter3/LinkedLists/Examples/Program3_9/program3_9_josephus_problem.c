/*
Program 3.9

Solves the josephus problem. Arranging N nodes in a circle, we go around
the circle M times an eliminate the corresponding node. We then close the circle
and repeat until there is one index left.
*/

#include "../../../../MacroLibrary/Utility.h"

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
 * @brief Determine the final person eliminated
 * in the Josephus problem consisting of N people
 * eliminating after M hops.
 *
 * @param argv[1] N - number of nodes > 0
 * @param argv[2] M - number of skips > 0
 *
 * @return EXIT_SUCCESS on successful termination else
 * @return EXIT_FAILURE
 */
int main(int argc, char* argv[argc + 1]) {
    if (argc != 3) {
        fprintf(stderr, "Requires arguments N M\n");
        return EXIT_FAILURE;
    }
    register size_t const N = strtoull(argv[1], nullptr, 0);
    register size_t const M = strtoull(argv[2], nullptr, 0);

    if (!(N && M)) {
        fprintf(stderr, "Error: N and M must be > 0\n");
        return EXIT_FAILURE;
    }

    register node* const t = calloc(1, SIZEOF_VARTYPE(*t));
    register node* x = t;
    t->item = 1;
    t->next = t;

    for (register size_t i = 2; i <= N; i++) {
        x = (x->next = calloc(1, SIZEOF_VARTYPE(*x)));
        x->item = i;
        x->next = t;
    }
    while (x != x->next) {
        for (register size_t i = 1; i < M; i++) x = x->next;
        register node* tmp = x->next;
        x->next = x->next->next;
        free(tmp);
    }
    printf("%zu\n", x->item);
    free(x);
    return EXIT_SUCCESS;
}