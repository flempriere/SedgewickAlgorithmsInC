/*
Exercise 3.24
Write a function that returns the number of nodes on a circular list,
given a pointer to one of the nodes on the list
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
 * @brief Counts the number of nodes
 * on a given linkedlist @t.
 * 
 * @param t - node
 * @return size_t
 */
size_t countNodes(node* t);

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
int main(int argc, char* argv[argc+1]) {

    if (argc != 3) {
        fprintf(stderr, "Missing arguments N M\n");
        return EXIT_FAILURE;
    }
    size_t N = strtoull(argv[1], NULL, 0);
    size_t s_idx = strtoull(argv[2], NULL, 0);

    if (!N || !s_idx) {
        fprintf(stderr, "Error: N and M must be > 0\n");
        return EXIT_FAILURE;
    }

    if (s_idx > N) {
        fprintf(stderr, "Error: N must be greater than M\n");
        return EXIT_FAILURE;
    }

    node* t = malloc(sizeof(*t));
    node* x = t;
    node* s = t;

    t->item = 1, t->next = t;
    for (key i = 2; i <= N; i++) {
        x = (x->next = malloc(sizeof(*x)));
        x->item = i;
        x->next = t;
        if (i == s_idx) s = x;
    }
    printf("%zu\n", countNodes(s));
    return EXIT_SUCCESS;
}

size_t countNodes(node* t) {
    size_t sz = 1;
    for (node* s = t->next; s != t; s=s->next, sz++);
    return sz;
}