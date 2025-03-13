/**
 * @file DequeList.c
 * @author Felix Lempriere
 * @brief Updates the List implementation of Deque to the Deque_v2 interface
 * by introducing DEQUEdump which prints the contents of the Deque.
 *
 * @version 0.1
 * @date 2025-03-11
 * 
 * @copyright Copyright (c) 2025
 * 
 */

 #include <stdio.h>
 #include <stdlib.h>
 #include "AsciiItem.h"
 #include "Deque_v2.h"

 /**
  * @brief Structure for a node containing an
  * element in the Deque.
  * 
  */
 typedef struct DEQUEnode DEQUEnode;

 /**
  * @brief Structure for an element in the Deque.
  * Contains the element, and a pointer to the next
  * element on the queue.
  * 
  */
 struct DEQUEnode {
    Item item;
    DEQUEnode* next;
    DEQUEnode* prev;
 };

 /**
  * @brief Pointer to the head of the Deque.
  * 
  */
 static DEQUEnode* head;
 
 /**
  * @brief Create a new DEQUENode storing the Item item.
  * 
  * @param item Item to store in the QueueNode

  * @return QUEUEnode* pointer to the new QUEUEnode if
  * successful, else
  * @return nullptr if failed to allocate. 
  */
 static DEQUEnode* NEW(Item item) {
    DEQUEnode* x = malloc(sizeof(typeof(*x)));
    if (!x) {
        DEQUEerror("failed to allocate memory for new Deque element");
        return nullptr;
    }
    x->item = item;
    x->next = nullptr;
    x->prev = nullptr;
    return x;
 }

 bool DEQUEinit(size_t size) {
    head = malloc(sizeof(typeof(*head)));
    if (!head) {
        DEQUEerror("failed to initialise Deque");
        return false;
    }
    head->next = head;
    head->prev = head;
    return true;
 }

 bool DEQUEempty(void) {
    return (head == head->next); //dummy head is only element if self refers.
 }

 /**
  * @brief Put a DEQUENode* new at the beginning of the Deque.
  * 
  * @param new new node to insert.
  */
 static void DEQUEputBeginning(DEQUEnode* new) {
    new->next = head->next;
    new->prev = head;
    head->next->prev = new;
    head->next = new;
 }

  /**
  * @brief Put a DEQUENode* new at the end of the Deque.
  * 
  * @param new new node to insert.
  */
 static void DEQUEputEnd(DEQUEnode* new) {
    new->prev = head->prev;
    head->prev->next = new;
    new->next = head;
    head->prev = new;
 }

 
 bool DEQUEput(Item i, e_DequeSide side) {
    DEQUEnode* new = NEW(i);
    if (!new) return false;

    if (side == DEQUE_eBEGINNING) DEQUEputBeginning(new);
    else if (side == DEQUE_eEND) DEQUEputEnd(new);
    return true;
 }

/**
  * @brief Get an item from the beginning of the Deque.
  *
  * Assumes DEQUEget has been called for error checking.
  * 
  * @return Item 
  */
 Item DEQUEgetBeginning(void) {

    DEQUEnode* x = head->next;
    x->next->prev = head;
    head->next = x->next;

    Item i = x->item;
    free(x);
    return i;
 }

/**
  * @brief Get an item from the end of the Deque.
  *
  * Assumes DEQUEget has been called for error checking.
  * 
  * @return Item 
  */
 Item DEQUEgetEnd(void) {

    DEQUEnode* x = head->prev;
    x->prev->next = head;
    head->prev = x->prev;

    Item i = x->item;
    free(x);
    return i;
 }

 bool DEQUEget(Item* dest, e_DequeSide side) {
    if (DEQUEempty()) {
        DEQUEerror("Queue is empty");
        return false;
    }
    if (side == DEQUE_eBEGINNING) {
        *dest = DEQUEgetBeginning();
    }
    else if (side == DEQUE_eEND) {
        *dest = DEQUEgetEnd();
    }
    return true;
 }

 void DEQUEerror(char *msg) {
    fprintf(stderr, "Error: %s\n", msg);
 }

 void DEQUEdump(void) {
    for (DEQUEnode* cur = head->next; cur != head; cur = cur->next) {
        ITEMshow(cur->item);
    }
 }


