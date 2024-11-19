/*
Exercise 3.30
Run Program 3.9 for M = 2,3,5,10 and N = 10^3, 10^4, 10^5, 10^6.
*/

#include <stdlib.h>
#include <stdio.h>

/**
 * @brief Number of distinct M values to test
 * 
 */
#define M_CASES 4

/**
 * @brief Number of distinct N values to test
 * 
 */
#define N_CASES 4

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
int main(int argc, char* argv[argc+1]) {

    size_t mArray[] = {2, 3, 5, 10};
    size_t nArray[] = {10000, 100000, 1000000, 10000000};

    for (size_t i = 0; i < N_CASES; i++) {
        size_t N = nArray[i];
        for (size_t j = 0; j < M_CASES; j++) {
            size_t M = mArray[j];

            node* t = malloc(sizeof(*t));
            node* x = t;
            t->item = 1;
            t->next = t;

            for (key k = 2; k <= N; k++) {
                x = (x->next = malloc(sizeof(*x)));
                x->item = k;
            }
            x->next = t;
            while (x != x->next) {
                for (key k = 1; k < M; k++) x = x->next;
                node* dropped = x->next;
                x->next = x->next->next;
                free(dropped);
            }
            printf("N: %zu, M: %zu, Result: %zu\n", N, M, x->item);
            free(x);
        }
    }
    return EXIT_SUCCESS;
}