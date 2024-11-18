/*
Exercise 3.25
Write a function that returns the number of nodes between two pointers x and
t on a circular linked list.
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
size_t countNodesBetween(node* x, node* t);

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
int main(int argc, char* argv[argc+1]) {

    if (argc != 4) {
        fprintf(stderr, "Error: call structure ./%s N x t\n", argv[0]);
        return EXIT_FAILURE;
    }

    size_t N = strtoull(argv[1], NULL, 0);
    size_t x_idx = strtoull(argv[2], NULL, 0);
    size_t t_idx = strtoull(argv[3], NULL, 0);

    if (!(N && x_idx && t_idx)) {
        fprintf(stderr, "Error: N, x and t must all be > 0\n");
        return EXIT_FAILURE;
    }
    if (x_idx > N || t_idx > N) {
        fprintf(stderr, "Error: N must be >= x and t");
        return EXIT_FAILURE;
    }

    node* t = malloc(sizeof(*t));
    node* x = t;
    node* srt = t;
    node* stp = t;

    t->item = 1, t->next = t;
    for (key i = 2; i <= N; i++) {
        x = (x->next = malloc(sizeof(*x)));
        x->item = i;
        x->next = t;
        if (i == x_idx) srt = x;
        if (i == t_idx) stp = x;
    }
    printf("%zu\n", countNodesBetween(srt, stp));
    return EXIT_FAILURE;
}

size_t countNodesBetween(node* x, node* t) {
    size_t sz = 0;
    for (; x != t; x=x->next, sz++);
    return sz;
}