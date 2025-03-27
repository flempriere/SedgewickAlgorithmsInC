/*
Exercise 3.36

Write a function that rearranges a linked list to put the nodes in even
positions after the nodes in odd positions in the list, preversing the
relative order of both the evens and the odds.

*/
#include "../../../../MacroLibrary/Generic.h"
#include "../../../../MacroLibrary/Random.h"
#include "../../../../MacroLibrary/Utility.h"

#include <stdio.h>
#include <stdlib.h>

/**
 * @brief Number of random nodes to generate for test driver
 *
 */
constexpr size_t N = 10u;

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
 * @brief Rearrange a linked list to put
 * the sublist of even indices before the
 * sublist of odd indices. The relative
 * order of each sublist is preserved.
 *
 * @param h
 */
void partition_odds_and_evens(node* const h);

/**
 * @brief Driver program to demonstrate PartitionOddsAndEvens.
 * We generate a list containing N elements keyed by their
 * position and then partition.
 *
 * @return int
 */
int main(int argc, char* argv[argc + 1]) {
    // generate a list of N random numbers with a dummy head
    node* const nodes = calloc(N + 1, SIZEOF_VARTYPE(*nodes));

    for (register size_t i = 1; i <= N; i++) {
        nodes[i - 1].next = &nodes[i];
        nodes[i].k = i;
    }
    nodes[N].next = nullptr;

    printf("Initial List:\n");
    print_list(nodes);
    partition_odds_and_evens(nodes);
    printf("List after partition:\n");
    print_list(nodes);

    return EXIT_SUCCESS;
}

void print_list(node const* head) {
    for (head = head->next; head != nullptr; head = head->next) {
        printf("%zu->", head->k);
    }
    printf("X\n");
}

void partition_odds_and_evens(node* const h) {
    register node* odd_head = calloc(1, SIZEOF_VARTYPE(*h));
    register node* odd_tail = odd_head;
    register node* even_head = calloc(1, SIZEOF_VARTYPE(*h));
    register node* even_tail = even_head;

    // build two lists, one for odd, one for even
    register node* cur = h->next;
    for (register size_t idx = 0; cur != nullptr; cur = cur->next, idx++) {
        if (IS_EVEN(idx)) {
            even_tail->next = cur;
            even_tail = cur;
        } else {
            odd_tail->next = cur;
            odd_tail = cur;
        }
    }
    // merge the odd and even lists
    even_tail->next = nullptr;
    odd_tail->next = even_head->next;
    h->next = odd_head->next;
    free(even_head);
    free(odd_head);
}