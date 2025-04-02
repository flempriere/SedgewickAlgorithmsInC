/*
Exercise 3.44

Implement a function that exchanges two given nodes on a
doubly linked list.

We use a dummy head and dummy tail representation
*/

#include "MacroLibrary/DefaultCalloc.h"
#include "MacroLibrary/Generic.h"
#include "MacroLibrary/Random.h"
#include "MacroLibrary/Utility.h"

#include <stdio.h>
#include <stdlib.h>

/**
 * @brief Number of nodes to generate in test list
 *
 */
constexpr unsigned int N = 10u;

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

typedef struct h_and_t {
    node* head;
    node* tail;
} h_and_t;

struct node {
    key item;
    node* next;
    node* prev;
};
/**
 * @brief builds a doubly linked list consisting of n
 * real nodes and a dummy head and tail.
 *
 * @param n
 * @return h_and_t struct containing the head and tail pointers.
 * If build fails the head and tail are set to nullptr.
 */
h_and_t build_list(size_t n);
/**
 * @brief Generates an index between 1 and N
 *
 * @see @N
 */
#define GEN_IDX() (RANDUINT(N, 1))

/**
 * @brief Prints a representation of the LinkedList
 * starting at h
 *
 * @param h node*
 */
void print_list(node const h[static 1]);

/**
 * @brief Prints a representation of the LinkedList
 * in reverse from h
 *
 * @param h node*
 */
void print_list_reverse(node const h[static 1]);
/**
 * @brief Exchanges the nodes x and t
 *
 * @param x
 * @param t
 */
void exchange_nodes(node x[static 1], node t[static 1]);

/**
 * @brief Test driver for exchangeNodes(x, t).
 * Generates a list containing ten elements then
 * randomly swaps two of them.
 *
 * @return EXIT_SUCCESS
 */
int main(int argc, char* argv[argc + 1]) {
    h_and_t ht = build_list(N);
    node* head = ht.head;
    node* tail = ht.tail;
    if (!(head && tail)) return EXIT_FAILURE;

    printf("List before exchange:\n");
    print_list(head->next);
    print_list_reverse(tail->prev);

    RAND_SEED_TIME;

    register size_t const idx_1 = GEN_IDX();
    register size_t const idx_2 = GEN_IDX();

    printf("Exchange nodes %zu and %zu\n", idx_1, idx_2);
    exchange_nodes(&head[idx_1], &head[idx_2]);

    printf("List after exchange:\n");
    print_list(head->next);
    print_list_reverse(tail->prev);

    free(head);
    return EXIT_SUCCESS;
}

h_and_t build_list(size_t n) {
    node* nodes = DEFAULTCALLOC(n + 2, *nodes);
    if (!nodes) return CAST(h_and_t){ .head = nullptr, .tail = nullptr };
    register node* head = nodes;
    register node* tail = &nodes[n + 1];
    // build list
    for (register size_t i = 1; i <= n + 1; i++) {
        nodes[i].item = i;
        nodes[i].prev = &nodes[i - 1];
        nodes[i - 1].next = &nodes[i];
    }
    head->prev = nullptr;
    tail->next = nullptr;
    return CAST(h_and_t){ .head = head, .tail = tail };
}

void print_list(node const h[static 1]) {
    for (; h->next != nullptr; h = h->next) { printf("%zu->", h->item); }
    printf("X\n");
}

void print_list_reverse(node const h[static 1]) {
    for (; h->prev != nullptr; h = h->prev) { printf("%zu->", h->item); }
    printf("X\n");
}

void exchange_nodes(node x[static 1], node t[static 1]) {
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
