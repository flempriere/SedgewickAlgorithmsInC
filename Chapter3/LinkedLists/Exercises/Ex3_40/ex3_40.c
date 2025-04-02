/*
Exercise 3.40

Write a function that takes two arguments - a link to a list
and a function that takes a link as an argument - removes those
arguments from the original list and returns them in a new list
*/

#include "List/Node/Node.h"
#include "MacroLibrary/DefaultCalloc.h"
#include "MacroLibrary/Generic.h"
#include "MacroLibrary/TraceMacro.h"

#include <stdio.h>
#include <stdlib.h>

/**
 * @brief Number of random nodes
 * to generate for test driver.
 */
constexpr unsigned int N = 10u;

/**
 * @brief test if the key associated with a
 * NODENode is even.
 *
 * @param l
 * @return true if l->k is even else
 * @return false
 */
bool is_even(NODENode const head[const static 1]);

/**
 * @brief Extracts all nodes from a list that compare true to a supplied
 * comparison function and returns them as a new list.
 *
 * @param h head of the list to partition.
 * @param cmp comparison function.
 * @return NODENode* head of the new list, nullptr if failed to make the new
 * NODENode.
 */
NODENode*
    partition_nodes_by_function(NODENode* h,
                                bool (*cmp)(NODENode const[const static 1]));

/**
 * @brief Test driver, generate a list of nodes
 * numbered 1 to 10 with a dummy head, then using
 * the function is_even to partition even numbered nodes.
 *
 * @return EXIT_SUCCESS
 */
int main(int argc, char* argv[argc + 1]) {
    // generate a list of N nodes numbered 0 to N-1 with a dummy head
    NODENode* nodes = NODEbuild_lin_list_dummy_head(N, NODEgen_key_idx);
    if (!nodes) return EXIT_FAILURE;

    printf("Initial List:\n");
    NODEprint_null_terminated_list(nodes->next);

    NODENode* eliminated = partition_nodes_by_function(nodes, is_even);
    if (!eliminated) return EXIT_FAILURE;

    printf("List after removal:\n");
    NODEprint_null_terminated_list(nodes->next);

    printf("New list after removal:\n");
    NODEprint_null_terminated_list(eliminated->next);

    free(nodes);
    free(eliminated);
    return EXIT_SUCCESS;
}

bool is_even(NODENode const l[const static 1]) { return IS_EVEN(l->k); }

NODENode* partition_nodes_by_function(NODENode* h,
                                      bool cmp(NODENode const* const)) {
    NODENode* elimHead = DEFAULTCALLOC(*elimHead);
    if (!elimHead) {
        TRACE_CALL("allocation failed\n");
        return nullptr;
    }
    NODENode* elimTail = elimHead;

    for (; !(h == nullptr || h->next == nullptr); h = h->next) {
        if (cmp(h->next)) {
            NODENode* h_nxt = h->next;
            h->next = h_nxt->next;
            elimTail->next = h_nxt;
            elimTail = elimTail->next;
        }
    }
    elimTail->next = nullptr;
    return elimHead;
}
