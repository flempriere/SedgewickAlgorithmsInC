/*
Linked List interface suggested in Program 3.11
*/

#include <stddef.h>

typedef size_t ListItem;
typedef struct node ListNode;

struct node {
    ListItem item;
    ListNode* next;
};

void initNodes(size_t N);
ListNode* newNode(ListItem k);
void freeNode(ListNode* n);
void insertNext(ListNode* x, ListNode* y);
ListNode* deleteNext(ListNode* x);
ListNode* next(ListNode* x);
ListItem Item(ListNode* x); 


