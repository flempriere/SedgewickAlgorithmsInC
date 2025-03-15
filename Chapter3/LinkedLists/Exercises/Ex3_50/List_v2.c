/*
Exercise 3.50

Reimplement Program 3.12 and Program 3.13 to use
malloc and free directly in newNode and freeNode

*/

#include <stdlib.h>
#include <stdio.h>
#include "List_v2.h"

/**
 * @brief list of allocated, unused nodes
 * for use in lists.
 */
LISTNode* freeList;

LISTNode *LISTnewNode(LISTItem k)
{
    LISTNode* x = malloc(sizeof(typeof_unqual(*x)));
    x->item = k;
    x->next = x;
    return x;
}

void LISTfreeNode(LISTNode* n) {
    free(n);    
}

void LISTprintList(LISTNode* h) {
    LISTNode* cur = h;
    do {
        printf("%zu->", cur->item);
        cur = cur->next;
    } while(cur != h);
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
