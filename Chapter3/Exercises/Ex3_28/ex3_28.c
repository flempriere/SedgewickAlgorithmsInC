/*
Exercise 3.28

Modify program 3.28 to reduce the number of excessive circular loops it makes.
*/

#include <stdlib.h>
#include <stdio.h>

typedef struct node* link;
typedef struct node {
    int item;
    link next;
} node;

void printList(node* head);

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
    }
    x->next = t;
    while (x != x->next) {
        for (size_t i = 1; i < M; i++) x = x->next;
        x->next = x->next->next; N--;
    }
    printf("%d\n", x->item);
    return 0;
}