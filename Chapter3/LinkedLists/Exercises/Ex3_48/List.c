/*
Exercise 3.48

Write a program that frees the nodes in positions
that are divisible by 5 in a linkedlist.

We modify the linked list to use a nullptr tail
rather than a circular list.

*/

#include "../../../../MacroLibrary/Utility.h"
#include "List_div5.h"

#include <stdio.h>
#include <stdlib.h>

LISTNode* LISTnew_node(LISTItem const k) {
    LISTNode* x = calloc(1, SIZEOF_VARTYPE(*x));
    x->item = k;
    x->next = nullptr;
    return x;
}

void LISTfree_node(LISTNode* const n) { free(n); }

LISTNode* LISTfree_every_fifth_node(LISTNode* const n) {
    register LISTNode* cur = n;
    register size_t i = 1;
    while (cur->next) {
        if (!((i + 1) % 5)) {
            free(LISTdelete_next(cur));
            i++;
            if (!(cur->next)) break;
        }
        cur = cur->next;
        i++;
    }
    return n;
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

void LISTfree_all_nodes(LISTNode* n) {
    do {
        register LISTNode* cur = n->next;
        free(n);
        n = cur;
    } while (n);
}

LISTNode* LISTnext(LISTNode const* const x) { return x->next; }

LISTItem LISTitem(LISTNode const* const x) { return x->item; }

void LISTprint_list(LISTNode const* h) {
    register LISTNode const* cur = h;
    do {
        printf("%zu->", cur->item);
        cur = cur->next;
    } while (cur);
    printf("X\n");
}