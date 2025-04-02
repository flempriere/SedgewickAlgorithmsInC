/*
Exercise 3.41

This function reverses a list, returning a pointer to the final NODENode,
which is now the new head NODENode. The first NODENode link is now a nullptr.

Uses a dummy head representation.
*/
#include "List/Node/Node.h"

#include <stdio.h>
#include <stdlib.h>

/**
 * @brief Reverse a linkedList. This modifies
 * the linkedlist in place.
 *
 * @param x head of the linked list to reverse
 * @return NODENode*, head of the reversed list.
 */
NODENode* reverse(NODENode x[const static 1]);

/**
 * @brief Demonstrates linkedList reversal
 *
 * @return EXIT_SUCCESS on successful completion
 */
int main(int argc, char* argv[argc + 1]) {
    register constexpr size_t N = 10;    // number of nodes to test.
    // dummy head
    register NODENode* head = NODEbuild_lin_list_dummy_head(N, NODEgen_key_idx);
    if (!head) return EXIT_FAILURE;

    NODEprint_null_terminated_list(head->next);
    NODEprint_null_terminated_list(reverse(head)->next);

    free(head);
    return EXIT_SUCCESS;
}

NODENode* reverse(NODENode x[const static 1]) {
    if (!(x->next)) return x;    // single node doesn't need to be reversed.

    register NODENode* y = x->next;    //
    register NODENode* r = nullptr;    // reversed list

    while (y != nullptr) {
        NODENode* t = y->next;
        y->next = r;
        r = y;
        y = t;
    }
    x->next = r;
    return x;
}