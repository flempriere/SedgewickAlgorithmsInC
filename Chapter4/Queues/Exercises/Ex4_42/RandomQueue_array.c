/**
 * @file RandomQueue_array.c
 * @author Felix Lempriere
 * @brief Implementation of the random queue interface using an
 * array. We fill the array bottom up, tracking its size, when we perform a
 * get we randomly chose the index and return it. 
 
 * To avoid shifting the entire
 * array contents we swap the removed item with the item in the index size-1,
 * this preserves the remaining elements in the indices [0 ... (size - 2)] which
 * is the new extent of the array. The removed while will be overwritten by the
 * next write.
 * @version 0.1
 * @date 2025-03-13
 * 
 * @copyright Copyright (c) 2025
 * 
 */

 #include "../../../AbstractObjects/Examples/intItem/Item.h"
 #include "RandomQueue.h"
 #include <stdlib.h>
 #include <stdio.h>

 /**
  * @brief Contents of the random queue.
  * 
  */
 static Item* rq;

 /**
  * @brief number of elements in the random queue.
  * 
  */
 static size_t rq_size;

 /**
  * @brief Maximum number of elements in the random queue.
  * 
  */
 static size_t rq_capacity;

/**
 * @brief Swaps two elements on the random queue.
 *
 * @param A first element to swap
 * @param B second element to swap
 * 
 */
 #define RANDOMQUEUESWAP(A, B) do { \
    typeof(A) tmp = (A);            \
    (A) = (B);                      \
    (B) = tmp;                      \
 } while(0)                         \
 
 bool RANDOMQUEUEinit(size_t size) {
    rq = malloc(size * sizeof(typeof(*rq)));
    if (!rq) {
        RANDOMQUEUEerror("Failed to initialise Random Queue");
        return false;
    }
    rq_size = 0;
    rq_capacity = size;
    return true;
 }

 bool RANDOMQUEUEempty(void) {
    return !rq_size;
 }

 bool RANDOMQUEUEput(Item i) {
    if (rq_size == rq_capacity) {
        RANDOMQUEUEerror("failed to put, random queue is full");
        return false;
    }
    rq[rq_size++] = i;
    return true;
 }

 bool RANDOMQUEUEget(Item* dest) {
    if (RANDOMQUEUEempty()) {
        RANDOMQUEUEerror("failed to get, random queue empty");
        return false;
    }
    size_t idx = rand() % rq_size;
    RANDOMQUEUESWAP(rq[idx], rq[rq_size - 1]); //idx to remove to end
    *dest = rq[--rq_size]; //remove last item.
    return true;
 }

 void RANDOMQUEUEerror(char *msg) {
    fprintf(stderr, "Error: %s\n", msg);
 }

