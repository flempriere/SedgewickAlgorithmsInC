/**
 * @file Operator.h
 * @author Felix Lempriere
 * @brief Interface for an operator based off the Item interface.
 * @version 0.1
 * @date 2025-03-06
 * 
 * @copyright Copyright (c) 2025
 * 
 */
#pragma once

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

/**
 * @brief Check if a char is a binary operator
 * 
 * @return true if A is a binary operator else
 * @return false.
 */
#define IS_BINARY_OPERATOR(A) ((A) == '+' || (A) == '*' || (A) == '-' || (A) == '/')

/**
 * @brief Check if a char is an unary operator
 * 
 * @return true if A is a unary operator else
 * @return false.
 */
#define IS_UNARY_OPERATOR(A) ((A) == '$' || (A) == '~')

/**
 * @brief Check if a char is an operator
 * 
 * @return true if A is an operator else
 * @return false
 */
#define IS_OPERATOR(A) (IS_UNARY_OPERATOR(A) || IS_BINARY_OPERATOR(A))

/**
 * @brief Type representing a mathematical operator
 * 
 */
typedef char Operator;

/**
 * @brief Compare two Operators for equality
 * 
 * @param A 
 * @param B
 * 
 * @return true if equal else
 * @return false
 */
#define OPERATOReq(A,B) ((A) == (B))

/**
 * @brief print the value of an Operator
 * 
 * @param A Operator to print
 * 
 */
#define OPERATORshow(A) (printf("%c", A))

/**
 * @brief Extracts an Operator from a string
 * 
 * @param src string to extract the number from
 * @param dest pointer to Number to store extracted number
 * @return size_t number of chars read if successful else
 * @return 0
 */
static inline size_t OPERATORfromStr(char* src, Operator* dest) {
    char* cur = src;
    while (isblank(*cur)) cur++;

    if (!IS_OPERATOR(*cur)) {
        fprintf(stderr, "Error: invalid operator symbol %c found in stream\n", *cur);
        return 0;
    }
    *dest = *cur++;
    return (size_t) (cur - src);
}
