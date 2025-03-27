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

#include "List.h"

#include "../../../../MacroLibrary/Utility.h"

#include <stdlib.h>

/**
 * @brief list of allocated, unused nodes
 * for use in lists.
 */
LISTNode* free_list;

void LISTinit_nodes(size_t const N) {
    free_list = calloc(N + 1, SIZEOF_VARTYPE(*free_list));
    for (register size_t i = 0; i < N + 1; i++) {
        free_list[i].next = &free_list[i + 1];
    }
    free_list[N].next = nullptr;
}

LISTNode* LISTnew_node(LISTItem const k) {
    LISTNode* x = LISTdelete_next(free_list);
    x->item = k;
    x->next = x;
    return x;
}

void LISTfree_node(LISTNode* const n) { LISTinsert_next(free_list, n); }

void LISTinsert_next(LISTNode* const x, LISTNode* const y) {
    y->next = x->next;
    x->next = y;
}

LISTNode* LISTdelete_next(LISTNode* const x) {
    LISTNode* t = x->next;
    x->next = t->next;
    return t;
}

LISTNode* LISTnext(LISTNode const* const x) { return x->next; }

LISTItem LISTitem(LISTNode const* const x) { return x->item; }
