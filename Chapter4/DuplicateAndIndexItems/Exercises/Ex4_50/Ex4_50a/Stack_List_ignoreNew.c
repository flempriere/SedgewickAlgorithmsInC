/**
 * @file Stack_List_ignoreNew.c
 * @brief Implementation of the Stack_v3 interface including error handling
 * and an ignoreNew no duplicates policy.
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
  * @return STACKnode* pointer to new STACKnode if successfully allocated else
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
 
 bool STACKinit(size_t capacity) {
     //reset stack
     head = nullptr;
     N = 0;
     return true;
 }
 
 size_t STACKcount(void) {
     return N;
 }
 
 bool STACKpush(Item item) {
    for (STACKnode* cur = head; cur; cur = cur->next) {
        if (ITEMeq(cur->item, item)) return true;
    }
    STACKnode* new = NEW(item, head);
    if (new) {
        head = new;
        N++;
        return true;
    }
    return false;
 }
 
 bool STACKpop(Item* dest) {

    if (STACKcount()) {
        *dest = head->item;
        STACKnode* t = head->next;
        free(head);
        head = t;
        N--;
        return true;
    }
    STACKerror("failed to pop, stack empty");
    return false;
}

 void STACKerror(char *msg) {
    fprintf(stderr, "Error: %s\n", msg);
 }
 
 