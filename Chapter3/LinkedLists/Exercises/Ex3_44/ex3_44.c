/*
Exercise 3.44

Implement a function that exchanges two given nodes on a
doubly linked list.

We use a dummy head and dummy tail representation
*/

#include <stdlib.h>
#include <stdio.h>
#include <time.h>

/**
 * @brief Number of nodes to generate in test list
 * 
 */
#define N 10

/**
 * @brief Generates an index between 1 and N
 * 
 * @see @N
 */
#define GEN_IDX() ((rand() % N) + 1)

#define SWAP(x,y) do {  \
    typeof(x) _t = x;   \
    x = y;              \
    y = _t;             \
} while(0)              \
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
void LISTprintList(node* h);

/**
 * @brief Prints a representation of the LinkedList
 * in reverse from h
 * 
 * @param h node*
 */
void printListReverse(node* h);
/**
 * @brief Exchanges the nodes x and t
 * 
 * @param x 
 * @param t 
 */
void exchangeNodes(node* x, node* t);


/**
 * @brief Test driver for exchangeNodes(x, t).
 * Generates a list containing ten elements then
 * randomly swaps two of them.
 * 
 * @return EXIT_SUCCESS
 */
int main(int argc, char* argv[argc+1]) {

    node* nodes = malloc((N+2)*sizeof(typeof_unqual(*nodes)));
    node* head = nodes;
    node* tail = &nodes[N+1];
    //build list
    for (size_t i = 1; i <= N+1; i++) {
        nodes[i].item = i;
        nodes[i].prev = &nodes[i-1];
        nodes[i-1].next = &nodes[i];
    }
    head->prev = nullptr;
    tail->next = nullptr;

    printf("List before exchange:\n");
    LISTprintList(head->next);
    printListReverse(tail->prev);

    srand(time(nullptr));
    size_t idx_1 = GEN_IDX();
    size_t idx_2 = GEN_IDX();

    printf("Exchange nodes %zu and %zu\n", idx_1, idx_2);
    exchangeNodes(&nodes[idx_1], &nodes[idx_2]);

    printf("List after exchange:\n");
    LISTprintList(head->next);
    printListReverse(tail->prev);

    return EXIT_SUCCESS; 
}

void LISTprintList(node* h) {
    for (; h->next != nullptr; h = h->next) {
        printf("%zu->", h->item);
    }
    printf("X\n");
}

void printListReverse(node* h) {

    for (; h->prev != nullptr; h = h->prev) {
        printf("%zu->", h->item);
    }
    printf("X\n");
}

void exchangeNodes(node* x, node* t) {
    if (x == t) return;

    //x_p<->x<->x_nxt<->...<->t_p<->t<->t_nxt
    if (t->next == x) SWAP(x,t);
    node* xn = x->next;
    node* tp = t->prev;

    x->next = t->next;
    t->prev = x->prev;
    t->next->prev = x;
    x->prev->next = t;

    if (xn == t) {
        t->next = x;
        x->prev = t;
    }
    else {
        t->next = xn;
        xn->prev = t;

        x->prev = tp;
        tp->next = x;
    }
}
