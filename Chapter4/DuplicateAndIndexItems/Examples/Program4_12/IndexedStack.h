/**
 * @file IndexedStack.h
 * @author Felix Lempriere
 * @brief Interface for a stack that contains elements indexed
 * from 0 to maxN - 1.
 * @version 0.1
 * @date 2025-03-14
 * 
 * @copyright Copyright (c) 2025
 * 
 */
 #include <stddef.h>

/**
 * @brief Initialises a stack for items with largest index capacity-1.
 * 
 * @param capacity Maximum number of items on the stack.
 */
 void STACKinit(size_t capacity);

/**
 * @brief Indicates if the stack is empty or not
 * 
 * @return true if the stack is empty else
 * @return false 
 */
 bool STACKempty(void);

/**
 * @brief Pushes an item onto the stack.
 * 
 * @param item item to put on the stack.
 */
 void STACKpush(size_t item);

/**
 * @brief Pop and return the item ontop of the stack. 
 * 
 * @return size_t Item ontop of the stack.
 */
 size_t STACKpop(void);