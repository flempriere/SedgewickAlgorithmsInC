/*
Exercise 3.47

Write a program that frees all the nodes on a given linked list

Note: We use the list interface from Exercise 3.50
*/

#include <stdio.h>
#include <stdlib.h>
#include "List_v3.h"

/**
 * @brief Number of test nodes to generate
 * 
 */
#define N 10

/**
 * @brief Generates a list of size N, then frees
 * the entire list
 * 
 * If this list has been successfully freed the second
 * print should cause a segmentation fault.
 * 
 * @return crash else EXIT_FAILURE
 */
int main(int argc, char* argv[argc+1]) {

    LISTNode* head = LISTnewNode(0);
    LISTNode* cur = head;
    for (size_t i = 1; i <= N; i++) {
        LISTinsertNext(cur, LISTnewNode(i));
        cur = LISTnext(cur);
    }
    LISTprintList(head);
    LISTfreeAllNodes(head);
    LISTprintList(head);
    return EXIT_FAILURE;
}
