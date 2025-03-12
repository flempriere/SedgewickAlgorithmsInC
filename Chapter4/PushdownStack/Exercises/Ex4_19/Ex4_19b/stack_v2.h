/**
 * @file stack.h
 * @brief Modified stack interface to replace STACKempty
 * with STACKcount which returns the number of elements in
 * the stack.
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
 * @brief Maximum capacity of the stack
 * 
 * @param capacity 
 */
void STACKinit(size_t capacity);

/**
 * @brief Returns the number of items on the stack.
 * 
 * @return size_t
 */
size_t STACKcount(void);

/**
 * @brief Push an Item i onto the stack
 * 
 * @param i 
 */
void STACKpush(Item i);

/**
 * @brief Returns the Item on top of the stack
 * 
 * @return Item 
 */
Item STACKpop(void);