/*
Exercise 3.52

Implementation of List interface using parallel arrays

*/

#include <stdlib.h>
#include "List_wError.h"

/**
 * @brief list of allocated, unused nodes
 * for use in lists.
 */
LISTNode freeList;

LISTItem* item;
LISTNode* next;

void LISTinitNodes(size_t N) {
    
    next = malloc((N)*sizeof(typeof_unqual(*next)));
    item = malloc((N)*sizeof(typeof_unqual(*item)));

    freeList = 0;
    for (size_t i = 0; i < N; i++) {
        next[i] = i+1;
    }
    next[N-1] = LIST_FULL;
}

LISTNode LISTnewNode(LISTItem k)
{
    if (freeList == LIST_FULL) {
        return LIST_FULL;
    }
    LISTNode x = freeList;
    freeList = next[freeList];
    item[x] = k;
    next[x] = x;
    
    return x;
}

void LISTfreeNode(LISTNode n) {
    next[n] = freeList;
    freeList = n;
}

void LISTinsertNext(LISTNode x, LISTNode y) {
    next[y] = next[x];
    next[x] = y;
}

LISTNode LISTdeleteNext(LISTNode x)
{
    LISTNode t = next[x];
    if (!(t == LIST_FULL)) {
        next[x] = next[t];
    }
    return t;
}

LISTNode LISTnext(LISTNode x)
{
    return next[x];
}

LISTItem LISTitem(LISTNode x)
{
    return item[x];
}
