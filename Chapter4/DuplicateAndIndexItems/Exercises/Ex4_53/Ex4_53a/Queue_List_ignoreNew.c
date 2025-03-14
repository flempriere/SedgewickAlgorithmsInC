/**
 * @file Queue_List_ignoreNew.c
 * @author Felix Lempriere
 * @brief Implements the Queue_v2 interface with an ignore New no duplicates
 * policy.
 *
 * @version 0.1
 * @date 2025-03-11
 * 
 * @copyright Copyright (c) 2025
 * 
 */

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
  * and pointing to the next QueueNode next.
  * 
  * @param item Item to store in the QueueNode
  * @param next QueueNode* to set as the next QueueNode
  * @return QUEUEnode* pointer to the new QUEUEnode. 
  */
 static QUEUEnode* NEW(Item item, QUEUEnode* next) {
    QUEUEnode* x = malloc(sizeof(typeof(*x)));
    if (x) {
        x->item = item;
        x->next = next;
    }
    else {
        QUEUEerror("failed to initialise new queue node");
    }
    return x;
 }

 bool QUEUEinit(size_t size) {
    head = nullptr;
    return true;
 }

 bool QUEUEempty(void) {
    return !head;
 }

 bool QUEUEput(Item i) {
    if (!head) {
        QUEUEnode* new = NEW(i, head);
        if (!new) return false;
        tail = new;
        head = new;
        return true;
    }
    //find duplicate if it exists, and shortcircuit.
    for (QUEUEnode* cur = head; cur != tail; cur = cur->next) {
        if (ITEMeq(cur->item, i)) return true;
    }
    QUEUEnode* new = NEW(i, tail->next);
    if (!new) return false;
    tail->next = new;
    tail = tail->next;
    return true;
 }

 bool QUEUEget(Item* dest) {
    if (tail + 1 == head) {
        QUEUEerror("get failed, queue empty");
        return false;
    }
    *dest = head->item;
    QUEUEnode* t = head->next;
    free(head);
    head = t;
    return true;
 }


