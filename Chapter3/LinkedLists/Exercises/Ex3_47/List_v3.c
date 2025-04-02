/*
Exercise 3.48

Write a function that frees (calls free with a pointer to)
all the nodes on a given linked list

See implementation of freeAllNodes()

*/

#include "List_v3.h"

#include "../../../../MacroLibrary/DefaultCalloc.h"

#include <stdio.h>
#include <stdlib.h>

/**
 * @brief list of allocated, unused nodes
 * for use in lists.
 */
LISTNode* free_list;

LISTNode* LISTnew_node(LISTItem const k) {
    register LISTNode* x = DEFAULTCALLOC(*x);
    if (!x) 
    x->item = k;
    x->next = x;
    return x;
}

void LISTfree_node(LISTNode* const n) { free(n); }

void LISTfree_all_nodes(LISTNode* n) {
    register LISTNode* cur = n->next;
    while (cur != n) {
        register LISTNode* cur_n = cur->next;
        free(cur);
        cur = cur_n;
    }
    free(n);
}

void LISTinsert_next(LISTNode* const x, LISTNode* const y) {
    y->next = x->next;
    x->next = y;
}

LISTNode* LISTdelete_next(LISTNode* const x) {
    register LISTNode* t = x->next;
    x->next = t->next;
    return t;
}

LISTNode* LISTnext(LISTNode const* const x) { return x->next; }

LISTItem LISTitem(LISTNode const* const x) { return x->item; }

void LISTprint_list(LISTNode const* h) {
    register LISTNode const* cur = h;
    do {
        printf("%zu->", cur->item);
        cur = cur->next;
    } while (cur != h);
    printf("X\n");
}
