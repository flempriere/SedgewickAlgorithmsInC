/*
Exercise 3.30
Run Program 3.9 for M = 2,3,5,10 and N = 10^3, 10^4, 10^5, 10^6.
*/

#include "../../../../MacroLibrary/Utility.h"

#include <stdio.h>
#include <stdlib.h>

/**
 * @brief Number of distinct M values to test
 *
 */
constexpr size_t M_CASES = 4u;

/**
 * @brief Number of distinct N values to test
 *
 */
constexpr size_t N_CASES = 4u;

/**
 * @brief Key type for node structure
 *
 */
typedef size_t key;

/**
 * @brief LinkedList node
 * consisting of a @key
 * and next node.
 *
 * @see key
 */
typedef struct node node;

typedef struct node {
    key item;
    node* next;
} node;

/**
 * @brief Determines the value of the Josephus function
 * for a precompiled array of N and M values.
 *
 * @return EXIT_SUCCESS on completion
 */
int main(int argc, char* argv[argc + 1]) {
    constexpr size_t mArray[] = { 2, 3, 5, 10 };
    constexpr size_t nArray[] = { 10000, 100000, 1000000, 10000000 };

    for (register size_t i = 0; i < N_CASES; i++) {
        register size_t N = nArray[i];
        for (register size_t j = 0; j < M_CASES; j++) {
            register size_t M = mArray[j];

            register node* const t = calloc(1, SIZEOF_VARTYPE(*t));
            register node* x = t;
            t->item = 1;
            t->next = t;

            for (register key k = 2; k <= N; k++) {
                x = (x->next = calloc(1, SIZEOF_VARTYPE(*x)));
                x->item = k;
            }
            x->next = t;
            while (x != x->next) {
                for (register key k = 1; k < M; k++) x = x->next;
                register node* dropped = x->next;
                x->next = x->next->next;
                free(dropped);
            }
            printf("N: %zu, M: %zu, Result: %zu\n", N, M, x->item);
            free(x);
        }
    }
    return EXIT_SUCCESS;
}