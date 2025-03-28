/*
Exercise 3.50

Reimplement Program 3.12 and Program 3.13 to use
malloc and free directly in newNode and freeNode

*/

#include "List_v2.h"

#include "../../../../MacroLibrary/Utility.h"

#include <stdio.h>
#include <stdlib.h>

LISTNode* LISTnew_node(LISTItem const k) {
    LISTNode* x = calloc(1, SIZEOF_VARTYPE(*x));
    x->item = k;
    x->next = x;
    return x;
}

void LISTfree_node(LISTNode* const n) { free(n); }

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
