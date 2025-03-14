/**
 * @file Queue_Array_ignoreNew.c
 * @author Felix Lempriere
 * @brief Implementation of the Queue_v2 interface introduced in Ex4.32 with an
 * ignore new no duplicates policy.
 *
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
      QUEUEerror("failed to initialise queue");
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
    if(tail + 1 == head) {
        QUEUEerror("failed to put, queue fulll");
        return false;
    }
    for (size_t idx = (head % N); idx != tail; idx++, idx %= N) {
        if (ITEMeq(q[idx], i)) return true;
    }
    q[tail++] = i;
    tail %= N;
    return true; 
 }

 bool QUEUEget(Item* dest) {
    if (QUEUEempty()) {
        QUEUEerror("failed to get, queue empty");
        return false;
    }
    head %= N;
    *dest = q[head++];
    return true;
 }

 void QUEUEerror(char *msg) {
    fprintf(stderr, "Error: %s\n", msg);
 }