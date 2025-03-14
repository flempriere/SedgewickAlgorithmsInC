/**
 * @file IndexedQueue.h
 * @author Felix Lempriere
 * @brief Modified version of Queue_v2 for an underying Index set from 0 to
 * maxN - 1.
 * @version 0.1
 * @date 2025-03-14
 * 
 * @copyright Copyright (c) 2025
 * 
 */

 #pragma once
 
 #include <stddef.h>
 #include "../../../AbstractObjects/Examples/intItem/Item.h"

 /**
  * @brief Initialises the IndexedQueue with room for indices 0 to size-1.
  * 
  * @param size Maximum number of Items that can be stored in the Queue.
  *
  * @return true if successfully initialised, else
  * @return false.
  */
bool INDEXEDQUEUEinit(size_t size);


 /**
  * @brief Indicates if the IndexedQueue is empty.
  * 
  * @return true if the queue is empty else
  * @return false 
  */
 bool INDEXEDQUEUEempty(void);

/**
 * @brief Places the index i on the Queue.
 * 
 * @param i idx to add to the queue
 *
 * @return true if successful else
 * @return false.
 */
 bool INDEXEDQUEUEput(size_t i);

/**
 * @brief Gets an index from the Queue. Items are removed
 * in a FIFO manner, i.e. if x, y are in the Queue, and x was
 * inserted before x, then it must be removed before y.
 * 
 * @return size_t the oldest idx on the Queue if successful else
 * @return SIZE_MAX.
 */
 size_t INDEXEDQUEUEget(void);

/**
 * @brief Prints an error msg on stderr. Should be used by
 * implementations to report error cases.
 * 
 * @param msg 
 */
 void INDEXEDQUEUEerror(char* msg);