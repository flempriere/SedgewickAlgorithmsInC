/*
Exercise 3.49

Write a program that frees the nodes in even positions

We modify the linked list to use a nullptr tail
rather than a circular list.

*/

#include "../../../../MacroLibrary/Utility.h"
#include "List_removeEven.h"

#include <stdio.h>
#include <stdlib.h>

LISTNode* LISTnew_node(LISTItem const k) {
    LISTNode* x = calloc(1, SIZEOF_VARTYPE(*x));
    x->item = k;
    x->next = nullptr;
    return x;
}

void LISTfree_node(LISTNode* n) { free(n); }

LISTNode* LISTfree_every_second_node(LISTNode* const n) {
    LISTNode* cur = n;
    bool delete = true;
    while (cur->next) {
        if (delete) {
            free(LISTdelete_next(cur));
            delete = !delete;
            if (!(cur->next)) break;
        }
        cur = cur->next;
        delete = !delete;
    }
    return n;
}

void LISTinsert_next(LISTNode* const x, LISTNode* const y) {
    y->next = x->next;
    x->next = y;
}

LISTNode* LISTdelete_next(LISTNode* const x) {
    LISTNode* t = x->next;
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
    for (; h != nullptr; h = h->next) { printf("%zu->", h->item); }
    printf("X\n");
}