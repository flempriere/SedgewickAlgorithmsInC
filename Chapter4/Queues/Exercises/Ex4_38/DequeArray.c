/**
 * @file DequeArray.c
 * @author Felix Lempriere
 * @brief Array implementation of a Deque based on the Deque.h interface.
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
 #include "../Ex4_37/Deque.h"

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
    head--;
    head %= N;
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

 static Item DEQUEgetBeginning(void) {
    head %= N;
    return q[head++];
 }

 static Item DEQUEgetEnd(void) {
    --tail;
    tail %= N;
    return q[tail];
 }

 bool DEQUEget(Item* dest, e_DequeSide side) {
    if (DEQUEempty()) {
        DEQUEerror("Cannot get from empty deque");
        return false;
    }
    *dest = (side == DEQUE_eBEGINNING) ? DEQUEgetBeginning() : DEQUEgetEnd(); 
    return true;
 }

 void DEQUEerror(char *msg) {
    fprintf(stderr, "Error: %s\n", msg);
 }