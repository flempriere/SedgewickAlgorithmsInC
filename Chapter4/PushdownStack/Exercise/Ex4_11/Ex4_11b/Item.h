/**
 * @file Item.h
 * @author Felix Lempriere
 * 
 * @brief Wraps the Item.h interface for a numeric type
 * (renamed Number.h) in an abstract Item.h interface
 * that can be used with the stack.h to support
 * operands and operators on the stack without the need
 * to assume that all types are characters.
 * 
 * Updated to support '-' and '/' operands.
 * 
 * @version 0.1
 * @date 2024-12-28
 * 
 * @copyright Copyright (c) 2024
 * 
 */
#pragma once

#include <stdio.h>
#include <ctype.h>
#include "Number.h"

/**
 * @brief Symbol can either be an operand like a
 * variable or an operator like + or *.
 * 
 * (Technically they could also be brackets but
 * we don't store these)
 * 
 */
typedef enum {SYM_OPERAND, SYM_OPERATOR} e_symbolType;

/**
 * @brief wrap Symbol struct in Item interface for
 * the stack
 * 
 */
typedef struct Symbol Item;

struct Symbol {
    e_symbolType symType;
    Number val;
};

/**
 * @brief Determine if two items are equal
 * 
 * @return @true if equal, else
 * @return @false
 */
#define eq(A, B) (((A.symType) == (B.symType)) && ((A.val) == (B.val)))


/**
 * @brief print the value of an ITEM
 * 
 */
#define ITEMshow(A) do {                                    \
    if (A.symType == SYM_OPERAND) {printf("%c", A.val);}    \
    else NUMshow(A);                                        \
} while(0)


/**
 * @brief Extracts an Item from the string pointed
 * to by src, and stores it in the Item pointed to
 * by dest and return the number of characters read.
 * 
 * In the case that a complete value could not be read
 * zero is returned.
 * 
 * @param src string to extract the item from
 * @param dest after successful function execution dest
 * stores the extracted value, in the case of an error
 * dest is untouched.
 * 
 * @return size_t indicating number of chars read or 0 in
 * the case of an error.
 * 
 * @remark This specific implementation is written for an
 * underlying integer type represented in decimal.
 */
static inline size_t ITEMfromStr(char* src, Item* dest) {
    char* cur;
    Item new;
    //operator
    if (*cur == '+' || *cur == '*' || *cur == '-' || *cur == '/') {
        new.symType = SYM_OPERATOR;
        new.val = *cur++;
    }
    //any variable must be a single letter
    else if (isalpha(*cur)) {
        if (*(cur+1) || isblank(*(cur+1)) || *(cur+1) == '\n') {
            new.symType = SYM_OPERAND;
            new.val = *cur++;
        }
    }
    //extract number
    else if (isnum(*cur)) {
        Number val;
        size_t n_read = NUMfromStr(cur, val);
        if (n_read) {
            cur += n_read;
            new.symType = SYM_OPERAND;
            new.val = val;
        }
    }
    size_t n_read = (size_t) (cur - src);
    if (n_read) {
        dest->symType = new.symType;
        dest->val = new.val;
    }
    return n_read;
}