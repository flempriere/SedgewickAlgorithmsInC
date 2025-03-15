/*
Exercise 3.49

Write a program that frees the nodes in even positions

We modify the linked list to use a nullptr tail
rather than a circular list.

*/

#include <stdlib.h>
#include <stdio.h>
#include "List_removeEven.h"

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

LISTNode* LISTfreeEverySecondNode(LISTNode* n) {
    LISTNode* cur = n;
    bool delete = true;
    while (cur->next) {
        if (delete) {
            free(LISTdeleteNext(cur));
            delete = !delete;
            if (!(cur->next)) break;
        }
        cur = cur->next;
        delete = !delete;
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
