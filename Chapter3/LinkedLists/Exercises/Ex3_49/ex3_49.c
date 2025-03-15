/*
Exercise 3.49

Write a program that frees the nodes in even positions
in a linkedList
*/

#include <stdio.h>
#include <stdlib.h>
#include "List_removeEven.h"

/**
 * @brief Number of test nodes to generate
 * 
 */
#define DEFAULT_N 25

/**
 * @brief Generates a list of size N, then frees
 * every fifth node.
 * 
 * 
 * @param @argv[1] Number of nodes to generate
 * 
 * @return EXIT_SUCCESS
 */
int main(int argc, char* argv[argc+1]) {

    size_t N = (argc == 2) ? (strtoull(argv[1], nullptr, 0)) : DEFAULT_N;

    LISTNode* head = LISTnewNode(1);
    LISTNode* cur = head;
    for (size_t i = 2; i <= N; i++) {
        LISTinsertNext(cur, LISTnewNode(i));
        cur = LISTnext(cur);
    }
    LISTprintList(head);
    head = LISTfreeEverySecondNode(head);
    LISTprintList(head);
    return EXIT_SUCCESS;
}