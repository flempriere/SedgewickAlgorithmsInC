/**
 * @file IndexedStack_List_forgetOld.c
 * @author Felix Lempriere
 * @brief Pushdown stack implementation assuming all items
 * are indices between 0 and maxN - 1.
 *
 * Uses a circular doubly-linked list with a dummy head as the underlying representation
 * and a seen array of pointers to nodes for quick duplicate
 * checking. Using a dummy head makes the code manipulation more straight
 * forward.
 *
 *
 * @version 0.1
 * @date 2025-03-14
 * 
 * @copyright Copyright (c) 2025
 * 
 */

 #include <stdint.h>
 #include <stdio.h>
 #include <stdlib.h>
 #include "../../Examples/Program4_12/IndexedStack.h"

/**
 * @brief Represents a node in an Indexed Stack.
 * 
 */
 typedef struct IndexedStackNode IndexedStackNode;

 /**
  * @brief IndexedStackNode containing an idx
  * and links to the previous and next nodes.
  * 
  */
 struct IndexedStackNode {
     size_t idx;
     IndexedStackNode* next;
     IndexedStackNode* prev;
 };

 /**
  * @brief Head of the linked list
  * 
  */
 static IndexedStackNode* head;
 /**
  * @brief Array containing references such that if
  * index i is in the linked list, idxLink[i] is a pointer
  * to the node with idx i.
  * 
  */
 static IndexedStackNode** idxLink;

 /**
  * @brief The largest valid index in the stack.
  * 
  */
 static size_t maxIdx;

/**
 * @brief Number of elements in the stack.
 */
 static size_t N;

 bool INDEXEDSTACKinit(size_t maxN) {
    head = malloc(sizeof(typeof(*head)));
    idxLink = calloc(maxN, sizeof(typeof(*idxLink)));
    if (head && idxLink) {
        head->next = head;
        head->prev = head;
        maxIdx = maxN - 1;
        N = 0;
        return true;
    }
    INDEXEDSTACKerror("failed to initialise stack");
    return false;
 }

 size_t INDEXEDSTACKcount(void) {
      return N;
 }

/**
 * @brief Adds a new node to the Linked List with item value before next.
 * 
 * @param item value to store in the new node.
 * @param next Node to insert this new node before.
 * @return IndexedStackNode* pointer to new node if successfully allocated else
 * @return nullptr.
 */
 static IndexedStackNode* NEW(size_t item, IndexedStackNode* next) {
    IndexedStackNode* new = malloc(sizeof(typeof(*new)));
    if (!new) {
        INDEXEDSTACKerror("failed to initialise new stack node");
    }
    else {
        new->next = next;
        new->prev = next->prev;
        next->prev->next = new;
        next->prev = new;
    }
    return new;
 }

 bool INDEXEDSTACKpush(size_t idx) {
    
    if (idx > maxIdx) {
        INDEXEDSTACKerror("push failed, idx is larger than maxIdx");
        return false;
    }

    IndexedStackNode* old = idxLink[idx];
    //not in the stack, add it
    if (!old) {
        IndexedStackNode* new = NEW(idx, head->next);
        if (!new) return false;
        idxLink[idx] = new;
        N++;
        return true; 
    }
    if (head->next == head) return true; //already head, no need to rearrange.

    //remove references into old node.
    old->next->prev = old->prev;
    old->prev->next = old->next;

    //move to start of the queue.
    old->next = head->next;
    head->next->prev = old;
    old->prev = head;
    head->next = old;

    return true;
 }

 size_t INDEXEDSTACKpop(void) {
    if (INDEXEDSTACKcount()) {
        //adjust the head
        IndexedStackNode* t = head->next;
        head->next = t->next;
        t->next->prev = head;
        
        //clean up removed node.
        size_t val = t->idx;
        free(t);
        idxLink[val] = nullptr;
        return val;
    }
    INDEXEDSTACKerror("failed to pop, stack empty");
    return SIZE_MAX;
 }

 void INDEXEDSTACKerror(char *msg) {
    fprintf(stderr, "Error: %s\n", msg);
 }



