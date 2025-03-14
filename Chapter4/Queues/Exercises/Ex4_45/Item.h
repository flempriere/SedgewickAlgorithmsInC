/**
 * @file Item.h
 * @author Felix Lempriere
 * @brief Provides a generic Item interface wrapping
 * around the Playing Card structure defined in
 * PlayingCard.h
 * @version 0.1
 * @date 2024-12-26
 * 
 * @copyright Copyright (c) 2024
 * 
 */

 #pragma once
 #include "PlayingCard.h"
 
 /**
  * @brief typedef to treat playing card
  * as a generic item
  * 
  */
 typedef PlayingCard Item;
 
 /**
  * @brief Test playing card equality
  * 
  */
 #define ITEMeq(A, B) (PLAYINGCARDeq(A,B))

 #define ITEMshow(A) (PLAYINGCARDshow(A))
 

 