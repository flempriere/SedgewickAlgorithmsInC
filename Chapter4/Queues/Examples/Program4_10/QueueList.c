/**
 * @file QueueList.c
 * @author Felix Lempriere
 * @brief This code implements the Queue interface in Program 4.9 using
 * a linked list. The implementation is very similar to Program 4.5's
 * implementation of the stack interface with a linked list.
 *
 * To maintain the queue policy of removing the oldest first, we maintain
 * a pointer to the tail of the list, and new nodes are added as the new tail.
 * @version 0.1
 * @date 2025-03-11
 * 
 * @copyright Copyright (c) 2025
 * 
 */

 #include <stdlib.h>
 #include "../../../AbstractObjects/Examples/intItem/Item.h"
 #include "../Program4_9/Program4_9.h"

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
    x->item = item;
    x->next = next;
    return x;
 }

 void QUEUEinit(size_t size) {
    head = nullptr;
 }

 bool QUEUEempty(void) {
    return !head;
 }

 void QUEUEput(Item i) {
    if (!head) {
        head = (tail = NEW(i, head));
        return;
    }
    tail->next = NEW(i, tail->next);
    tail = tail->next;
 }

 Item QUEUEget(void) {
    Item item = head->item;
    QUEUEnode* t = head->next;
    free(head);
    head = t;
    return item;
 }


