/*
Exercise 3.48

Write a function that frees (calls free with a pointer to)
all the nodes on a given linked list

See implementation of freeAllNodes()

*/

#include <stdlib.h>
#include <stdio.h>
#include "List_v3.h"

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

void LISTfreeAllNodes(LISTNode* n) {
    LISTNode* cur = n->next;
    while (cur != n) {
        LISTNode* cur_n = cur->next;
        free(cur);
        cur = cur_n;
    }
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
