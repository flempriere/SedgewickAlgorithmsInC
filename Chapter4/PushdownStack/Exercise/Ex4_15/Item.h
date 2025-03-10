/**
 * @file Item.h
 * @author Felix Lempriere
 * @brief Item interface for Ex4_15, based on the String Item interface from
 * Chapter 4, Abstract Objects.
 * 
 * We add additional aliases for nessecary string functions.
 * @version 0.1
 * @date 2025-03-06
 * 
 * @copyright Copyright (c) 2025
 * 
 */
#pragma once

#include <string.h>
#include <stdio.h>

/**
 * @brief Obscures the char* type so we can use it with the stack.
 * 
 */
 typedef char* Item;

 /**
 * @brief compare if two Item's are equal
 * 
 * @return true if equal, else
 * @return false
 */
#define ITEMeq(A, B) (strcmp(A, B) == 0)

/**
 * @brief print the value of a strItem
 * 
 * @param A Item to print.
 * 
 */
#define ITEMshow(A) printf("%s", A)
