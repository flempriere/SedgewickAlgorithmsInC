/**
 * @file IndexedQueue_List_forgetOld.c
 * @author Felix Lempriere
 * @brief FIFO Queue implementation assuming all indices are between 0 and
 * maxN - 1.
 *
 * Uses a circular doubly-linked list with a dummy head as the underlying
 * representation and a seen array of pointers to nodes for quick
 * duplicate checking.
 *
 * @version 0.1
 * @date 2025-03-14
 * 
 * @copyright Copyright (c) 2025
 * 
 */

 #include <stdio.h>
 #include <stdlib.h>
 #include <stdint.h>
 #include "IndexedQueue.h"

/**
 * @brief Represents a node in an Indexed Queue.
 * 
 */
 typedef struct IndexedQueueNode IndexedQueueNode;

/**
 * @brief IndexedQueueNode containing an idx and links
 * to the previous and next nodes.
 * 
 */
 struct IndexedQueueNode {
    size_t idx;
    IndexedQueueNode* next;
    IndexedQueueNode* prev;
 };

/**
 * @brief dummy head for the Queue.
 * 
 */
 static IndexedQueueNode* head;

 /**
  * @brief Array containing links to nodes such that
  * if i is in the list, then idxLink[i] is a pointer
  * to the node with idx value i.
  * 
  */
 static IndexedQueueNode** idxLink;

 /**
  * @brief Largest index that can be included in the set.
  */
 static size_t maxIdx;


 bool INDEXEDQUEUEinit(size_t capacity) {
    head = malloc(sizeof(typeof(*head)));
    idxLink = calloc(capacity, sizeof(typeof(*idxLink)));
    if (head && idxLink) {
        head->next = head;
        head->prev = head;
        maxIdx = capacity - 1;
        return true;
    }
    INDEXEDQUEUEerror("failed to initialise queue");
    return false;
 }

 bool INDEXEDQUEUEempty(void) {
    return (head == head->next);
 }

/**
 * @brief Creates a new node with idx i, and sets its next
 * node to be the argument next.
 * 
 * @param i idx for the new node.
 * @param next IndexedQueueNode* to set as the next node.
 * @return IndexedQueueNode* 
 */
 static IndexedQueueNode* NEW(size_t i, IndexedQueueNode* next) {
    IndexedQueueNode* new = malloc(sizeof(typeof(*new)));
    if (!new) INDEXEDQUEUEerror("failed to allocate new IndexedQueueNode");
    else {
        new->next = next;
        new->prev = next->prev;
        next->prev->next = new;
        next->prev = new;
    }
    return new;

 }

 bool INDEXEDQUEUEput(size_t i) {
    if (i > maxIdx) {
        INDEXEDQUEUEerror("put failed, idx is larger than maxIdx");
        return false;
    }
    IndexedQueueNode* old = idxLink[i];
    //not on the queue, add it.
    if (!old) {
        IndexedQueueNode* new = NEW(i, head->next);
        if (!new) return false;
        idxLink[i] = new;
        return true;
    }
    old->idx = i; //update the item.
    //if already most recent, don't need to move it.
    if (old == head->next) return true;

    // remove links coming into old.
    old->next->prev = old->prev;
    old->prev->next = old->next;
    
    //move old to after dummy head
    old->prev = head;
    head->next->prev = old;
    old->next = head->next;
    head->next = old;

    return true;
 }


 size_t INDEXEDQUEUEget(void) {
    if (INDEXEDQUEUEempty()) {
        INDEXEDQUEUEerror("get failed, queue empty");
        return SIZE_MAX;
    }
    IndexedQueueNode* t = head->prev;
    t->prev->next = t->next;
    t->next->prev = t->prev;

    size_t val = t->idx;
    free(t);
    idxLink[val] = nullptr;
    return val;
 }

 void INDEXEDQUEUEerror(char *msg) {
    fprintf(stderr, "Error: %s\n", msg);
 }