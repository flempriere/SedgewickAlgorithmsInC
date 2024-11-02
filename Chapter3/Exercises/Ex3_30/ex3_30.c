/*
Exercise 3.30
Run Program 3.9 for M = 2,3,5,10 and N = 10^3, 10^4, 10^5, 10^6.
*/

#include <stdlib.h>
#include <stdio.h>

#define M_CASES 4
#define N_CASES 4

typedef struct node* link;
typedef struct node {
    size_t item;
    link next;
} node;

void printList(node* head);

int main(int argc, char* argv[argc+1]) {

    size_t mArray[] = {2, 3, 5, 10};
    size_t nArray[] = {10000, 100000, 1000000, 10000000};

    for (size_t i = 0; i < N_CASES; i++) {
        size_t N = nArray[i];
        for (size_t j = 0; j < M_CASES; j++) {
            size_t M = mArray[j];

            link t = malloc(sizeof(*t));
            link x = t;
            t->item = 1;
            t->next = t;

            for (size_t k = 2; k <= N; k++) {
                x = (x->next = malloc(sizeof(*x)));
                x->item = k;
            }
            x->next = t;
            while (x != x->next) {
                for (size_t k = 1; k < M; k++) x = x->next;
                node* dropped = x->next;
                x->next = x->next->next;
                free(dropped);
            }
            printf("N: %zu, M: %zu, Result: %zu\n", N, M, x->item);
            free(x);
        }
    }
    return 0;
}