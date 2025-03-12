/**
 * @file Queue.h
 * @author Felix Lempriere
 * @brief Basic Queue interface, indentical to that
 * of the original stack interface, except the behaviour on
 * calling get differs to pop.
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
  */
 void QUEUEinit(size_t size);


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
 */
 void QUEUEput(Item i);

/**
 * @brief Gets an Item from the Queue. Items are removed
 * in a FIFO manner, i.e. if x, y are in the Queue, and x was
 * inserted before x, then it must be removed before y.
 * 
 * @return Item the oldest Item on the Queue.
 */
 Item QUEUEget(void);