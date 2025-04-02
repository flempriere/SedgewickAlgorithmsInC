/*
Exercise 3.38
Write a function that takes a link to a list as argument
and returns a link to a copy of the list (a new list
containing all the same items, in the same order)
*/

#include "List/Node/Node.h"

#include <stdio.h>
#include <stdlib.h>

/**
 * @brief Number of random nodes
 * to generate for test driver.
 */
constexpr unsigned int N = 10u;

/**
 * @brief function to cleanup a partially constructed list copy if the
 * construction runs out of memory during the construction.
 *
 * @param h
 * @param stop
 * @return nullptr_t
 */
static inline nullptr_t copy_failed_cleanup(NODENode* h, NODENode* stop) {
    while (h != stop) {
        NODENode* tmp = h;
        h = h->next;
        free(tmp);
    }
    free(stop);
    return nullptr;
}
/**
 * @brief Creates a deep copy of the
 * list and returns a pointer to the copy.
 * The new head is a dummy head.
 *
 * @param head - start of the list to be copied,
 * assume a dummy head.
 *
 * @return Node* pointer to new list else nullptr if allocation fails.
 */
NODENode* copy_list(NODENode head[static 1]) {
    NODENode* const new_head = NODEmake_node(0, nullptr);
    if (!new_head) return nullptr;

    NODENode* tail = new_head;

    for (head = head->next; head != nullptr; head = head->next) {
        tail = (tail->next = NODEmake_node(head->k, nullptr));
        if (!(tail)) return NODEclean_failed_build(new_head);
    }
    return new_head;
}

int main(int argc, char* argv[argc + 1]) {
    // generate a list of N nodes numbered 1 to 10 with a dummy head
    register NODENode* const nodes =
        NODEbuild_lin_list_dummy_head(N, NODEgen_key_idx);

    printf("Initial List:\n");
    NODEprint_null_terminated_list(nodes[0].next);

    register NODENode* const copied_list = copy_list(nodes);

    printf("Copied list:\n");
    NODEprint_null_terminated_list(copied_list->next);

    NODEdelete_null_terminated_list(copied_list);
    free(nodes);
    return EXIT_SUCCESS;
}