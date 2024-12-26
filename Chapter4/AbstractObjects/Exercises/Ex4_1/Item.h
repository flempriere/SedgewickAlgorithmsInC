/**
 * @file Item.h
 * @author Felix Lempriere
 * @brief Provides an Item interface similar to Chapter 4.1's
 * examples for a floating point number.
 * @version 0.1
 * @date 2024-12-25
 * 
 * @copyright Copyright (c) 2024
 * 
 */

#include <tgmath.h>

/**
 * @brief Obscure underlying float representation
 * 
 */
typedef double Item;

/**
 * @brief tolerance for floating point equality
 * 
 */
#define TOL 1e-6

/**
 * @brief Test for equality of two items
 * 
 * @param A 
 * @param B 
 * @return true i equal else
 * @return false 
 */
inline bool eq(Item A, Item B) {
    Item lgst = (fabs(A) > fabs(B)) ? fabs(A) : fabs(B);
    return (fabs(A - B) / lgst < TOL); 
}

