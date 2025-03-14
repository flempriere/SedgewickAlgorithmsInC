/**
 * @file Item.h
 * @brief Sample interface providing an item
 * and corresponding operations. Typedef is used
 * to obscure the underlying type.
 * 
 * Extends the examples in Section 4.1 by providing
 * a function to extract an Item from a string.
 * @version 0.1
 * @date 2024-12-27
 * 
 * @copyright Copyright (c) 2024
 * 
 */
 #pragma once

 #include <limits.h>
 #include <ctype.h>
 #include <stdlib.h>
 #include <stdio.h>

 /**
  * @brief typedef to obscure underlying datatype
  * 
  */
 typedef int Item;
 
 static const Item ITEM_MAX = INT_MAX;
 
 /**
  * @brief Determine if two items are equal
  * 
  * @param A
  * @param B
  * 
  * @return @true if equal, else
  * @return @false
  */
 #define ITEMeq(A, B) ((A) == (B))
 
 /**
  * @brief print the value of an Item
  * 
  * @param A Item to print.
  * 
  */
 #define ITEMshow(A) printf("%d", A)
 
 
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
     char* cur;
     Item val = 0;
     for (cur = src; isdigit(cur); cur++) {
         val = 10*val + (*cur - '0');
     }
     size_t len =  (size_t)(cur - src);
     if (len) *dest = val;
     return len;
 }
 
 
 