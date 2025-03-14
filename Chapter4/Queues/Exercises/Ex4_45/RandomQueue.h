/**
 * @file RandomQueue.h
 * @author Felix Lempriere
 * @brief Interface for a Random Queue with Item.h swapped out to the Item.h
 * for a playing card.
 * @version 0.1
 * @date 2025-03-11
 * 
 * @copyright Copyright (c) 2025
 * 
 */
 #pragma once

 #include <stddef.h>
 #include "Item.h"

 /**
  * @brief Initialises the RandomQueue with room for size Items.
  * 
  * @param size Maximum number of Items that can be stored in the RandomQueue.
  *
  * @return true if RandomQueue successfully initalised else
  * @return false.
  */
 bool RANDOMQUEUEinit(size_t size);


 /**
  * @brief Indicates if the RandomQueue is empty.
  * 
  * @return true if the RandomQueue is empty else
  * @return false 
  */
 bool RANDOMQUEUEempty(void);

/**
 * @brief Places the item i on the RandomQueue.
 * 
 * @param i 
 *
 * @return true if i is successfully placed on the RandomQueue else
 * @return false.
 */
 bool RANDOMQUEUEput(Item i);

/**
 * @brief Gets an Item from the RandomQueue and stores it in *dest.
 *
 *The returned Item is chosen at uniformly at random from the elements on
 * the random queue.
 * 
 * @param dest Pointer to store the removed item.
 *
 * @return true if item successfully removed, else
 * @return false.
 */
 bool RANDOMQUEUEget(Item* dest);

/**
 * @brief Indicates an error has taken place
 * 
 * @param msg error message.
 */
 void RANDOMQUEUEerror(char* msg);