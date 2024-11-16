/*
Exercise 3.25
Write a function that returns the number of nodes between two pointers x and
t on a circular linked list.
*/

#include <stdlib.h>
#include <stdio.h>

typedef struct node* link;
typedef struct node {
    int item;
    link next;
} node;

size_t countNodesBetween(node* x, node* t);

int main(int argc, char* argv[argc+1]) {

    if (argc != 4) {
        fprintf(stderr, "Missing arguments N x t\n");
        return 1;
    }
    size_t N = strtoull(argv[1], NULL, 0);
    size_t x_idx = strtoull(argv[2], NULL, 0);
    size_t t_idx = strtoull(argv[3], NULL, 0);

    link t = malloc(sizeof(*t));
    link x = t;
    link srt = t;
    link stp = t;

    t->item = 1, t->next = t;
    for (size_t i = 2; i <= N; i++) {
        x = (x->next = malloc(sizeof(*x)));
        x->item = i;
        x->next = t;
        if (i == x_idx) srt = x;
        if (i == t_idx) stp = x;
    }
    printf("%zu\n", countNodesBetween(srt, stp));
    return 0;
}

size_t countNodesBetween(node* x, node* t) {
    size_t sz = 0;
    for (; x != t; x=x->next, sz++);
    return sz;
}