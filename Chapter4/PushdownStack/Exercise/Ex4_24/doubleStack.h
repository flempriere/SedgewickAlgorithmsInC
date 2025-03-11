/**
 * @file doubleStack.h
 * @brief Uses the stack_v3.h interface but extends it
 * to support two stacks using the same buffer. The stack
 * capacity is split between the two stacks.
 *
 *We refer to the stack that fills up as the lower stack
 *and the stack that fills down  as the upper stack.
 *
 * 
 * @version 0.1
 * @date 2024-12-26
 * 
 * @copyright Copyright (c) 2024
 * 
 */
 #pragma once

 #include <stdlib.h>
 #include "Item.h"

 /**
  * @brief Maximum capacity of the stacks. This
  * capacity is shared by both stacks.
  * 
  * @param capacity 
  * 
  * @return true on success else
  * @return false.
  *
  */
 bool STACKinit(size_t capacity);
 
 /**
  * @brief Returns the number of elements on the lower
  * stack.
  * 
  * @return size_t number of elements on the stack.
  */
 size_t STACKlowerCount(void);

  /**
  * @brief Returns the number of elements on the upper
  * stack.
  *
  * @return size_t number of elements on the stack.
  */
  size_t STACKupperCount(void);
 
 /**
  * @brief Push an Item i onto the lower stack
  * 
  * @param i item to push onto the stack
  *
  *@return true if successful else
  *@return false.
  */
 bool STACKlowerPush(Item i);

  /**
  * @brief Push an Item i onto the upper stack
  * 
  * @param i item to push onto the stack
  *
  *@return true if successful else
  *@return false.
  */
  bool STACKupperPush(Item i);


 
 /**
  * @brief Returns the Item on top of the lower stack and
  * stores it in dest.
  * 
  * @param dest - Pointer to store popped item in.
  * 
  * @return true if successfully popped, else
  * @return false. 
  */
 bool STACKlowerPop(Item* dest);

 /**
  * @brief Returns the Item on top of the upper stack and
  * stores it in dest.
  * 
  * @param dest - Pointer to store popped item in.
  * 
  * @return true if successfully popped, else
  * @return false. 
  */
  bool STACKupperPop(Item* dest);
 
 /**
  * @brief Indicates an error has taken place
  * 
  * @param msg error message
  */
 void STACKerror(char* msg); 