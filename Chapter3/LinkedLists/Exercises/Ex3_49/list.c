/*
Exercise 3.49

Write a program that frees the nodes in even positions

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

ListNode* freeEverySecondNode(ListNode* n) {
    ListNode* cur = n;
    bool delete = true;
    while (cur->next) {
        if (delete) {
            free(deleteNext(cur));
            delete = !delete;
            if (!(cur->next)) break;
        }
        cur = cur->next;
        delete = !delete;
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
