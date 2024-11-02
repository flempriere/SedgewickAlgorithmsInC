/*
Program 3.9

Solves the josephus problem. Arranging N nodes in a circle, we go around
the circle M times an eliminate the corresponding node. We then close the circle
and repeat until there is one index left.
*/

#include <stdlib.h>
#include <stdio.h>

typedef struct node* link;
typedef struct node {
    int item;
    link next;
} node;


int main(int argc, char* argv[argc+1]) {
    
    if (argc != 3) {
        fprintf(stderr, "Requires arguments N M\n");
        return 1;
    }
    size_t N = strtoull(argv[1], NULL, 0);
    size_t M = strtoull(argv[2], NULL, 0);

    link t = malloc(sizeof(*t));
    link x = t;
    t->item = 1;
    t->next = t;

    for (size_t i = 2; i <= N; i++) {
        x = (x->next = malloc(sizeof(*x)));
        x->item = i;
        x->next = t;
    }
    while (x != x->next) {
        for (size_t i = 1; i < M; i++) x = x->next;
        x->next = x->next->next; N--;
    }
    printf("%d\n", x->item);
    return 0;
}