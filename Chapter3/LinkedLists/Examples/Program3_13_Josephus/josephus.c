/*
Program 3.13 List allocation for the josephus problem

This program for the Josephus problem is a client program that utilises
the list interface from Program 3.12 and the Program 3.14 implementation.
*/

#include "MacroLibrary/NumberParse.h"
#include "List/v1/List.h"

#include <stdio.h>
#include <stdlib.h>


/**
 * @brief Builds a list of size N for the josephus problem.
 * 
 * @param N 
 * @return LISTNode* 
 */
LISTNode* build_list(size_t const n);

/**
 * @brief Calculate the josephus problem taking m steps around the list per
 * elimination.
 * 
 * @param x 
 * @param m 
 * @return LISTItem key value of the last node remaining.
 */
LISTItem NODEcalculate_josephus(LISTNode x[static 1], size_t const m);
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
int main(int argc, char* argv[argc + 1]) {
    if (argc != 3) {
        fprintf(stderr, "Usage is ./josephus N M\n");
        return EXIT_FAILURE;
    }
    register size_t const N = NUMPARSEexit_on_fail(N, argv[1]);
    register size_t const M = NUMPARSEexit_on_fail(M, argv[2]);
    if (!(N && M)) {
        fprintf(stderr, "Error: N and M must be > 0\n");
        return EXIT_FAILURE;
    }

    if(!LISTinit_nodes(N)) {
        fprintf(stderr, "Failed to build Josephus List\n");
        return EXIT_FAILURE;
    }
    register LISTNode* x = build_list(N);

    printf("%zu\n", NODEcalculate_josephus(x, M));

    LISTdeinit_list();
    return EXIT_SUCCESS;
}

LISTNode* build_list(size_t const n) {
    register LISTNode* x = LISTnew_node(1);
    for (register size_t i = 2; i <= n; i++) {
        register LISTNode* t = LISTnew_node(i);
        LISTinsert_next(x, t);
        x = t;
    }
    return x;
}

LISTItem NODEcalculate_josephus(LISTNode x[static 1], size_t const m) {
    while (x != LISTnext(x)) {
        for (register size_t i = 1; i < m; i++) x = LISTnext(x);
        LISTfree_node(LISTdelete_next(x));
    }
    LISTItem k = LISTitem(x);
    LISTfree_node(LISTdelete_next(x));
    return k;
}