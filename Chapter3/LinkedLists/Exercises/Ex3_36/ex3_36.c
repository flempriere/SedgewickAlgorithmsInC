/*
Exercise 3.36

Write a function that rearranges a linked list to put the nodes in even
positions after the nodes in odd positions in the list, preversing the
relative order of both the evens and the odds.

*/
#include "List/Node/Node.h"
#include "MacroLibrary/Generic.h"

#include <stdio.h>
#include <stdlib.h>

/**
 * @brief Number of random nodes to generate for test driver
 *
 */
constexpr size_t N = 10u;

/**
 * @brief Rearrange a linked list to put
 * the sublist of even indices before the
 * sublist of odd indices. The relative
 * order of each sublist is preserved.
 *
 * @param h
 */
void partition_odds_and_evens(NODENode h[const static 1]);

/**
 * @brief Driver program to demonstrate PartitionOddsAndEvens.
 * We generate a list containing N elements keyed by their
 * position and then partition.
 *
 * @return int
 */
int main(int argc, char* argv[argc + 1]) {
    // generate a list of N numbers indexed from zero.
    NODENode* const nodes = NODEbuild_lin_list_dummy_head(N, NODEgen_key_idx);
    if (!nodes) return EXIT_FAILURE;
    printf("Initial List:\n");
    NODEprint_null_terminated_list(nodes[0].next);

    partition_odds_and_evens(nodes);

    printf("List after partition:\n");
    NODEprint_null_terminated_list(nodes[0].next);

    free(nodes);
    return EXIT_SUCCESS;
}

void partition_odds_and_evens(NODENode h[const static 1]) {
    register NODENode* odd_head = nullptr;
    register NODENode* odd_tail = odd_head;
    register NODENode* even_head = nullptr;
    register NODENode* even_tail = even_head;

    // build two lists, one for odd, one for even
    register NODENode* cur = h->next;
    for (register size_t idx = 0; cur != nullptr; cur = cur->next, idx++) {
        if (IS_EVEN(idx)) {
            (!even_head) ? (even_head = cur) : (even_tail->next = cur);
            even_tail = cur;
        } else {
            (!odd_head) ? (odd_head = cur) : (odd_tail->next = cur);
            odd_tail = cur;
        }
    }
    // merge the odd and even lists
    even_tail->next = nullptr;
    odd_tail->next = even_head;
    h->next = odd_head;
}