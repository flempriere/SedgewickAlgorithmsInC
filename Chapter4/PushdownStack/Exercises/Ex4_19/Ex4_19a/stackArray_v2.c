/**
 * @file stackArray_v2.c
 * @brief Version of stackArray.c that replaces the the test is
 * empty function with a function that returns the count.
 * 
 * @version 0.1
 * @date 2024-12-28
 * 
 * @copyright Copyright (c) 2024
 * 
 */

 #include <stdlib.h>
 #include "Item.h"
 #include "stack_v2.h"
 
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
 
 
 void STACKinit(size_t capacity) {
     s = malloc(capacity * sizeof(typeof(*s)));
     N = 0;
 }
 
 size_t STACKcount(void) {
     return N;
 }
 
 void STACKpush(Item i) {
     s[N++] = i;
 }
 
 Item STACKpop(void) {
     return s[--N];
 }
 
 