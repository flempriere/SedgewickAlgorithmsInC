/*
Exercise 3.35

Write a function that moves the smallest item on a given list to the be
first node on a list

*/
#include "../../../../MacroLibrary/DefaultCalloc.h"
#include "../../../../MacroLibrary/NumberParse.h"
#include "../../../../MacroLibrary/Random.h"

#include <stdio.h>
#include <stdlib.h>
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
 * @brief move the smallest element of the list
 * starting at h to the start of the list.
 *
 * @param h
 */
void move_smallest_to_front(node* const h);

/**
 * @brief Checks that the smallest element of the list
 * starting at h is at the end.
 *
 * @return true if the first element is the smallest else
 * @return false
 */
bool assert_smallest_at_front(node const* h);

int main(int argc, char* argv[argc + 1]) {
    // generate a list of N random numbers with a dummy head
    register size_t const N =
        (argc == 2) ? NUMPARSEexit_on_fail(N, argv[1]) : DEFAULT_N;
    node* const nodes = CALLOC_FAILS_EXIT(N + 1, *nodes);

    RAND_SEED_TIME;

    for (register size_t i = 1; i <= N; i++) {
        register size_t k = RAND_NUM(MAX_NUM);
        nodes[i - 1].next = &nodes[i];
        nodes[i].k = k;
    }
    nodes[N].next = nullptr;

    printf("Initial List:\n");
    print_list(nodes);

    move_smallest_to_front(nodes);

    printf("List after smallest moved to front:\n");
    print_list(nodes);

    printf("Smallest at the front?: %s\n",
           (assert_smallest_at_front(nodes) ? "true" : "false"));

    free(nodes);
    return EXIT_SUCCESS;
}

void print_list(node const* head) {
    for (head = head->next; head != nullptr; head = head->next) {
        printf("%zu->", head->k);
    }
    printf("X\n");
}

void move_smallest_to_front(node* const h) {
    if (!(h->next)) return;         // empty list
    register node* min_pred = h;    // the predecessor to the current min
    for (register node* cur = h->next; cur->next; cur = cur->next) {
        if (cur->next->k < min_pred->next->k) min_pred = cur;
    }
    if (min_pred == h) return;    // min element is first

    register node* min = min_pred->next;
    min_pred->next = min->next;
    min->next = h->next;
    h->next = min;
}

bool assert_smallest_at_front(node const* h) {
    h = h->next;
    register size_t smallest = h->k;
    for (h = h->next; h != nullptr; h = h->next) {
        if (h->k < smallest) return false;
    }
    return true;
}
