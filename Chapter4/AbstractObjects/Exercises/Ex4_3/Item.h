/**
 * @file Item.h
 * @author Felix Lempriere
 * @brief Adds a generic macro Itemshow to the generic
 * object type definitions for integers and strings
 * described in the text. Your macro should print the
 * value of the Item on standard input.
 * @version 0.1
 * @date 2024-12-26
 * 
 * @copyright Copyright (c) 2024
 * 
 */
#include <string.h>
#include <stdio.h>

// generic type definition for integers example

/**
 * @brief Obscure underlying type
 * 
 */
typedef int numericItem;

/**
 * @brief Compare if two numericItems are equal
 * 
 * @return true if equal, else
 * @return false
 */
#define numEq(A, B) ((A) == (B))

/**
 * @brief print the value of a numericItem
 * 
 */
#define numItemshow(A) printf("%d", A)

// generic type definition for strings example

/**
 * @brief typedef for a stringlike Item
 * 
 */
typedef char* strItem;

/**
 * @brief compare if two strItem's are equal
 * 
 * @return true if equal, else
 * @return false
 */
#define strEq(A, B) (strcmp(A, B) == 0)

/**
 * @brief print the value of a strItem
 * 
 */
#define strItemshow(A) printf("%s", A)


