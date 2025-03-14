/**
 * @file Stack_Array_forgetOld.c
 * @brief Stack implementation utilising an array and
 * forget old no duplicates policy. Utilises Stack_v3
 * interface for error handling.
 * 
 * @version 0.1
 * @date 2024-12-28
 * 
 * @copyright Copyright (c) 2024
 * 
 */

 #include <stdio.h>
 #include <stdlib.h>
 #include "../../../AbstractObjects/Examples/intItem/Item.h"
 #include "../Ex4_48/Stack_v3.h"
 
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
     return N;
 }
 
 bool STACKpush(Item i) {
    //find match
    size_t idx;
    for (size_t idx = 0; (idx < N) && (!ITEMeq(s[idx],i)); idx++);
    if (idx != N) { // idx == N means no match
        for (; idx+1 < N; idx++) { // shuffle down the array
            s[idx] = s[idx+1];
        }
        s[N-1] = i; //put new item in
        return true; 
    } else if (N < size) {
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

 void STACKerror(char *msg) {
    fprintf(stderr, "Error: %s\n", msg);
 }
 
 