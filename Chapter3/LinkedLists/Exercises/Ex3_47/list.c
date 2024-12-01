/*
Exercise 3.48

Write a function that frees (calls free with a pointer to)
all the nodes on a given linked list

See implementation of freeAllNodes()

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
    x->next = x;
    return x;
}

void freeNode(ListNode* n) {
    free(n);    
}

void freeAllNodes(ListNode* n) {
    ListNode* cur = n->next;
    while (cur != n) {
        ListNode* cur_n = cur->next;
        free(cur);
        cur = cur_n;
    }
    free(n);
}

void printList(ListNode* h) {
    ListNode* cur = h;
    do {
        printf("%zu->", cur->item);
        cur = cur->next;
    } while(cur != h);
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
