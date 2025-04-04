/**
 * @file Deque.h
 * @author Felix Lempriere
 * @brief Interface for a Deque ADT based on the Queue_v2.h interface with
 * error handling.
 *
 * We implement put and get as a single function using a enum type to control
 * which end of the deque is modified.
 *
 * @version 0.1
 * @date 2025-03-13
 * 
 * @copyright Copyright (c) 2025
 * 
 */
 #pragma once

 #include <stddef.h>
 #include "../../../AbstractObjects/Examples/intItem/Item.h"

 typedef enum e_DequeSide {
    DEQUE_eBEGINNING,
    DEQUE_eEND
 } e_DequeSide;


  /**
  * @brief Initialises the Deque with room for size Items.
  * 
  * @param size Maximum number of Items that can be stored in the Deque.
  *
  * @return true if Deque successfully initalised else
  * @return false.
  */
  bool DEQUEinit(size_t size);


  /**
   * @brief Indicates if the Deque is empty.
   * 
   * @return true if the deque is empty else
   * @return false 
   */
  bool DEQUEempty(void);
 
 /**
  * @brief Places the item i on the Deque.
  * 
  * @param i Item to place on the queue.
  * @param side Indicates if the Item is to be placed at the beginning 
  * or end of the Deque.
  *
  * @return true if i is successfully placed on the Deque else
  * @return false.
  */
  bool DEQUEput(Item i, e_DequeSide side);
 
 /**
  * @brief Gets an Item from the Deque and stores it in *dest.
  * 
  * @param dest Pointer to store the removed item.
  * @param side Indicates if the Item is to be removed from the beginning 
  * or end of the Deque.
  *
  * @return true if item successfully removed, else
  * @return false.
  */
  bool DEQUEget(Item* dest, e_DequeSide side);
 
 /**
  * @brief Indicates an error has taken place
  * 
  * @param msg error message.
  */
  void DEQUEerror(char* msg);