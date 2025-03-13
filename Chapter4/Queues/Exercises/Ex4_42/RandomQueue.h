/**
 * @file RandomQueue.h
 * @author Felix Lempriere
 * @brief Interface for a Random Queue. Follows a similar mechanism
 * to the Queue_v2.h interface including error standards. 
 *
 * Random Queue functions as a Queue but with the property that the get
 * function will randomly return an element on the queue. The element to return
 * is chosen uniformly from all the elements on the Queue.
 * 
 * @version 0.1
 * @date 2025-03-11
 * 
 * @copyright Copyright (c) 2025
 * 
 */
 #pragma once

 #include <stddef.h>
 #include "../../../AbstractObjects/Examples/intItem/Item.h"

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