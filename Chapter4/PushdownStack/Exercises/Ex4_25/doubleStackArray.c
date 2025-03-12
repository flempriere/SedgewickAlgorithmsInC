/**
 * @file doubleStackArray.c
 * @brief Implements the doubleStack header with
 * an underlying array structure.
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
 #include "doubleStack.h"
 
 /**
  * @brief private array representing the stack
  * 
  */
 static Item* s;
 
 /**
  * @brief private variable representing the lower stack head
  * 
  */
 static size_t lN;

 /**
  * @brief private variable representing the upper stack head
  * 
  */
 static size_t uN;

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
     lN = 0;
     uN = capacity;
     CAPACITY = capacity;
     return true;
 }
 
 size_t STACKlowerCount(void) {
     return lN;
 }

 size_t STACKupperCount(void) {
    return CAPACITY - uN;
 }
 
 bool STACKlowerPush(Item i) {
    if (lN >= uN) {
        STACKerror("stack at capacity");
        return false;
    }
     s[lN++] = i;
     return true;
 }

 bool STACKupperPush(Item i) {
    if (lN >= uN) {
        STACKerror("stack at capacity");
        return false;
    }
    s[--uN] = i;
    return true;
 }
 
 bool STACKlowerPop(Item* dest) {
    if (lN) {
        *dest = s[--lN];
        return true;
    }
    STACKerror("lower stack empty");
    return false;
 }

 bool STACKupperPop(Item* dest) {
    if (uN < CAPACITY) {
        *dest = s[uN++];
        return true;
    }
    STACKerror("upper stack empty");
    return false;
 }

 void STACKerror(char* msg) {
    fprintf(stderr, "Error: %s\n", msg);
 }
 
 