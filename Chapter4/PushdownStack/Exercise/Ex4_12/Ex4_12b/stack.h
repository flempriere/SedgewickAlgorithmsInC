/**
 * @file stack.h
 * @brief This interface defines the basic operations that
 * define a pushdown stack. We assume that the four declarations
 * here are in a file stack.h (see this one), which is referenced
 * as an include by client programs that use these functions and
 * implementations that define Item, perhaps by including an Item.h
 * file. The argument to STACKInit specifies the maximum number of items
 * expected on the stack.
 * 
 * @version 0.1
 * @date 2024-12-26
 * 
 * @copyright Copyright (c) 2024
 * 
 */
#pragma once

/**
 * @brief Typedef for Item, in a true implementation this would
 * come from an Item.h or similar source.
 * 
 */

#include <stdlib.h>
#include "Item.h"
/**
 * @brief Maximum capacity of the stack
 * 
 * @param capacity 
 */
void STACKinit(size_t capacity);

/**
 * @brief Check if the stack is empty
 * 
 * @return true if empty, else
 * @return false
 */
bool STACKempty();

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