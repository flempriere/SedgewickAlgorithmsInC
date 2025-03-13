/**
 * @file DequeArray.c
 * @author Felix Lempriere
 * @brief Extends the Array implementation of Deque to conform to the Deque_v2
 * interface.
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
  * @brief Array representing the Queue.
  * 
  */
 static Item* q;

 /**
  * @brief Capacity of the queue.
  * 
  */
 static size_t N;
 /**
  * @brief idx of the first element in the queue.
  * 
  */
 static size_t head;
 /**
  * @brief idx of the last element in the queue.
  * 
  */
 static size_t tail;

 bool DEQUEinit(size_t size) {
    
    q = malloc((size + 1) * sizeof(typeof(*q)));
    if (!q) {
        DEQUEerror("failed to initialise Deque.");
        return false;
    }
    N = size + 1;
    head = N;
    tail = 0;
    return true;
 }

 bool DEQUEempty(void) {
    return ((head % N) == tail);
 }

 /**
  * @brief Puts the Item i at the beginning of the Deque. Assumes
  * DEQUEput has been used to validate input.
  * 
  * @param i Item to put on the Deque.
  */
 static void DEQUEputBeginning(Item i) {
    head = (head) ? ((head - 1) % N) : N - 1;
    q[head] = i;
 }

 /**
  * @brief Puts the Item i at the end of the Deque. Assumes
  * DEQUEput has been used to validate input.
  * 
  * @param i Item to put on the Deque.
  */
 static void DEQUEputEnd(Item i) {
    q[tail++] = i;
    tail %= N;
 }

 bool DEQUEput(Item i, e_DequeSide side) {
    if ((tail + 1) == head) {
        DEQUEerror("Cannot put on a full Deque");
        return false;
    }
    (side == DEQUE_eBEGINNING) ? DEQUEputBeginning(i) : DEQUEputEnd(i);
    return true; 
 }

 /**
  * @brief Get an item from the beginning of the Deque.
  *
  * Assumes DEQUEget has been called for error checking.
  * 
  * @return Item 
  */
 static Item DEQUEgetBeginning(void) {
    head %= N;
    return q[head++];
 }

  /**
  * @brief Get an item from the end of the Deque.
  *
  * Assumes DEQUEget has been called for error checking.
  * 
  * @return Item 
  */
 static Item DEQUEgetEnd(void) {
    tail = (tail) ? ((tail - 1) % N) : N-1; 
    return q[tail];
 }

 bool DEQUEget(Item* dest, e_DequeSide side) {
    if (DEQUEempty()) {
        DEQUEerror("Cannot get from empty deque");
        return false;
    }
    *dest = ((side == DEQUE_eBEGINNING) ? DEQUEgetBeginning() : DEQUEgetEnd()); 
    return true;
 }

 void DEQUEerror(char *msg) {
    fprintf(stderr, "Error: %s\n", msg);
 }


 void DEQUEdump(void) {
    for (size_t i = head; (i % N) != tail; i = (i + 1) % N) {
        ITEMshow(q[i]);
    }
 }