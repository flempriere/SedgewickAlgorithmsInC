/**
 * @file RandomQueue_array.c
 * @author Felix Lempriere
 * @brief Implementation of the RandomQueue using an array, we have changed
 * the Item.h reference to the Item.h wrapper for a playing card.
 * @version 0.1
 * @date 2025-03-13
 * 
 * @copyright Copyright (c) 2025
 * 
 */

 #include "Item.h"
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
 #define RANDOMQUEUESWAP(A, B) do {\
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
    RANDOMQUEUESWAP(rq[idx], rq[rq_size-1]); //idx to remove to end
    *dest = rq[--rq_size]; //remove last item.
    return true;
 }

 void RANDOMQUEUEerror(char *msg) {
    fprintf(stderr, "Error: %s\n", msg);
 }

