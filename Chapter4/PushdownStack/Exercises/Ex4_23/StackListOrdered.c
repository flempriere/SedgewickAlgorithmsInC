/**
 * @file stackList_ex4_19.c
 * @brief stackList implementation with the updated stack interface
 * replacing STACKempty with STACKcount.
 *
 * This version also uses a circular doubly linked list with a dummy head
 * to keep elements ordered
 * least to most recent and still enable popping in O(1) time.
 * 
 * @version 0.1
 * @date 2024-12-28
 * 
 * @copyright Copyright (c) 2024
 * 
 */

 #include <stdio.h>
 #include <stdlib.h>
 #include "Item.h"
 #include "stack_v3.h"
 
 /**
  * @brief Linked List structure representing a stack.
  * Contains an item on the stack and link to the previously
  * pushed member.
  */
 typedef struct STACKnode STACKnode;
 
 struct STACKnode {
     Item item;
     STACKnode* next;
     STACKnode* prev;
 };
 
 /**
  * @brief Private variable pointing to the top of the stack
  * 
  */
 static STACKnode* head;
 
 /**
  * @brief Creates a new stack node with value
  * @item and pointing to @next. 
  * 
  * @param item 
  * @param next 
  * @return STACKnode* pointer to new STACKnode or
  * @return nullptr if failed to allocate.
  */
 STACKnode* NEW(Item item) {
     STACKnode* x = malloc(sizeof(typeof(*x)));
     if (!x) {
        STACKerror("failed to allocate memory for new stack element");
        return nullptr;
     }
     x->item = item;
     return x;
 }
 
 bool STACKinit(size_t maxN) {
     head = malloc(sizeof(typeof(*head)));
     if (!head) {
        STACKerror("failed to allocate stack");
        return false;
     }
     head->next = head;
     head->prev = head;
     return true;

 }
 
 /**
 * @brief Returns the number of elements on the stack
 * 
 * @return size_t number of elements on the stack.
 */
 size_t STACKcount(void) {
     size_t len = 0;
     for (STACKnode* cur = head->next; cur != head; len++, cur = cur->next);
     return len;
 }
 
 bool STACKpush(Item item) {
    STACKnode* new = NEW(item);
    if (new) {
        new->prev = head->prev;
        head->prev->next = new;
        new->next = head;
        head->prev = new;
        return true;
    }
    return false;
 }
 
 bool STACKpop(Item* dest) {
    if (head->prev == head) {
        STACKerror("stack empty");
        return false;
    }
    STACKnode* pop = head->prev;
    head->prev = pop->prev;
    pop->prev->next = head;
    *dest = pop->item;
    free(pop);
    return true;
 }

 void STACKerror(char* msg) {
    fprintf(stderr, "Error: %s\n", msg);
 }
 
 