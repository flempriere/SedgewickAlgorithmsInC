/*
Exercise 3.27
Write a function that given two pointers x and t to elements in a list,
moves the node following t to the node following x.
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
void print_list(node const* const head);

/**
 * @brief Moves the node following @t to the position
 * following the node following @x.
 *
 * i.e. if t' = t->next and x' = x->next pre function
 * call, post function call x'->next = t'.
 *
 * Note we preseve the rest of the list ordering, i.e.
 * t->next becomes equivalent to t->next->next before the
 * function call, and t'->next = x'->next before the call.
 * @param x node such that x->next->next becomes t->next
 * @param t node such that t->next becomes x->next->next
 */
void move_node(node* const x, node* const t);

/**
 * @brief Test driver code for moveNodes. Creates
 * a list of size @N, and then calls @moveNode to
 * move @t->next to @x->next->next.
 *
 * @param argv[0] N, number of nodes in the list
 * @param argv[1] x, node such that after the fn call
 * x->next->next = t' (where t' is the original t->next)
 * @param argv[2] t, node such that the current t->next
 * becomes x->next->next
 *
 * @return EXIT_SUCCESS on sucessful completion else
 * @return EXIT_FAILURE
 *
 * @see moveNode
 */
int main(int argc, char* argv[argc + 1]) {
    if (argc != 4) {
        fprintf(stderr, "Missing arguments N x t\n");
        return EXIT_FAILURE;
    }

    register size_t const N = strtoull(argv[1], nullptr, 0);
    register size_t const x_idx = strtoull(argv[2], nullptr, 0);
    register size_t const t_idx = strtoull(argv[3], nullptr, 0);

    if (!(N && x_idx && t_idx)) {
        fprintf(stderr, "Error: N, x, t must all be > 0\n");
        return EXIT_FAILURE;
    }

    if (!(0 < x_idx && x_idx <= N)) {
        fprintf(stderr, "Error: x must be between 1 and N\n");
        return EXIT_FAILURE;
    }

    if (!(0 < t_idx && t_idx <= N)) {
        fprintf(stderr, "Error: t must be between N+1 and 2N\n");
        return EXIT_FAILURE;
    }

    register node* const t = calloc(1, SIZEOF_VARTYPE(*t));
    register node* x = t;
    register node* srt = t;
    register node* stp = t;

    t->item = 1, t->next = t;
    for (register key i = 2; i <= N; i++) {
        x = (x->next = calloc(1, SIZEOF_VARTYPE(*x)));
        x->item = i;
        x->next = t;
        if (i == x_idx) srt = x;
        if (i == t_idx) stp = x;
    }
    printf("List premove: \n");
    print_list(srt);
    move_node(srt, stp);
    printf("List postmove: \n");
    print_list(srt);
    return EXIT_SUCCESS;
}

void print_list(node const* const head) {
    for (register node const* t = head->next; t != head; t = t->next) {
        printf("%zu->", t->item);
    }
    printf("%zu\n", head->item);
}

void move_node(node* const x, node* const t) {
    // edge case: (x == t)
    // t->(t_nxt_nxt)->(t_nxt)->...
    if (x == t) {
        register node* t_nxt = t->next;
        t->next = t_nxt->next;
        t_nxt->next = t->next->next;
        t->next->next = t_nxt;
    } else {
        register node* t_nxt = t->next;
        register node* x_nxt = x->next;

        t->next = t_nxt->next;
        t_nxt->next = x_nxt->next;
        x_nxt->next = t_nxt;
    }
}