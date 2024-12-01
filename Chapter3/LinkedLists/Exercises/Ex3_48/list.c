/*
Exercise 3.48

Write a program that frees the nodes in positions
that are divisible by 5 in a linkedlist.

We modify the linked list to use a nullptr tail
rather than a circular list.

*/

#include <stdlib.h>
#include <stdio.h>
#include "list.h"

/**
 * @brief list of allocated, unused nodes
 * for use in lists.
 */
ListNode* freeList;

ListNode *newNode(ListItem k)
{
    ListNode* x = malloc(sizeof(typeof_unqual(*x)));
    x->item = k;
    x->next = nullptr;
    return x;
}

void freeNode(ListNode* n) {
    free(n);    
}

ListNode* freeEveryFifthNode(ListNode* n) {
    ListNode* cur = n;
    size_t i = 1;
    while (cur->next) {
        if (!((i+1) % 5)) {
            free(deleteNext(cur));
            i++;
            if (!(cur->next)) break;
        }
        cur = cur->next;
        i++;
    }
    return n;
}

void printList(ListNode* h) {
    for (; h != nullptr; h = h->next) {
        printf("%zu->", h->item);
    }
    printf("X\n");
}

void insertNext(ListNode* x, ListNode* y) {
    y->next = x->next;
    x->next = y;
}

ListNode* deleteNext(ListNode* x)
{
    ListNode* t = x->next;
    x->next = t->next;
    return t;
}

ListNode* next(ListNode* x)
{
    return x->next;
}

ListItem Item(ListNode* x)
{
    return x->item;
}
