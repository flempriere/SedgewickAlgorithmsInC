/**
 * @file Queue_v2.h
 * @author Felix Lempriere
 * @brief Queue interface including a STACKerror function and
 * updating functions that can error appropriately.
 *
 * Realistically QUEUEError does not need to be part of the 
 * interface since its only used internally, but it's here for
 * illustrative purposes to highlight that its part of the QUEUE.
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
  * @brief Initialises the Queue with room for size Items.
  * 
  * @param size Maximum number of Items that can be stored in the Queue.
  *
  * @return true if Queue successfully initalised else
  * @return false.
  */
 bool QUEUEinit(size_t size);


 /**
  * @brief Indicates if the Queue is empty.
  * 
  * @return true if the queue is empty else
  * @return false 
  */
 bool QUEUEempty(void);

/**
 * @brief Places the item i on the Queue.
 * 
 * @param i 
 *
 * @return true if i is successfully placed on the QUEUE else
 * @return false.
 */
 bool QUEUEput(Item i);

/**
 * @brief Gets an Item from the Queue and stores it in *dest.
 * 
 * @param dest Pointer to store the removed item.
 *
 * @return true if item successfully removed, else
 * @return false.
 */
 bool QUEUEget(Item* dest);

/**
 * @brief Indicates an error has taken place
 * 
 * @param msg error message.
 */
 void QUEUEerror(char* msg);