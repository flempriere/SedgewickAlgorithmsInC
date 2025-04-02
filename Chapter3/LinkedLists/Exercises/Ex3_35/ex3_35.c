/*
Exercise 3.35

Write a function that moves the smallest item on a given list to the be
first Node on a list

*/
#include "List/Node/Node.h"
#include "MacroLibrary/NumberParse.h"
#include "MacroLibrary/Random.h"

#include <stdio.h>
#include <stdlib.h>
/**
 * @brief Number of random nodes to generate for test driver
 *
 */
constexpr size_t DEFAULT_N = 10u;

/**
 * @brief move the smallest element of the list
 * starting at h to the start of the list.
 *
 * @param h
 */
void move_smallest_to_front(NODENode h[static 1]);

/**
 * @brief Checks that the smallest element of the list
 * starting at h is at the end.
 *
 * @return true if the first element is the smallest else
 * @return false
 */
bool assert_smallest_at_front(NODENode const h[static 1]);

int main(int argc, char* argv[argc + 1]) {
    // generate a list of N random numbers with a dummy head
    register size_t const N =
        (argc == 2) ? NUMPARSEexit_on_fail(N, argv[1]) : DEFAULT_N;

    RAND_SEED_TIME;

    NODENode* const nodes = NODEbuild_lin_list_dummy_head(N, NODEgen_key_rand);
    if (!nodes) return EXIT_FAILURE;

    printf("Initial List:\n");
    NODEprint_null_terminated_list(nodes[0].next);

    move_smallest_to_front(nodes);

    printf("List after smallest moved to front:\n");
    NODEprint_null_terminated_list(nodes[0].next);

    printf("Smallest at the front?: %s\n",
           (assert_smallest_at_front(nodes) ? "true" : "false"));

    free(nodes);
    return EXIT_SUCCESS;
}

void move_smallest_to_front(NODENode h[static 1]) {
    if (!(h->next)) return;             // empty list
    register NODENode* min_pred = h;    // the predecessor to the current min
    for (register NODENode* cur = h->next; cur->next; cur = cur->next) {
        if (cur->next->k < min_pred->next->k) min_pred = cur;
    }
    if (min_pred == h) return;    // min element is first

    register NODENode* min = min_pred->next;
    min_pred->next = min->next;
    min->next = h->next;
    h->next = min;
}

bool assert_smallest_at_front(NODENode const h[static 1]) {
    h = h->next;
    if (!h) return true;    // list has only one element.
    register size_t smallest = h->k;
    for (h = h->next; h != nullptr; h = h->next) {
        if (h->k < smallest) return false;
    }
    return true;
}
