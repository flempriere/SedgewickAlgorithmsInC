/**
 * @file Queue_circularList.c
 * @author Felix Lempriere
 * @brief Implements the Queue_v2.h interface from Ex4.32 using
 * a circular linked list.
 *
 * We will use a dummy head representation.
 *
 * @version 0.1
 * @date 2025-03-13
 * 
 * @copyright Copyright (c) 2025
 * 
 */

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

static QUEUEnode* tail;


 bool QUEUEinit(size_t size) {
    head = nullptr;
    return true;
 }

 bool QUEUEempty(void) {
    return (!head); // empty circular list is just self-referential dummy head.

 }

 bool QUEUEput(Item i) {
    QUEUEnode* new = malloc(sizeof(typeof(*new)));
    if (!new) {
        QUEUEerror("failed to allocate memory for new Queue element");
        return false;
    }
    new->item = i;
    (!head) ? (head = new) : (tail->next = new);
    tail = new;
    tail->next = head;
    return true;
 }

 bool QUEUEget(Item* dest) {
    if (QUEUEempty()) {
        QUEUEerror("Queue is empty");
        return false;
    }
    *dest = head->item;

    QUEUEnode* t = head->next;
    tail->next = t;
    free(head);
    (head == t) ? (head = nullptr) : (head = t); // if head was last node null it.
    return true;
 }

 void QUEUEerror(char *msg) {
    fprintf(stderr, "Error: %s\n", msg);
 }


