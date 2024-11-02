/*
Exercise 3.31
Run Program 3.9 plot the results for M = 10, with N = 2 to 1000.
*/

#include <stdlib.h>
#include <stdio.h>

#define N_MAX 1000

typedef struct node* link;
typedef struct node {
    size_t item;
    link next;
} node;

void printList(node* head);

int main(int argc, char* argv[argc+1]) {

    size_t M = 10;

    for (size_t N = 2; N < N_MAX; N++) {
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
        printf("N: %zu, f(N): %zu\n", N, x->item);
        free(x);
    }
    return 0;
}