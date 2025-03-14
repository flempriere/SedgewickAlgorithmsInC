/**
 * @file Queue_List_forgetOld.c
 * @author Felix Lempriere
 * @brief Implements the Queue_v2 interface with an ignore New no duplicates
 * policy. To make the find duplicate code easier we use a dummy head and
 * self referential tail.
 * @version 0.1
 * @date 2025-03-11
 * 
 * @copyright Copyright (c) 2025
 * 
 */

 #include <stdio.h>
 #include <stdlib.h>
 #include "../../../../AbstractObjects/Examples/intItem/Item.h"
 #include "../../../../Queues/Exercises/Ex4_32/Queue_v2.h"

 /**
  * @brief Structure for a node containing an
  * element in the Queue.
  * 
  */
 typedef struct QUEUEnode QUEUEnode;

 /**
  * @brief Structure for an element in the Queue.
  * Contains the element, and a pointer to the next
  * element on the queue.
  * 
  */
 struct QUEUEnode {
    Item item;
    QUEUEnode* next;
 };

 /**
  * @brief Pointer to the head of the Queue.
  * 
  */
 static QUEUEnode* head;
 /**
  * @brief Pointer to the tail of the Queue.
  * 
  */
 static QUEUEnode* tail;
 
 /**
  * @brief Create a new QueueNode storing the Item item
  * and pointing to itself, it is inserted into the list
  * after prev.
  * 
  * @param item Item to store in the QueueNode
  * @param prev Node to insert the new node after.
  *
  * @return QUEUEnode* pointer to the new QUEUEnode on success, else
  * @return nullptr.
  */
 static QUEUEnode* NEW(Item item, QUEUEnode* prev) {
    QUEUEnode* x = malloc(sizeof(typeof(*x)));
    if (!x) {
        QUEUEerror("failed to initialise new queue node");
    }
    else {
        x->item = item;
        x->next = x;
        prev->next = x;    
    }
    return x;
 }

 bool QUEUEinit(size_t size) {
    head = malloc(sizeof(typeof(*head)));
    if (!head) {
        fprintf(stderr, "failed to initialise the Queue\n");
        return false;
    }
    head->next = head;
    tail = head;
    return true;
 }

 bool QUEUEempty(void) {
    return head->next = head;
 }

 bool QUEUEput(Item i) {
    //if empty list, insert it.
    if (QUEUEempty()) {
        QUEUEnode* new = NEW(i, tail);
        if (new) tail = tail->next;
        return true;
    }
    //quickly check the tail.
    if (ITEMeq(tail->item, i)) {
        tail->item = i;
        return true;
    }
    //find node, BEFORE the match.
    QUEUEnode* cur;
    for (cur = head; cur != tail && (ITEMeq(cur->next->item, i)); cur = cur->next);
    
    if (cur != tail) { //match found
        //move the matched node to the tail.
        QUEUEnode* t = cur->next;
        cur->next = t->next;
        tail->next = t;
        t->next = t;
        tail = tail->next;

        t->item = i; //update item
        return true; 
    }
    // else make new node;
    QUEUEnode* new = NEW(i, tail);
    if (new) {
        tail = tail->next;
        return true;
    }
    else return false;
 }

 bool QUEUEget(Item* dest) {
    if (QUEUEempty()) {
        QUEUEerror("get failed, queue empty");
        return false;
    }
    *dest = head->next->item;
    QUEUEnode* t = head->next;
    head->next = (t == tail) ? head : t->next; //maintain self-referential tail.
    free(t);
    return true;
 }

void QUEUEerror(char *msg) {
    fprintf(stderr, "Error: %s\n", msg);
}

