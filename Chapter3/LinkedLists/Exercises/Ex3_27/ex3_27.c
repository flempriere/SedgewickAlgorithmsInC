/*
Exercise 3.27
Write a function that given two pointers x and t to elements in a list,
moves the node following t to the node following x.
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
 * @brief Prints the list containing @head
 * treating @head as the start of the list
 * in the format key_head->key_{head -> next}
 * etc. The end of the list is denoted by ->X
 * 
 * @param head node* to take as start of the list
 */
void printList(node* head);

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
void moveNode(node* x, node* t);

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
int main(int argc, char* argv[argc+1]) {

    if (argc != 4) {
        fprintf(stderr, "Missing arguments N x t\n");
        return EXIT_FAILURE;
    }

    size_t N = strtoull(argv[1], NULL, 0);
    size_t x_idx = strtoull(argv[2], NULL, 0);
    size_t t_idx = strtoull(argv[3], NULL, 0);

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
    printf("List premove: \n");
    printList(srt);
    moveNode(srt, stp);
    printf("List postmove: \n");
    printList(srt);
    return EXIT_SUCCESS;
}

void printList(node* head) {
    for (node* t = head->next; t != head; t = t->next) {
        printf("%zu->", t->item);
    }
    printf("%zu\n", head->item);
}

void moveNode(node* x, node* t) {

    //edge case: (x == t)
    //t->(t_nxt_nxt)->(t_nxt)->...
    if (x == t) {

        node* t_nxt = t->next;
        t->next = t_nxt->next;
        t_nxt->next = t->next->next;
        t->next->next = t_nxt;
    } else {
        node* t_nxt = t->next;
        node* x_nxt = x->next;

        t->next = t_nxt->next;
        t_nxt->next = x_nxt->next;
        x_nxt->next = t_nxt;
    }
}