/*
Exercise 3.52

Implementation of List interface using parallel arrays

*/

#include <stdlib.h>
#include "list.h"

/**
 * @brief list of allocated, unused nodes
 * for use in lists.
 */
ListNode freeList;

ListItem* item;
ListNode* next;

void initNodes(size_t N) {
    
    next = malloc((N)*sizeof(typeof_unqual(*next)));
    item = malloc((N)*sizeof(typeof_unqual(*item)));

    freeList = 0;
    for (size_t i = 0; i < N; i++) {
        next[i] = i+1;
    }
    next[N-1] = LIST_FULL;
}

ListNode newNode(ListItem k)
{
    if (freeList == LIST_FULL) {
        return LIST_FULL;
    }
    ListNode x = freeList;
    freeList = next[freeList];
    item[x] = k;
    next[x] = x;
    
    return x;
}

void freeNode(ListNode n) {
    next[n] = freeList;
    freeList = n;
}

void insertNext(ListNode x, ListNode y) {
    next[y] = next[x];
    next[x] = y;
}

ListNode deleteNext(ListNode x)
{
    ListNode t = next[x];
    if (!(t == LIST_FULL)) {
        next[x] = next[t];
    }
    return t;
}

ListNode Next(ListNode x)
{
    return next[x];
}

ListItem Item(ListNode x)
{
    return item[x];
}
