/**
 * @file Item.h
 * @brief Sample interface providing an item
 * and corresponding operations. Typedef is used
 * to obscure the underlying type.
 * @version 0.1
 * @date 2024-12-26
 * 
 * @copyright Copyright (c) 2024
 * 
 */
#include <limits.h>
#include <stdlib.h>

/**
 * @brief typedef to obscure underlying datatype
 * 
 */
typedef int Item;

static const Item ITEM_MAX = INT_MAX;

/**
 * @brief Determine if two items are equal
 * 
 * @return @true if equal, else
 * @return @false
 */
#define eq(A, B) ((A) == (B))

/**
 * @brief print the value of an Item
 * 
 */
#define ITEMshow(A) printf("%d", A)

#define ITEMrand() (rand() % ITEM_MAX)

