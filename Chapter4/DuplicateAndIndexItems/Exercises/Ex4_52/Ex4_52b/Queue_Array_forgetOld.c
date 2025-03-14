/**
 * @file Queue_Array_forgetOld.c
 * @author Felix Lempriere
 * @brief Variant of the Queue_v2 implementation from Exercise 4.32 with a
 * forget-the-old policy.
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
    if (tail+1 == head) {
        QUEUEerror("put failed, queue full");
        return false;
    }
    // check if already last
    if (ITEMeq(q[(tail) ? tail-1 : N-1], i)) {
        q[tail] = i;
        return true;
    }
    //find match
    size_t idx;
    for (idx = (head % N); (idx != tail) && (ITEMeq(q[idx],i)); idx++, idx %= N);

    if (idx != tail) {
        size_t nxt;
        for (; ((nxt = (idx+1) % N)) != tail; idx++, idx %= N) (q[idx] = q[nxt]);
        q[tail-1] = i;
    } else {
        q[tail++] = i;
        tail %= N; 
    }
    return true;
 }

 bool QUEUEget(Item* dest) {
    if (QUEUEempty()) {
        QUEUEerror("get failed, queue empty");
        return false;
    }
    head %= N;
    *dest = q[head++];
    return true;
 }

 void QUEUEerror(char *msg) {
    fprintf(stderr, "Error: %s\n", msg);
 }