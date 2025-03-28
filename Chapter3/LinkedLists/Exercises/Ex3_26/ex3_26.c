/*
Exercise 3.26
Write a function that given two pointers x and t to disjoint circular lists,
insert the list pointed to by t into the list pointed to by x at the point
after x

The driver code here will make one list with elements 1...N and one with
elements N + 1... 2N, x should be a number in the first list and t a
number in the second.
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
 * @brief Prints the list containing @head
 * treating @head as the start of the list
 * in the format key_head->key_{head -> next}
 * etc. The end of the list is denoted by ->X
 *
 * @param head node* to take as start of the list
 */
void print_list(node const* head);

/**
 * @brief Given a list containing @x and a seperate list
 * containing @t. the list containing @t is inserted
 * in the list containing @x after @x with @t being
 * treated as the head of the second list.
 *
 * @param x representative node of the first list
 * @param t representative node of the second list
 *
 * @exception if the @x and @t are in the same
 * list, the function terminates without merging.
 */
void merge_lists(node* const x, node* const t);

/**
 * @brief Test driver code for merge_lists. Creates
 * two lists of size @N, and then merges the list
 * containing @x and @t together where @N, @x and @t
 * are all command line arguments.
 *
 * Nodes in the first list are numbered 1 ... N
 * Nodes in the second list are numbered N+1 ... 2N
 *
 * @param argv[0] N, number of nodes in each list
 * @param argv[1] x, node in the first list to insert
 * the second list after, 0 < x <= N
 * @param argv[2] t, node from the second list to treat
 * as the head, N < x <= 2N
 *
 * @return EXIT_SUCCESS on sucessful completion else
 * @return EXIT_FAILURE
 */
int main(int argc, char* argv[argc + 1]) {
    if (argc != 4) {
        fprintf(stderr, "Error: Call structure is ./%s N x t\n", argv[0]);
        return EXIT_FAILURE;
    }
    register size_t const N = strtoull(argv[1], nullptr, 0);
    register key const x_idx = strtoull(argv[2], nullptr, 0);
    register key const t_idx = strtoull(argv[3], nullptr, 0);

    if (!(N && x_idx && t_idx)) {
        fprintf(stderr, "Error: N, x, t must all be > 0\n");
        return EXIT_FAILURE;
    }

    if (!(0 < x_idx && x_idx <= N)) {
        fprintf(stderr, "Error: x must be between 1 and N\n");
        return EXIT_FAILURE;
    }

    if (!(N < t_idx && t_idx <= 2 * N)) {
        fprintf(stderr, "Error: t must be between N+1 and 2N\n");
        return EXIT_FAILURE;
    }

    register node* t = calloc(1, SIZEOF_VARTYPE(*t));
    register node* x = t;
    register node* xp = t;

    t->item = 1, t->next = t;
    for (register size_t i = 2; i <= N; i++) {
        x = (x->next = calloc(1, SIZEOF_VARTYPE(*x)));
        x->item = i;
        x->next = t;
        if (i == x_idx) xp = x;
    }

    t = calloc(1, SIZEOF_VARTYPE(*t));
    x = t;
    register node* tp = t;

    t->item = N + 1, t->next = t;
    for (register key i = N + 2; i <= 2 * N; i++) {
        x = (x->next = calloc(1, SIZEOF_VARTYPE(*x)));
        x->item = i;
        x->next = t;
        if (i == t_idx) tp = x;
    }
    print_list(xp);
    print_list(tp);
    merge_lists(xp, tp);
    print_list(xp);

    return EXIT_SUCCESS;
}

void print_list(node const* head) {
    for (register node* t = head->next; t != head; t = t->next) {
        printf("%zu->", t->item);
    }
    printf("%zu\n", head->item);
}

void merge_lists(node* const xp, node* const tp) {
    register node* t_prev;
    for (t_prev = tp; t_prev->next != tp; t_prev = t_prev->next) {
        if (t_prev == xp) return;    // x and t in the same list
    }    // find the node linking to tp

    t_prev->next = xp->next;
    xp->next = tp;
}