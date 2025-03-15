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

#include <stdlib.h>
#include "List.h"

/**
 * @brief list of allocated, unused nodes
 * for use in lists.
 */
LISTNode* freeList;

void LISTinitNodes(size_t N) {
    freeList = malloc((N+1)*sizeof(typeof_unqual(*freeList)));
    for (size_t i = 0; i < N+1; i++) {
        freeList[i].next = &freeList[i+1];
    }
    freeList[N].next = nullptr;
}

LISTNode *LISTnewNode(LISTItem k)
{
    LISTNode* x = LISTdeleteNext(freeList);
    x->item = k;
    x->next = x;
    return x;
}

void LISTfreeNode(LISTNode* n) {
    LISTinsertNext(freeList, n);    
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
