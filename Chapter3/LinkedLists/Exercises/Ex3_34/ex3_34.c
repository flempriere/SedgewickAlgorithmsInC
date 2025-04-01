/*
Exercise 3.34

Write a function that moves the largest item on a given list to be
the final Node on a list.

*/
#include "../../../../MacroLibrary/NumberParse.h"
#include "../../../../MacroLibrary/Random.h"
#include "../Ex3_24/src/Node.h"

#include <stdio.h>
#include <stdlib.h>

/**
 * @brief Number of random nodes to generate for test driver
 *
 */
constexpr size_t DEFAULT_N = 10u;

/**
 * @brief move the largest element of the list
 * starting at h to the end of the list.
 *
 * @param h
 */
void move_largest_to_end(NODENode h[static 1]);

/**
 * @brief Checks that the largest element of the list
 * starting at h is at the end.
 *
 * @return true if the last element is the largest else
 * @return false
 */
bool assert_largest_at_end(NODENode const h[static 1]);

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
        (argc == 2) ? NUMPARSEexit_on_fail(N, argv[1]) : DEFAULT_N;

    RAND_SEED_TIME;
    NODENode* const nodes = NODEbuild_lin_list_dummy_head(N, gen_key_rand);

    printf("Initial List:\n");
    NODEprint_null_terminated_list(nodes[0].next);

    move_largest_to_end(nodes);

    printf("List after largest moved to end:\n");
    NODEprint_null_terminated_list(nodes[0].next);

    printf("Largest at the end?: %s\n",
           (assert_largest_at_end(nodes) ? "true" : "false"));

    free(nodes);
    return EXIT_SUCCESS;
}

void move_largest_to_end(NODENode h[static 1]) {
    if (!(h->next)) return;    // empty list
    NODENode* max_pred = h;        // the predecessor to the current max
    for (h = h->next; h->next; h = h->next) {
        if (h->next->k > max_pred->next->k) max_pred = h;
    }
    if (max_pred->next == h) return;    // max element is the last
    NODENode* max = max_pred->next;
    max_pred->next = max->next;
    h->next = max;
    max->next = nullptr;
}

bool assert_largest_at_end(NODENode const h[static 1]) {
    size_t largest_seen = 0;
    for (h = h->next; h->next != nullptr; h = h->next) {
        largest_seen = (largest_seen > h->k) ? largest_seen : h->k;
    }
    return ((h->k >= largest_seen) ? true : false);
}