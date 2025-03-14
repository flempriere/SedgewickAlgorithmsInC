/**
 * @file Stack_Array_ignoreNew.c
 * @brief Stack implementation utilising an array and
 * ignore new no duplicates policy. Utilises Stack_v3
 * interface to provide error handling.
 * 
 * @version 0.1
 * @date 2024-12-28
 * 
 * @copyright Copyright (c) 2024
 * 
 */

 #include <stdlib.h>
 #include "../../../AbstractObjects/Examples/intItem/Item.h"
 #include "Stack_v3.h"
 
 /**
  * @brief private array representing the stack
  * 
  */
 static Item* s;
 
 /**
  * @brief private variable representing the stack head
  * 
  */
 static size_t N;
 
 /**
  * @brief Maximum number of items that can be stored in the stack.
  * 
  */
 static size_t size;
 
 bool STACKinit(size_t capacity) {
     s = malloc(capacity * sizeof(typeof(*s)));
     if (!s) {
        STACKerror("failed to initalise stack");
        return false;
     }
     N = 0;
     size = capacity;
     return true;
 }
 
 size_t STACKcount(void) {
     return (N);
 }
 
 bool STACKpush(Item i) {
    //brute force bottom up scan to see if item already exists.
    for (size_t idx = 0; idx < N; idx++) {
        if (ITEMeq(s[idx],i)) return true;  //found, then early exit
    }
    if (N < size) {
        s[N++] = i;
        return true;
    }
    STACKerror("failed to push, stack full");
    return false;
 }
 
 bool STACKpop(Item* dest) {
    if (N) {
        *dest = s[--N];
        return true;
    }
    STACKerror("failed to pop, stack empty");
    return false;
 }
 
 