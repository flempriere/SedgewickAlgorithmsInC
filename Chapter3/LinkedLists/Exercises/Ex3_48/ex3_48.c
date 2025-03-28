/*
Exercise 3.48

Write a program that frees the nodes in every fifth position,
assuming the first position is indexed as 1.

Note: We use the list interface from Exercise 3.50
*/

#include "List_div5.h"

#include <stdio.h>
#include <stdlib.h>

/**
 * @brief Number of test nodes to generate
 *
 */
constexpr size_t DEFAULT_N = 25u;

/**
 * @brief Generates a list of size N, then frees
 * every fifth node.
 *
 *
 * @param @argv[1] Number of nodes to generate
 *
 * @return EXIT_SUCCESS
 */
int main(int argc, char* argv[argc + 1]) {
    register size_t const N =
        (argc == 2) ? (strtoull(argv[1], nullptr, 0)) : DEFAULT_N;

    register LISTNode* head = LISTnew_node(1);
    register LISTNode* cur = head;
    for (register size_t i = 2; i <= N; i++) {
        LISTinsert_next(cur, LISTnew_node(i));
        cur = LISTnext(cur);
    }
    LISTprint_list(head);
    head = LISTfree_every_fifth_node(head);
    LISTprint_list(head);

    LISTfree_all_nodes(head);

    return EXIT_SUCCESS;
}
