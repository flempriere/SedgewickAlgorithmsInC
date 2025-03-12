/**
 * @file QueueArray_v2.c
 * @author Felix Lempriere
 * @brief Updates the QueueArray to refer to the new Queue_v2 interface
 * with error handling capability and calls QUEUEerror where appropriate.
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
 #include "Queue_v2.h"

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

 bool QUEUEinit(size_t size) {
    
    q = malloc((size + 1) * sizeof(typeof(*q)));
    if (!q) {
        QUEUEerror("failed to initialise Queue.");
        return false;
    }
    N = size + 1;
    head = N;
    tail = 0;
    return true;
 }

 bool QUEUEempty(void) {
    return ((head % N) == tail);
 }

 bool QUEUEput(Item i) {
    if ((tail + 1) == head) {
        QUEUEerror("Cannot put on a full queue");
        return false;
    }
    q[tail++] = i;
    tail %= N;
    return true; 
 }

 bool QUEUEget(Item* dest) {
    if (QUEUEempty()) {
        QUEUEerror("Cannot get from empty queue");
        return false;
    }
    head %= N;
    *dest = q[head++];
    return true;
 }

 void QUEUEerror(char *msg) {
    fprintf(stderr, "Error: %s\n", msg);
 }