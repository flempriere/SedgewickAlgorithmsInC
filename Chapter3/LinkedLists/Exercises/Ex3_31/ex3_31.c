/*
Exercise 3.31
Run Program 3.9 plot the results for M = 10, with N = 2 to 1000.
*/

#include "../../../../MacroLibrary/Utility.h"

#include <stdio.h>
#include <stdlib.h>

/**
 * @brief Maximum value of N to run the Josephus
 * function for.
 */
constexpr size_t N_MAX = 1000u;

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
struct node {
    key item;
    node* next;
};

/**
 * @brief Records the value of the Josephus function
 * varying N from 2 to 1000 with M fixed equal to 10.
 *
 * @return EXIT_SUCCESS
 */
int main(int argc, char* argv[argc + 1]) {
    constexpr size_t M = 10;

    for (register size_t N = 2; N < N_MAX; N++) {
        register node* t = calloc(1, SIZEOF_VARTYPE(*t));
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
        printf("N: %zu, f(N): %zu\n", N, x->item);
        free(x);
    }
    return EXIT_SUCCESS;
}