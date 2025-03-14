/**
 * @file Stack_List_forgetOld.c
 * @brief Implementation of the Stack_v3 interface with a
 * forget old no duplicates policy. We change the representation to use
 * a dummy head.
 * 
 * @version 0.1
 * @date 2024-12-28
 * 
 * @copyright Copyright (c) 2024
 * 
 */

 #include <stdio.h>
 #include <stdlib.h>
 #include "../../../../AbstractObjects/Examples/intItem/Item.h"
 #include "../../Ex4_48/Stack_v3.h"
 
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
  * @brief private variable representing the stack head
  * 
  */
 static size_t N;
 
 /**
  * @brief Creates a new stack node with value
  * @item and pointing to @next. 
  * 
  * @param item 
  * @param next 
  * @return STACKnode* pointer to new STACKnode if successful else
  * @return nullptr.
  */
 STACKnode* NEW(Item item, STACKnode* next) {
     STACKnode* x = malloc(sizeof(typeof(*x)));
     if (x) {
        x->item = item;
        x->next = next;
     }
     else {
        STACKerror("failed to initialise new stack node");
     }
     return x;
 }
 
 bool STACKinit(size_t maxN) {
     //reset stack
     head = malloc(sizeof(typeof(*head)));
     if (!head) {
        STACKerror("failed to initialise stack");
        return false;
     }
     head->next = nullptr;
     N = 0;
     return true;
 }
 
 size_t STACKcount(void) {
     return N;
 }
 
 bool STACKpush(Item item) {
    STACKnode* cur;
    //iterate to find node BEFORE the match.
    for (cur = head; cur->next && (!ITEMeq(cur->next->item,item)); cur = cur->next);
    if (cur->next) {
        STACKnode* t = cur->next;
        t->item = item; // update the item and move t to the start.
        cur->next = t->next;
        t->next = head->next;
        head->next = t;
    }
    else { //add new node
        STACKnode* x = NEW(item, head->next);
        if (!x) return false;
        head->next = x;
        N++;
    }
    return true;
 }
 
 bool STACKpop(Item* dest) {

    if (STACKcount()) {
        *dest = head->next->item;
        STACKnode* t = head->next->next;
        free(head->next);
        head->next = t;
        N--;
        return true;
    }
    STACKerror("failed to pop, stack empty");
    return false;
 }

 void STACKerror(char *msg) {
    fprintf(stderr, "Error: %s\n", msg);
 }
 
 