/*
Exercise 3.33
Modify Program 3.9 that uses an array of indices to implement
the linked list
*/
#include "MacroLibrary/NumberParse.h"

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
 * @brief Calculates the Josephus problem assuming a linked list represented
 * using parallel arrays.
 *
 * @param h starting link
 * @param m number of hops per elimination.
 * @param n total size of the linked list array
 * @param it items array
 * @param nxt next array
 * @return key of the last element left.
 */
key NODEcalculate_josephus(link h, size_t const m, size_t const n, key it[n],
                           link nxt[n]);
/**
 * @brief Prints the current state of the parallel
 * @it and @nxt arrays representing a linked list.
 *
 * @param N Max size of the linkedList
 * @param it Key array of the linkedlist, at least size N
 * @param nxt Link array of the linkedlist, at least size N
 */
void print_state(size_t const n, key const it[n], link const nxt[n]);

/**
 * @brief Initialises the linked list structure.
 *
 * @param n
 * @param it
 * @param nxt
 */
void init_list(size_t n, key it[n], link nxt[n]);
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

    init_list(N, item, next);

    register link x = N;

    printf("Final Key: %2zu\n", NODEcalculate_josephus(x, M, N, item, next));
    return EXIT_SUCCESS;
}

void print_state(size_t const N, key const it[N], link const nxt[N]) {
    printf("Item: ");
    for (size_t i = 0; i < N; i++) { printf("%2zu ", it[i]); }
    printf("\nNext: ");
    for (size_t i = 0; i < N; i++) { printf("%2zu ", nxt[i]); }
    printf("\n");
}

void init_list(size_t const n, key it[n], link nxt[n]) {
    for (register key i = 0; i < n; i++) {
        it[i] = i + 1;
        nxt[i] = (i + 1) % n;
    }
}

key NODEcalculate_josephus(link h, size_t const m, size_t const n, key it[n],
                           link nxt[n]) {
    while (h != nxt[h]) {
        print_state(n, it, nxt);
        for (register link i = 1; i < m; i++) h = nxt[h];
        printf("%2zu\n", it[nxt[h]]);
        nxt[h] = nxt[nxt[h]];
    }
    return it[h];
}