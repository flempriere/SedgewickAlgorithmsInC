/*
Exercise 3.37

Implement a function for linked lists that exchanges the positions of the
nodes after the nodes nodes referenced by two given links t and u.
*/

#include "../../../../MacroLibrary/Generic.h"
#include "../../../../MacroLibrary/Random.h"
#include "../../../../MacroLibrary/Utility.h"

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/**
 * @brief Exlusive upper bound for random node key values
 *
 */
constexpr unsigned int N = 10u;

/**
 * @brief Linked List node with
 * key and next element.
 */
typedef struct node node;

struct node {
    size_t k;
    node* next;
};

/**
 * @brief Print out the LinkedList starting
 * from the node head.
 *
 * @param head
 */
void print_list(node const* head);

/**
 * @brief Exchanges the nodes after @t
 * and @u
 *
 * @param t
 * @param u
 */
void exchange_after(node const* const t, node const* const u);

/**
 * @brief Tests ExchangeAfter by generating N
 * nodes numbered 1 to N and calling ExchangeAfter
 * on a random pair of nodes.
 *
 * @return EXIT_SUCCESS
 */
int main(int argc, char* argv[argc + 1]) {
    // generate a list of N nodes numbered 1 to 10 with a dummy head
    node* const nodes = calloc((N + 1), SIZEOF_VARTYPE(*nodes));

    RAND_SEED_TIME;
    for (register size_t i = 1; i <= N; i++) {
        nodes[i - 1].next = &nodes[i];
        nodes[i].k = i;
    }
    nodes[N].next = nullptr;

    printf("Initial List:\n");
    print_list(nodes);
    register size_t i = RAND_NUM(N + 1);
    register size_t j = RAND_NUM(N + 1);
    exchange_after(&nodes[i], &nodes[j]);
    printf("List after exchange of nodes after %zu & %zu\n", i, j);
    print_list(nodes);

    return EXIT_SUCCESS;
}

void print_list(node const* head) {
    for (head = head->next; head != nullptr; head = head->next) {
        printf("%zu->", head->k);
    }
    printf("X\n");
}

void exchange_after(node const* const t, node const* const u) {
    node* t_nxt = t->next;
    node* u_nxt = u->next;

    // return if either is nullptr or they are the same node
    if (!(t_nxt && u_nxt) || t == u) return;
    SWAP(t->next, u->next);
    SWAP(t_nxt->next, u_nxt->next);
}