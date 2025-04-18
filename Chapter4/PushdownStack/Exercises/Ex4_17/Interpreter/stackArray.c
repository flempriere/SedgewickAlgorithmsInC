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
 #include "NumericToken.h"
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
 static size_t opN;

  /**
  * @brief private array representing the numericToken stack
  * 
  */
 static NumericToken* numS;
 
 /**
  * @brief private variable representing the numericToken stack head
  * 
  */
 static size_t numN;
 
 
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

 void STACKoperandStackPush(NumericToken i) {
    numS[numN++] = i;
 }
 
Operator STACKoperatorStackPop(void) {
     return opS[--opN];
 }

 NumericToken STACKoperandStackPop(void) {
    return numS[--numN];
 }

 void STACKoperatorStackClear(void) {
    opN = 0;
 }

 void STACKoperandStackClear(void) {
    numN = 0;
 }