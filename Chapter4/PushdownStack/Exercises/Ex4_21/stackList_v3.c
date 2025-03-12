/**
 * @file stackList_ex4_19.c
 * @brief stackList implementation with the updated stack interface
 * replacing STACKempty with STACKcount.
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
  * @return STACKnode* pointer to new STACKnode
  */
 STACKnode* NEW(Item item, STACKnode* next) {
     STACKnode* x = malloc(sizeof(typeof(*x)));
     if (!x) {
        STACKerror("failed to allocate memory for new stack element");
        return next;
     }
     x->item = item;
     x->next = next;
     
     return x;
 }
 
 bool STACKinit(size_t maxN) {
     //reset stack
     head = nullptr;
     return true;
 }
 
 /**
 * @brief Returns the number of elements on the stack
 * 
 * @return size_t number of elements on the stack.
 */
 size_t STACKcount(void) {
     size_t len = 0;
     for (STACKnode* cur = head; cur != nullptr; len++, cur = cur->next);
     return len;
 }
 
 bool STACKpush(Item item) {
     STACKnode* curhead = head;
     head = NEW(item, head);
     return (!(curhead == head)); //if equal push failed.
 }
 
 bool STACKpop(Item* dest) {
    if (head) {
        *dest = head->item;
        STACKnode* t = head->next;
        free(head);
        head = t;
    
        return true;
    }
    STACKerror("stack empty");
    return false;
 }

 void STACKerror(char* msg) {
    fprintf(stderr, "Error: %s\n", msg);
 }
 
 