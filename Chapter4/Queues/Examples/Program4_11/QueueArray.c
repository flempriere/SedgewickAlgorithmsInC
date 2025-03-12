/**
 * @file QueueArray.c
 * @author Felix Lempriere
 * @brief Implementation of the Queue.h interface in Program 4.9
 * utilising an array. We use a head and tail idx to keep track of
 * the proportion of the array currently in use by the Queue (with wraparound).
 *
 * The array is thus effectively a circular buffer.
 *
 * @version 0.1
 * @date 2025-03-11
 * 
 * @copyright Copyright (c) 2025
 * 
 */

 #include <stdlib.h>
 #include "../../../AbstractObjects/Examples/intItem/Item.h"
 #include "../Program4_9/Queue.h"

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

 void QUEUEinit(size_t size) {
    
    q = malloc((size + 1) * sizeof(typeof(*q)));
    N = size + 1;
    head = N;
    tail = 0;
 }

 bool QUEUEempty(void) {
    return ((head % N) == tail);
 }

 void QUEUEput(Item i) {
    q[tail++] = i;
    tail %= N; 
 }

 Item QUEUEget(void) {
    head %= N;
    return q[head++];
 }