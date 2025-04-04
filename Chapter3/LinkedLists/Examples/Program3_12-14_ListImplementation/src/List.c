/*
Program 3.14

Implements the list-processing interface for Program 3.12.

This implementation relies on the nodes being a fixed-size. A free list is
initialised to the maximum number of nodes that our program uses, all linked.

When a node is allocated, it is removed from the free list. Conversely a
deallocated node is returned to the free list.

By convention, client programs do not refer to list nodes except through
function calls, and nodes returned to client programs have self-links. These
conventions protect against undefined parameters.

*/

#include "../List.h"

#include "MacroLibrary/DefaultCalloc.h"

#include <stdlib.h>

/**
 * @brief list of allocated, unused nodes
 * for use in lists.
 */
LISTNode* free_list;

bool LISTinit_nodes(size_t const N) {
    free_list = DEFAULTCALLOC(N + 1, *free_list);
    if (!free_list) return false;

    for (register size_t i = 1; i < N + 1; i++) {
        free_list[i - 1].next = &free_list[i];
    }

    free_list[N].next = nullptr;
    return true;
}

LISTNode* LISTnew_node(LISTItem const k) {
    LISTNode* x = LISTdelete_next(free_list);
    if (x != nullptr) {
        x->item = k;
        x->next = x;
    }
    return x;
}

void LISTfree_node(LISTNode n[const static 1]) {
    LISTinsert_next(free_list, n);
}

void LISTinsert_next(LISTNode x[const static 1], LISTNode y[const static 1]) {
    y->next = x->next;
    x->next = y;
}

LISTNode* LISTdelete_next(LISTNode x[const static 1]) {
    LISTNode* t = x->next;
    if (t) x->next = t->next;
    return t;
}

void LISTdeinit_list(void) { free(free_list); }

LISTNode* LISTnext(LISTNode const x[const static 1]) { return x->next; }

LISTItem LISTitem(LISTNode const x[const static 1]) { return x->item; }
