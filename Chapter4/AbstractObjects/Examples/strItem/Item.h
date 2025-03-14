/**
 * @file Item.h
 * @brief Sample interface providing an item
 * and corresponding operations. Typedef is used
 * to obscure the underlying type.
 * @version 0.1
 * @date 2024-12-25
 * 
 * @copyright Copyright (c) 2024
 * 
 */
#include <string.h>

/**
 * @brief Obscures underlying datatype
 * 
 */
typedef char* Item;

/**
 * @brief Test if two items are equal
 * 
 * @return @true if equal, else
 * @return @false
 */
#define ITEMeq(A, B) (strcmp(A,B) == 0)