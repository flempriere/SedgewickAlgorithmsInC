/*
Program 3.14

Implements the list-processing interface for Program 3.12.

The list is represented using a dummy head node and a nullptr-terminated tail

This implementation relies on the nodes being a fixed-size. A free list is
initialised to the maximum number of nodes that our program uses, all linked.

When a node is allocated, it is removed from the free list. Conversely a
deallocated node is returned to the free list.

By convention, client programs do not refer to list nodes except through
function calls, and nodes returned to client programs have self-links. These
conventions protect against undefined parameters.

*/

#include <stdlib.h>
#include "list.h"

ListNode* freeList;

void initNodes(size_t N) {
    freeList = malloc((N+1)*sizeof(typeof_unqual(*freeList)));
    for (size_t i = 0; i < N+1; i++) {
        freeList[i].next = &freeList[i+1];
    }
    freeList[N].next = nullptr;
}

ListNode *newNode(ListItem k)
{
    ListNode* x = deleteNext(freeList);
    x->item = k;
    x->next = x;
    return x;
}

void freeNode(ListNode *n) {
    insertNext(freeList, n);    
}

void insertNext(ListNode *x, ListNode *y) {
    y->next = x->next;
    x->next = y;
}

ListNode* deleteNext(ListNode *x)
{
    ListNode* t = x->next;
    x->next = t->next;
    return t;
}

ListNode* next(ListNode *x)
{
    return x->next;
}

ListItem Item(ListNode *x)
{
    return x->item;
}
