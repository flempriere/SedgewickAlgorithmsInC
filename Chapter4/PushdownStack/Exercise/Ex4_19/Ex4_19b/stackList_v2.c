/**
 * @file stackList_v2.c
 * @brief stackList implementation with the updated stack interface
 * replacing STACKempty with STACKcount.
 * 
 * @version 0.1
 * @date 2024-12-28
 * 
 * @copyright Copyright (c) 2024
 * 
 */

 #include <stdlib.h>
 #include "Item.h"
 #include "stack_v2.h"
 
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
     x->item = item;
     x->next = next;
     
     return x;
 }
 
 void STACKinit(int maxN) {
     //reset stack
     head = nullptr;
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
 
 void STACKpush(Item item) {
     head = NEW(item, head);
 }
 
 Item STACKpop(void) {
 
     Item item = head->item;
     STACKnode* t = head->next;
     free(head);
     head = t;
 
     return item;
 }
 
 