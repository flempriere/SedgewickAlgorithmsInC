/*
Program 3.9

Solves the josephus problem. Arranging N nodes in a circle, we go around
the circle M times an eliminate the corresponding node. We then close the circle
and repeat until there is one index left.
*/

#include <stdlib.h>
#include <stdio.h>

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
int main(int argc, char* argv[argc+1]) {
    
    if (argc != 3) {
        fprintf(stderr, "Requires arguments N M\n");
        return EXIT_FAILURE;
    }
    size_t N = strtoull(argv[1], NULL, 0);
    size_t M = strtoull(argv[2], NULL, 0);

    node* t = malloc(sizeof(*t));
    node* x = t;
    t->item = 1;
    t->next = t;

    for (size_t i = 2; i <= N; i++) {
        x = (x->next = malloc(sizeof(*x)));
        x->item = i;
        x->next = t;
    }
    while (x != x->next) {
        for (size_t i = 1; i < M; i++) x = x->next;
        x->next = x->next->next; N--;
    }
    printf("%zu\n", x->item);
    return EXIT_SUCCESS;
}