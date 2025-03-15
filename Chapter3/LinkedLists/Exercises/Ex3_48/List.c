/*
Exercise 3.48

Write a program that frees the nodes in positions
that are divisible by 5 in a linkedlist.

We modify the linked list to use a nullptr tail
rather than a circular list.

*/

#include <stdlib.h>
#include <stdio.h>
#include "List_div5.h"

/**
 * @brief list of allocated, unused nodes
 * for use in lists.
 */
LISTNode* freeList;

LISTNode *LISTnewNode(LISTItem k)
{
    LISTNode* x = malloc(sizeof(typeof_unqual(*x)));
    x->item = k;
    x->next = nullptr;
    return x;
}

void LISTfreeNode(LISTNode* n) {
    free(n);    
}

LISTNode* LISTfreeEveryFifthNode(LISTNode* n) {
    LISTNode* cur = n;
    size_t i = 1;
    while (cur->next) {
        if (!((i+1) % 5)) {
            free(LISTdeleteNext(cur));
            i++;
            if (!(cur->next)) break;
        }
        cur = cur->next;
        i++;
    }
    return n;
}

void LISTprintList(LISTNode* h) {
    for (; h != nullptr; h = h->next) {
        printf("%zu->", h->item);
    }
    printf("X\n");
}

void LISTinsertNext(LISTNode* x, LISTNode* y) {
    y->next = x->next;
    x->next = y;
}

LISTNode* LISTdeleteNext(LISTNode* x)
{
    LISTNode* t = x->next;
    x->next = t->next;
    return t;
}

LISTNode* LISTnext(LISTNode* x)
{
    return x->next;
}

LISTItem LISTitem(LISTNode* x)
{
    return x->item;
}
