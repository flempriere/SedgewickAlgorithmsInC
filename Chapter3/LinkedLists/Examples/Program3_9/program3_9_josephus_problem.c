/*
Program 3.9

Solves the josephus problem. Arranging N Nodes in a circle, we go around
the circle M times an eliminate the corresponding Node. We then close the circle
and repeat until there is one index left.
*/

#include "MacroLibrary/DefaultCalloc.h"
#include "MacroLibrary/NumberParse.h"
#include "MacroLibrary/Utility.h"

#include <stdio.h>
#include <stdlib.h>

/**
 * @brief Key type for Node structure
 *
 */
typedef size_t key;

/**
 * @brief LinkedList Node
 * consisting of a @key
 * and next Node.
 *
 * @see key
 */
typedef struct Node Node;

struct Node {
    key item;
    Node* next;
};

static inline Node* make_node(key k, Node* nxt) {
    Node* t = CALLOC_FAILS_EXIT(*t);
    *t = CAST(Node){ .item = k, .next = nxt };
    return t;
}
/**
 * @brief Builds a list of N Nodes for the josephus problem and returns the
 * head of the list.
 *
 * @param N
 * @return Node*
 */
Node* build_list(size_t const n);

/**
 * @brief Evaluate the Josephus problem and return the final key.
 *
 * @remark frees the Nodes as they are deleted.
 *
 * @param h Starting point on the list.
 * @param m number of hops before elimination.
 * @return key
 */
key compute_josephus(Node h[static 1], size_t const m);
/**
 * @brief Determine the final person eliminated
 * in the Josephus problem consisting of N people
 * eliminating after M hops.
 *
 * @param argv[1] N - number of Nodes > 0
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
    register size_t const N = NUMPARSEexit_on_fail(N, argv[1]);
    register size_t const M = NUMPARSEexit_on_fail(M, argv[2]);

    if (!(N && M)) {
        fprintf(stderr, "Error: N and M must be > 0\n");
        return EXIT_FAILURE;
    }

    register Node* t = build_list(N);
    register key res = compute_josephus(t, M);
    printf("%zu\n", res);

    return EXIT_SUCCESS;
}

Node* build_list(size_t const n) {
    if (!n) return nullptr;
    Node* t = make_node(1, nullptr);
    t->next = t;
    register Node* x = t;
    for (register size_t i = 2; i <= n; i++) {
        x->next = make_node(i, t);
        x = x->next;
    }
    return x;
}

key compute_josephus(Node h[static 1], size_t const m) {
    while (h != h->next) {
        for (register size_t i = 1; i < m; i++) h = h->next;
        register Node* tmp = h->next;
        h->next = h->next->next;
        free(tmp);
    }
    key k = h->item;
    free(h);
    return k;
}