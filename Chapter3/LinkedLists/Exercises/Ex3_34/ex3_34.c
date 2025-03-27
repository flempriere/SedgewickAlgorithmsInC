/*
Exercise 3.34

Write a function that moves the largest item on a given list to be
the final node on a list.

*/
#include "../../../../MacroLibrary/Random.h"
#include "../../../../MacroLibrary/Utility.h"

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/**
 * @brief Number of random nodes to generate for test driver
 *
 */
constexpr size_t DEFAULT_N = 10u;
/**
 * @brief Exlusive upper bound for random node key values
 *
 */
constexpr unsigned int MAX_NUM = 100u;
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
 * @brief move the largest element of the list
 * starting at h to the end of the list.
 *
 * @param h
 */
void move_largest_to_end(node* h);

/**
 * @brief Checks that the largest element of the list
 * starting at h is at the end.
 *
 * @return true if the last element is the largest else
 * @return false
 */
bool assert_largest_at_end(node const* h);

/**
 * @brief Test driver for moveLargestToEnd, generates
 * either default_N or up to N nodes depending on if
 * N is provided as a command line argument, then moves
 * the largest to the end.
 *
 * @param argc
 * @param argv
 * @return int
 */
int main(int argc, char* argv[argc + 1]) {
    // generate a list of N random numbers with a dummy head
    register size_t const N =
        (argc == 2) ? strtoull(argv[1], nullptr, 0) : DEFAULT_N;
    node* const nodes = calloc((N + 1), SIZEOF_VARTYPE(*nodes));

    RAND_SEED_TIME;
    for (register size_t i = 1; i <= N; i++) {
        register size_t k = RAND_NUM(MAX_NUM);
        nodes[i - 1].next = &nodes[i];
        nodes[i].k = k;
    }
    nodes[N].next = nullptr;

    printf("Initial List:\n");
    print_list(nodes);
    move_largest_to_end(nodes);
    printf("List after largest moved to end:\n");
    print_list(nodes);
    printf("Largest at the end?: %s\n",
           (assert_largest_at_end(nodes) ? "true" : "false"));

    free(nodes);
    return EXIT_SUCCESS;
}

void print_list(node const* head) {
    for (head = head->next; head != nullptr; head = head->next) {
        printf("%zu->", head->k);
    }
    printf("X\n");
}

void move_largest_to_end(node* h) {
    if (!(h->next)) return;    // empty list
    node* max_pred = h;        // the predecessor to the current max
    for (h = h->next; h->next; h = h->next) {
        if (h->next->k > max_pred->next->k) max_pred = h;
    }
    if (max_pred->next == h) return;    // max element is the last
    node* max = max_pred->next;
    max_pred->next = max->next;
    h->next = max;
    max->next = nullptr;
}

bool assert_largest_at_end(node const* h) {
    size_t largest_seen = 0;
    for (h = h->next; h->next != nullptr; h = h->next) {
        largest_seen = (largest_seen > h->k) ? largest_seen : h->k;
    }
    return ((h->k >= largest_seen) ? true : false);
}