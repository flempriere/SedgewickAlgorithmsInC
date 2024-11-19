/*
Exercise 3.28

Modify program 3.28 to reduce the number of excessive circular loops it makes.
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
 * @brief Improves the efficiency of Program 3.9 
 * by relaxing the requirement that the list is
 * always circular to "the list is circular after
 * construction ends".
 * 
 * Otherwise identical to Program 3.9
 * @param argv[1] N, number of nodes
 * @param argv[2] M, number of nodes to count per elimination
 *  
 * @return EXIT_SUCCESS on successful completion else
 * @return EXIT_FAILURE
 */
int main(int argc, char* argv[argc+1]) {
    
    if (argc != 3) {
        fprintf(stderr, "Requires arguments N M\n");
        return EXIT_FAILURE;
    }

    size_t N = strtoull(argv[1], NULL, 0);
    size_t M = strtoull(argv[2], NULL, 0);

    if (!(N && M)) {
        fprintf(stderr, "N and M must both be > 0\n");
        return EXIT_FAILURE;
    }

    node* t = malloc(sizeof(*t));
    node* x = t;
    t->item = 1;
    t->next = t;

    for (key i = 2; i <= N; i++) {
        x = (x->next = malloc(sizeof(*x)));
        x->item = i;
    }
    x->next = t;
    while (x != x->next) {
        for (key i = 1; i < M; i++) x = x->next;
        x->next = x->next->next; N--;
    }
    printf("%zu\n", x->item);
    return EXIT_SUCCESS;
}