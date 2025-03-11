/**
 * @file Item.h
 * @author Felix Lempriere
 * @brief Item interface based on the floating-point Item interface in
 * Exercise 4.1
 * @version 0.1
 * @date 2024-12-25
 * 
 * @copyright Copyright (c) 2024
 * 
 */
 #pragma once

 #include <tgmath.h>
 #include <stdlib.h>
 #include <stdio.h>

 /**
  * @brief Obscure underlying float representation
  * 
  */
 typedef double Item;
 
 /**
  * @brief tolerance for floating point equality
  * 
  */
 #define TOL 1e-6
 
 /**
  * @brief Test for equality of two items
  * 
  * @param A 
  * @param B 
  * @return true if equal else
  * @return false 
  */
 inline bool ITEMeq(Item A, Item B) {
     Item lgst = (fabs(A) > fabs(B)) ? fabs(A) : fabs(B);
     if (lgst == 0) return true; //both values zero.
     return (fabs(A - B) / lgst < TOL); 
 }
 
 /**
 * @brief Prints the number
 * 
 * @param A Item to print
 * 
 */
#define ITEMshow(A) printf("%g", A)

/**
 * @brief Extracts a Number from a string
 * 
 * @param src string to extract the number from
 * @param dest pointer to Number to store extracted number
 * @return size_t number of chars read if successful else
 * @return 0
 */
static inline size_t ITEMfromStr(char* src, Item* dest) {
    char* endptr;
    *dest = strtod(src, &endptr);
    return (size_t) (endptr - src);
}
 