/**
 * @file Item.h
 * @author Felix Lempriere
 * @brief Item interface for infix to postfix conversion based on the 
 * strItem interface from Abstract Objects
 * @version 0.1
 * @date 2025-03-03
 * 
 * @copyright Copyright (c) 2025
 * 
 */
#pragma once
#include <stdio.h>
#include <string.h>

/**
 * @brief typedef for a stringlike Item
 * 
 */
typedef char* Item;

/**
 * @brief compare if two strItem's are equal
 * 
 * @param A
 * @param B
 * 
 * @return true if equal, else
 * @return false
 */
#define ITEMEq(A, B) (strcmp(A, B) == 0)

/**
 * @brief print the value of a strItem
 * 
 * @param A Item to print.
 * 
 */
#define ITEMshow(A) printf("%s", A)