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
 
 
 void STACKinit(size_t capacity) {
     s = malloc(capacity * sizeof(typeof(*s)));
     if (!s) {
        STACKerror("failed to allocate memory for stack");
        return;
     }
     N = 0;
     CAPACITY = capacity;
 }
 
 size_t STACKcount(void) {
     return N;
 }
 
 void STACKpush(Item i) {
    if (N == CAPACITY) {
        STACKerror("stack at capacity");
        return;
    }
     s[N++] = i;
 }
 
 Item STACKpop(void) {
    if (N) return s[--N];
    STACKerror("stack empty");
    return 0;
 }

 void STACKerror(char* msg) {
    fprintf(stderr, "Error: %s\n", msg);
 }
 
 