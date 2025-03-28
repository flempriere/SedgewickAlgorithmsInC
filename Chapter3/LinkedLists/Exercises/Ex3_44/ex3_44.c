/*
Exercise 3.44

Implement a function that exchanges two given nodes on a
doubly linked list.

We use a dummy head and dummy tail representation
*/

#include "../../../../MacroLibrary/Generic.h"
#include "../../../../MacroLibrary/Random.h"
#include "../../../../MacroLibrary/Utility.h"

#include <stdio.h>
#include <stdlib.h>

/**
 * @brief Number of nodes to generate in test list
 *
 */
constexpr unsigned int N = 10u;

/**
 * @brief Generates an index between 1 and N
 *
 * @see @N
 */
#define GEN_IDX() (RAND_NUM(N) + 1)

/**
 * @brief Key type for node structure
 *
 */
typedef size_t key;

/**
 * @brief Doubly LinkedList node
 * consisting of a @key, next node
 * and prev node.
 *
 * @see key
 */
typedef struct node node;

struct node {
    key item;
    node* next;
    node* prev;
};

/**
 * @brief Prints a representation of the LinkedList
 * starting at h
 *
 * @param h node*
 */
void print_list(node const* h);

/**
 * @brief Prints a representation of the LinkedList
 * in reverse from h
 *
 * @param h node*
 */
void print_list_reverse(node const* h);
/**
 * @brief Exchanges the nodes x and t
 *
 * @param x
 * @param t
 */
void exchange_nodes(node* x, node* t);

/**
 * @brief Test driver for exchangeNodes(x, t).
 * Generates a list containing ten elements then
 * randomly swaps two of them.
 *
 * @return EXIT_SUCCESS
 */
int main(int argc, char* argv[argc + 1]) {
    node* const nodes = calloc(N + 2, SIZEOF_VARTYPE(*nodes));
    register node* head = nodes;
    register node* tail = &nodes[N + 1];
    // build list
    for (register size_t i = 1; i <= N + 1; i++) {
        nodes[i].item = i;
        nodes[i].prev = &nodes[i - 1];
        nodes[i - 1].next = &nodes[i];
    }
    head->prev = nullptr;
    tail->next = nullptr;

    printf("List before exchange:\n");
    print_list(head->next);
    print_list_reverse(tail->prev);

    RAND_SEED_TIME;
    register size_t const idx_1 = GEN_IDX();
    register size_t const idx_2 = GEN_IDX();

    printf("Exchange nodes %zu and %zu\n", idx_1, idx_2);
    exchange_nodes(&nodes[idx_1], &nodes[idx_2]);

    printf("List after exchange:\n");
    print_list(head->next);
    print_list_reverse(tail->prev);

    free(nodes);
    return EXIT_SUCCESS;
}

void print_list(node const* h) {
    for (; h->next != nullptr; h = h->next) { printf("%zu->", h->item); }
    printf("X\n");
}

void print_list_reverse(node const* h) {
    for (; h->prev != nullptr; h = h->prev) { printf("%zu->", h->item); }
    printf("X\n");
}

void exchange_nodes(node* x, node* t) {
    if (x == t) return;

    // x_p<->x<->x_nxt<->...<->t_p<->t<->t_nxt
    if (t->next == x) SWAP(x, t);
    register node* xn = x->next;
    register node* tp = t->prev;

    x->next = t->next;
    t->prev = x->prev;
    t->next->prev = x;
    x->prev->next = t;

    if (xn == t) {
        t->next = x;
        x->prev = t;
    } else {
        t->next = xn;
        xn->prev = t;

        x->prev = tp;
        tp->next = x;
    }
}
