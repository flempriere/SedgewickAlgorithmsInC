/**
 * @file stackArray_v3.c
 * @brief Extends stackArray_v2.c with the STACKError function
 * which is called on pop or push failing.
 * 
 * @version 3.0
 * @date 2024-12-28
 * 
 * @copyright Copyright (c) 2024
 * 
 */
 #include <stdio.h>
 #include <stdlib.h>
 #include "Item.h"
 #include "stack_v3.h"
 
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
  * @brief private variable storing the maximum capacity
  * 
  */
 static size_t CAPACITY;
 
 
 bool STACKinit(size_t capacity) {
     s = malloc(capacity * sizeof(typeof(*s)));
     if (!s) {
        STACKerror("failed to allocate memory for stack");
        return false;
     }
     N = 0;
     CAPACITY = capacity;
     return true;
 }
 
 size_t STACKcount(void) {
     return N;
 }
 
 bool STACKpush(Item i) {
    if (N == CAPACITY) {
        STACKerror("stack at capacity");
        return false;
    }
     s[N++] = i;
     return true;
 }
 
 bool STACKpop(Item* dest) {
    if (N) {
        *dest = s[--N];
        return true;
    }
    STACKerror("stack empty");
    return false;
 }

 void STACKerror(char* msg) {
    fprintf(stderr, "Error: %s\n", msg);
 }
 
 