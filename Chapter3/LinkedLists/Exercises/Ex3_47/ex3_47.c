/*
Exercise 3.47

Write a program that frees all the nodes on a given linked list

Note: We use the list interface from Exercise 3.50
*/

#include "List_v3.h"

#include <stdio.h>
#include <stdlib.h>

/**
 * @brief Number of test nodes to generate
 *
 */
constexpr unsigned int N = 10u;

/**
 * @brief Generates a list of size N, then frees
 * the entire list
 *
 * If this list has been successfully freed the second
 * print should cause a segmentation fault.
 *
 * @return crash else EXIT_FAILURE
 */
int main(int argc, char* argv[argc + 1]) {
    register LISTNode* const head = LISTnew_node(0);
    register LISTNode* cur = head;
    for (register size_t i = 1; i <= N; i++) {
        LISTinsert_next(cur, LISTnew_node(i));
        cur = LISTnext(cur);
    }
    LISTprint_list(head);
    LISTfree_all_nodes(head);
    LISTprint_list(head);
    return EXIT_FAILURE;
}
