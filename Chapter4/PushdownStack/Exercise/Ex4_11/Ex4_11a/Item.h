/**
 * @file Item.h
 * @brief Provides the familiar Item interface from previous
 * examples but with an additional method to parse from a string.
 * 
 * @version 0.1
 * @date 2025-03-03
 * 
 * @copyright Copyright (c) 2024
 * 
 */
#pragma once

#include <stdlib.h>
#include <stdio.h>

/**
 * @brief typedef to obscure underlying datatype
 * 
 */
typedef long Item;

/**
 * @brief Determine if two items are equal
 * 
 * @param A
 * @param B
 * 
 * @return @true if equal, else
 * @return @false
 */
#define ITEMeq(A, B) ((A) == (B))

/**
 * @brief Prints the number
 * 
 * @param A Item to show
 * 
 */
#define ITEMshow(A) printf("%ld", A)

/**
 * @brief Extracts a Number from a string
 * 
 * @param src string to extract the number from
 * @param dest pointer to Number to store extracted number
 * @return size_t number of chars read if successful else
 * @return 0
 */
static inline size_t ITEMfromStr(char* src, Item* dest) {
    char* endptr;
    *dest = strtol(src, &endptr, 0);
    return (size_t) (endptr - src);
}