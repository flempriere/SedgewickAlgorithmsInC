/*
Exercise 3.27
Write a function that given two pointers x and t to elements in a list,
moves the node following t to the node following x.
*/

#include <stdlib.h>
#include <stdio.h>

typedef struct node* link;
typedef struct node {
    int item;
    link next;
} node;

void printList(node* head);
void moveNode(node* x, node* t);

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
    printList(srt);
    moveNode(srt, stp);
    printList(srt);
    return 0;
}

void printList(node* head) {
    for (node* t = head->next; t != head; t = t->next) {
        printf("%d->", t->item);
    }
    printf("%d\n", head->item);
}

void moveNode(node* x, node* t) {

    node* t_nxt = t->next;
    t->next = t_nxt->next;
    t_nxt->next = x->next;
    x->next = t_nxt;
}