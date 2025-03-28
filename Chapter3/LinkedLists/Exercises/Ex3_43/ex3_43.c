/*
Exercise 3.43

Implement a version of Program 3.9 that uses a head node.
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
    node* const nodes = calloc(N + 1, SIZEOF_VARTYPE(*nodes));
    register node* head = nodes;

    // build list
    for (register size_t i = 1; i <= N; i++) {
        nodes[i].item = i;
        nodes[i - 1].next = &nodes[i];
    }
    nodes[N].next = nullptr;

    register node* x = head;
    while (head->next->next != nullptr) {
        for (register size_t i = 1; i < M; i++) {
            x = x->next;
            if (!x) x = head->next;    // reach end of list
        }
        if ((x->next))
            x->next = x->next->next;
        else { head->next = head->next->next; }
    }
    printf("%zu\n", head->next->item);
    return EXIT_SUCCESS;
}