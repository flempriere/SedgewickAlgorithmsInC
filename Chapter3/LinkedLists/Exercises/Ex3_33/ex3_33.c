/*
Exercise 3.33
Modify Program 3.9 that uses an array of indices to implement
the linked list
*/
#include "../../../../MacroLibrary/NumberParse.h"

#include <stdio.h>
#include <stdlib.h>

/**
 * @brief Maximum number of nodes for Josephus Problem
 *
 */
constexpr size_t MAX_N = 100u;

/**
 * @brief Key type for node structure
 * @see @link
 */
typedef size_t key;

/**
 * @brief Link type for node structure
 * @see @key
 */
typedef size_t link;

/**
 * @brief Prints the current state of the parallel
 * @it and @nxt arrays representing a linked list.
 *
 * @param N Max size of the linkedList
 * @param it Key array of the linkedlist, at least size N
 * @param nxt Link array of the linkedlist, at least size N
 */
void print_state(size_t const N, key const it[N], link const nxt[N]);

/**
 * @brief Version of the Josephus Problem [Program 3.9]
 * that utilises a parallel array structure to implement
 * the linked list.
 *
 * This version will also print out the state of the linkedlist
 * after every elimination (to produce the output for ex3_32 for
 * example)
 *
 * @param argv[0] N, number of nodes in initial list
 * @param argv[1] M, number of nodes to count before each elimination
 * @return EXIT_SUCCESS on successful completion else
 * @return EXIT_FAILURE
 */
int main(int argc, char* argv[argc + 1]) {
    // idx i holds the i-th node.
    // zero the arrays
    key item[MAX_N] = {};
    link next[MAX_N] = {};

    if (argc != 3) {
        fprintf(stderr, "Error: requires args N M\n");
        return EXIT_FAILURE;
    }
    register size_t const N = NUMPARSEexit_on_fail(N, argv[1]);
    register size_t const M = NUMPARSEexit_on_fail(M, argv[2]);

    if (!(M && N)) {
        fprintf(stderr, "Error: N and M must be > 0\n");
        return EXIT_FAILURE;
    }

    for (register key i = 0; i < N; i++) {
        item[i] = i + 1;
        next[i] = (i + 1) % N;
    }

    register link x = N;
    register size_t n = N;
    while (x != next[x]) {
        print_state(n, item, next);
        for (register link i = 1; i < M; i++) x = next[x];
        printf("%2zu\n", item[next[x]]);
        next[x] = next[next[x]];
    }
    printf("Result: %2zu\n", item[x]);
    return EXIT_SUCCESS;
}

void print_state(size_t const N, key const it[N], link const nxt[N]) {
    printf("Item: ");
    for (size_t i = 0; i < N; i++) { printf("%2zu ", it[i]); }
    printf("\nNext: ");
    for (size_t i = 0; i < N; i++) { printf("%2zu ", nxt[i]); }
    printf("\n");
}