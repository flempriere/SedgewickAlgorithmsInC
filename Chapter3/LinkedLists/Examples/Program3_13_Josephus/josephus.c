/*
Program 3.13 List allocation for the josephus problem

This program for the Josephus problem is a client program that utilises
the list interface from Program 3.12 and the Program 3.14 implementation.
*/

#include "../Program3_12-14_ListImplementation/List.h"
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

    LISTinitNodes(N);
    LISTNode* x = LISTnewNode(1);
    for (size_t i = 2; i <= N; i++) {
        LISTNode* t = LISTnewNode(i);
        LISTinsertNext(x, t);
        x = t;
    }
    while(x != LISTnext(x)) {
        for (size_t i = 1; i < M; i++) x = LISTnext(x);
        LISTfreeNode(LISTdeleteNext(x));
    }
    printf("%zu\n", LISTitem(x));
    return EXIT_SUCCESS;
}