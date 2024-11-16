/*
Program 3.13 List allocation for the josephus problem

This program for the Josephus problem is a client program that utilises
the list interface from Program 3.12 and the Program 3.14 implementation.
*/

#include "list.h"
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char* argv[argc+1]) {
    if (argc != 3) {
        fprintf(stderr, "Usage is ./josephus N M");
        return EXIT_FAILURE;
    }
    size_t N = strtoull(argv[1], nullptr, 0);
    size_t M = strtoull(argv[2], nullptr, 0);

    initNodes(N);
    ListNode* x = newNode(1);
    for (size_t i = 2; i <= N; i++) {
        ListNode* t = newNode(i);
        insertNext(x, t);
        x = t;
    }
    while(x != next(x)) {
        for (size_t i = 1; i < M; i++) x = next(x);
        freeNode(deleteNext(x));
    }
    printf("%zu\n", Item(x));
}