/**
 * @file Item.h
 * @author Felix Lempriere
 * @brief Provides an Item interface similar to Chapter 4.1's
 * examples for a floating point number.
 * @version 0.1
 * @date 2024-12-25
 * 
 * @copyright Copyright (c) 2024
 * 
 */
#pragma once

#include <tgmath.h>
#include <stdlib.h>

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
 inline bool eq(Item A, Item B) {
     Item lgst = (fabs(A) > fabs(B)) ? fabs(A) : fabs(B);
     return (fabs(A - B) / lgst < TOL); 
 }

 /**
  * @brief prints the value of an Item
  * 
  */
 #define ITEMshow(A) printf("%g", A)


/**
 * @brief Extracts an ITEM from the string pointed
 * to by src, and stores it in the Item pointed to
 * by dest and return the number of characters read.
 * 
 * In the case that a complete value could not be read
 * zero is returned.
 * 
 * @param src string to extract the item from
 * @param dest after successful function execution dest
 * stores the extracted value, in the case of an error
 * dest is untouched.
 * 
 * @return size_t indicating number of chars read or 0 in
 * the case of an error.
 * 
 * @remark This specific implementation is written for an
 * underlying integer type represented in decimal.
 */
static inline size_t ITEMfromStr(char* src, Item* dest) {
    char* endptr = src;
    double val = strtod(src, &endptr);
    size_t len =  (size_t)(endptr - src);
    if (len) *dest = val;
    return len;
}


