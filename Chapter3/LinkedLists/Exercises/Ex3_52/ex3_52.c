/*
Exercise 3.52

Implement the interface in Program 3.12 using array indices
(and no head node) rather than pointers.
*/

#include "list.h"
#include <stdio.h>
#include <stdlib.h>

/**
 * @brief Determine the final person eliminated
 * in the Josephus problem consisting of N people
 * eliminating after M hops.
 * 
 * @param argv[1] N - number of nodes > 0
 * @param argv[2] M - number of skips > 0
 * 
 * @return EXIT_SUCCESS on successful termination else
 * @return EXIT_FAILURE 
 */
int main(int argc, char* argv[argc+1]) {
    if (argc != 3) {
        fprintf(stderr, "Usage is ./josephus N M\n");
        return EXIT_FAILURE;
    }
    size_t N = strtoull(argv[1], nullptr, 0);
    size_t M = strtoull(argv[2], nullptr, 0);
    if (!(N && M)) {
        fprintf(stderr, "Error: N and M must be > 0\n");
        return EXIT_FAILURE;
    }

    initNodes(N);
    ListNode x = newNode(1);
    for (size_t i = 2; i <= N; i++) {
        ListNode t = newNode(i);
        insertNext(x, t);
        x = t;
    }
    while(x != Next(x)) {
        for (size_t i = 1; i < M; i++) x = Next(x);
        freeNode(deleteNext(x));
    }
    printf("%zu\n", Item(x));

    printf("Free List:\n");
    for (ListNode x = freeList; x != LIST_FULL; x = Next(x)) {
        printf("%zu->", Item(x));
    }
    printf("X\n");
    return EXIT_SUCCESS;
}