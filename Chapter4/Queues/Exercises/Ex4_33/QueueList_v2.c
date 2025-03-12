/**
 * @file QueueList_v2.c
 * @author Felix Lempriere
 * @brief Updates the QueueList implementation to conform to the
 * Queue_v2.h interface with error handling capability. Calling QUEUEerror
 * where appropriate.
 *
 * @version 0.1
 * @date 2025-03-11
 * 
 * @copyright Copyright (c) 2025
 * 
 */

 #include <stdio.h>
 #include <stdlib.h>
 #include "../../../AbstractObjects/Examples/intItem/Item.h"
 #include "../Ex4_32/Queue_v2.h"

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
    if (!x) {
        QUEUEerror("failed to allocate memory for new Queue element");
        return next;
    }
    x->item = item;
    x->next = next;
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
        head = (tail = NEW(i, head));
        return head; // head must be nolonger null if succeeded.
    }
    //tail->next is always nullptr, so check for failure by nullptr
    tail->next = NEW(i, tail->next);
    if (!(tail->next)) return false;
    tail = tail->next;
    return true;//tail must have changed if succeeded.
 }

 bool QUEUEget(Item* dest) {

    if (QUEUEempty()) {
        QUEUEerror("Queue is empty");
        return false;
    }

    *dest = head->item;
    QUEUEnode* t = head->next;
    free(head);
    head = t;
    return true;
 }

 void QUEUEerror(char *msg) {
    fprintf(stderr, "Error: %s\n", msg);
 }


