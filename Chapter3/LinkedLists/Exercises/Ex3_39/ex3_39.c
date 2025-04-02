/*
Exercise 3.39

Write a function that takes two arguments - a link to a list
and a function that takes a link as an argument - and removes
all items on the given list for which the function returns
a nonzero value
*/

#include "List/Node/Node.h"
#include "MacroLibrary/Generic.h"

#include <stdio.h>
#include <stdlib.h>

/**
 * @brief Number of random nodes
 * to generate for test driver.
 */
constexpr unsigned int N = 10u;

/**
 * @brief test if the key associated with a
 * node is even.
 *
 * @param l
 * @return true if l->k is even else
 * @return false
 */
bool is_even(NODENode const l[const static 1]);

/**
 * @brief Removes all nodes on a list that compare true to a given
 * cmp function.
 *
 * @param h head of the list to check.
 * @param cmp comparison function, that takes in a node* and returns true or
 * false.
 */
void remove_nodes_by_function(NODENode* h,
                              bool cmp(NODENode const[const static 1]));

/**
 * @brief Test driver, generate a list of nodes
 * numbered 1 to 10 with a dummy head, then using
 * the function is_even remove all even nodes.
 *
 * @return EXIT_SUCCESS
 */
int main(int argc, char* argv[argc + 1]) {
    // generate a list of N nodes numbered 1 to 10 with a dummy head
    NODENode* const nodes = NODEbuild_lin_list_dummy_head(N, NODEgen_key_idx);
    if (!nodes) return EXIT_FAILURE;

    printf("Initial List:\n");
    NODEprint_null_terminated_list(nodes[0].next);

    remove_nodes_by_function(nodes, is_even);

    printf("List after removal:\n");
    NODEprint_null_terminated_list(nodes[0].next);

    free(nodes);
    return EXIT_SUCCESS;
}

bool is_even(NODENode const l[const static 1]) { return IS_EVEN(l->k); }

void remove_nodes_by_function(NODENode* h, bool cmp(NODENode const* const)) {
    for (; !(h == nullptr || h->next == nullptr); h = h->next) {
        if (cmp(h->next)) {
            NODENode* h_nxt = h->next;
            h->next = h_nxt->next;
        }
    }
}
