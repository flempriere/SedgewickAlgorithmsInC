/**
 * @file Number.h
 * @author Felix Lempriere
 * @brief Interface for a number based on the Item.h interface.
 * @version 0.1
 * @date 2025-03-06
 * 
 * @copyright Copyright (c) 2025
 * 
 */
 #pragma once

 #include <stdio.h>
 #include <stdlib.h>
 #include <tgmath.h>
 #include <stdio.h>
 
  /**
   * @brief Obscure underlying float representation
   * 
   */
  typedef double Number;
  
  /**
   * @brief tolerance for floating point equality
   * 
   */
  #define TOL 1e-6
  
  /**
   * @brief Test for equality of two numbers
   * 
   * @param A 
   * @param B 
   * @return true if equal else
   * @return false 
   */
  inline bool NUMBEReq(Number A, Number B) {
      Number lgst = (fabs(A) > fabs(B)) ? fabs(A) : fabs(B);
      if (lgst == 0) return true; //both numbers zero.
      return (fabs(A - B) / lgst < TOL); 
  }
  
  /**
  * @brief Prints the number
  * 
  * @param A Number to print.
  * 
  */
 #define NUMBERshow(A) printf("%g", A)
 
 /**
  * @brief Extracts a Number from a string
  * 
  * @param src string to extract the number from
  * @param dest pointer to Number to store extracted number
  * @return size_t number of chars read if successful else
  * @return 0
  */
 static inline size_t NUMBERfromStr(char* src, Number* dest) {
     char* endptr;
     *dest = strtod(src, &endptr);
     return (size_t) (endptr - src);
 }