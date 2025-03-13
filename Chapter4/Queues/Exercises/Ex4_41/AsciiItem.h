/**
 * @file AsciiItem.h
 * @author Felix Lempriere
 * @brief Item interface for an ascii char
 * @version 0.1
 * @date 2025-03-13
 * 
 * @copyright Copyright (c) 2025
 * 
 */

/**
 * @brief Obscure char
 * 
 */
 typedef char Item;


/**
 * @brief Check equality of two items.
 * 
 */
 #define ITEMeq(A,B) ((A) == (B))

 /**
  * @brief show an item
  * 
  */
  #define ITEMshow(A) printf("%c", A)


