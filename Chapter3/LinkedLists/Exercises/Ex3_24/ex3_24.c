/*
Exercise 3.24
Write a function that returns the number of nodes on a circular list,
given a pointer to one of the nodes on the list
*/

#include <stdlib.h>
#include <stdio.h>

typedef struct node* link;
typedef struct node {
    int item;
    link next;
} node;

size_t countNodes(node* t);

int main(int argc, char* argv[argc+1]) {

    if (argc != 3) {
        fprintf(stderr, "Missing arguments N start_idx\n");
        return 1;
    }
    size_t N = strtoull(argv[1], NULL, 0);
    size_t s_idx = strtoull(argv[2], NULL, 0);

    link t = malloc(sizeof(*t));
    link x = t;
    link s = t;

    t->item = 1, t->next = t;
    for (size_t i = 2; i <= N; i++) {
        x = (x->next = malloc(sizeof(*x)));
        x->item = i;
        x->next = t;
        if (i == s_idx) s = x;
    }
    printf("%zu\n", countNodes(s));
}

size_t countNodes(node* t) {
    size_t sz = 1;
    for (link s = t->next; s != t; s=s->next, sz++);
    return sz;
}