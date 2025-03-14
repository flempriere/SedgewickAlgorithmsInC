/**
 * @file Stack_v3.h
 * @brief Stack_v3.h interface from Exercise 4.20
 * 
 * @version 0.1
 * @date 2024-12-26
 * 
 * @copyright Copyright (c) 2024
 * 
 */
 #pragma once

 #include <stdlib.h>
 #include "../../../AbstractObjects/Examples/intItem/Item.h"
 /**
  * @brief Maximum capacity of the stack
  * 
  * @param capacity
  * 
  * @return true on success else
  * @return false.
  */
 bool STACKinit(size_t capacity);
 
 /**
  * @brief Returns the number of elements on the stack
  * 
  * @return size_t number of elements on the stack.
  */
 size_t STACKcount(void);
 
 /**
  * @brief Push an Item i onto the stack
  * 
  * @param i 
  * @return true if successful else
  * @return false.
  */
 bool STACKpush(Item i);
 
 /**
  * @brief Returns the Item on top of the stack and
  * stores it in dest.
  * 
  * @param dest - Pointer to store popped item in.
  * 
  * @return true if successfully popped, else
  * @return false. 
  */
 bool STACKpop(Item* dest);
 
 /**
  * @brief Indicates an error has taken place
  * 
  * @param msg error message
  */
 void STACKerror(char* msg); 