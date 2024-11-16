/*
Exercise 3.26
Write a function that given two pointers x and t to disjoint circular lists,
insert the list pointed to by t into the list pointed to by x at the point
after x

The driver code here will make one list with elements 1...N and one with
elements N + 1... 2N, x should be a number in the first list and t a
number in the second.
*/

#include <stdlib.h>
#include <stdio.h>

typedef struct node* link;
typedef struct node {
    int item;
    link next;
} node;

void printList(node* head);
void mergeLists(node* x, node* t);

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
    link xp = t;

    t->item = 1, t->next = t;
    for (size_t i = 2; i <= N; i++) {
        x = (x->next = malloc(sizeof(*x)));
        x->item = i;
        x->next = t;
        if (i == x_idx) xp = x;
    }

    t = malloc(sizeof(*t));
    x = t;
    link tp = t;

    t->item = N+1, t->next = t;
    for (size_t i = N + 2; i <= 2*N; i++) {
        x = (x->next = malloc(sizeof(*x)));
        x->item = i;
        x->next = t;
        if (i == t_idx) tp = x;
    }
    printList(xp);
    printList(tp);
    mergeLists(xp, tp);
    printList(xp);
}

void printList(node* head) {
    for (node* t = head->next; t != head; t = t->next) {
        printf("%d->", t->item);
    }
    printf("%d\n", head->item);
    return 0;
}

void mergeLists(node* xp, node* tp) {
    node* t_prev;
    for (t_prev = tp; t_prev->next != tp; t_prev = t_prev->next); //find the node linking to tp

    t_prev->next = xp->next;
    xp->next = tp;
}