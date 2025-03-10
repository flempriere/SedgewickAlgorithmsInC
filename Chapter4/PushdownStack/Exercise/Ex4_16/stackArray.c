/**
 * @file stackArray.c
 * @brief Specialised version of the Stack data that supports two stacks, one
 * for operators and a second for Numbers.
 * 
 * @version 0.1
 * @date 2025-03-06
 * 
 * @copyright Copyright (c) 2024
 * 
 */

 #include <stdlib.h>
 #include "Operator.h"
 #include "Number.h"
 #include "stack.h"
 

 /**
  * @brief private array representing the operator stack
  * 
  */
 static Operator* opS;
 
 /**
  * @brief private variable representing the operator stack head
  * 
  */
 static int opN;

  /**
  * @brief private array representing the number stack
  * 
  */
 static Number* numS;
 
 /**
  * @brief private variable representing the number stack head
  * 
  */
 static int numN;
 
 
 void STACKoperatorStackInit(size_t capacity) {
     opS = malloc(capacity * sizeof(typeof(*opS)));
     opN = 0;
 }

 void STACKoperandStackInit(size_t capacity) {
    numS = malloc(capacity * sizeof(typeof(*numS)));
    numN = 0;
}
 
 bool STACKoperatorStackEmpty(void) {
     return (opN == 0);
 }

 bool STACKoperandStackEmpty(void) {
    return (numN == 0);
 }
 
 void STACKoperatorStackPush(Operator i) {
     opS[opN++] = i;
 }

 void STACKoperandStackPush(Number i) {
    numS[numN++] = i;
 }
 
Operator STACKoperatorStackPop(void) {
     return opS[--opN];
 }

 Number STACKoperandStackPop(void) {
    return numS[--numN];
 }