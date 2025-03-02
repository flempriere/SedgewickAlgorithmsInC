/**
 * @file Item.h
 * @author Felix Lempriere
 * 
 * @brief Item.h interface that can be used with the stack.h to support
 * operands and operators on the stack without the need
 * to assume that all types are characters.
 * 
 * @version 0.1
 * @date 2024-12-27
 * 
 * @copyright Copyright (c) 2024
 * 
 */
#pragma once

#include <stdio.h>
#include <ctype.h>
#include <string.h>

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
    char* val;
    size_t len;
};

/**
 * @brief Determine if two items are equal
 * 
 * @return @true if equal, else
 * @return @false
 */
static inline bool ITEMeq(Item A,Item B) {
    return (A.symType == B.symType && (!strcmp(A.val, B.val)));
}


/**
 * @brief print the value of an ITEM
 * 
 */
#define ITEMshow(A) printf("%s", A.val)

/**
 * @brief Extracts an Item from the string pointed
 * to by src, and stores it in the Item pointed to
 * by dest and return the number of characters read.
 * 
 * In the case that a complete value could not be read
 * zero is returned.
 * 
 * @param src string to extract the item from, to extract
 * the next token in a previous token, pass a nullptr.
 * 
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

    char* delim = " ";
    char* next_token = strtok(src, delim);

    if ((*next_token == '+' || *next_token == '*') && !*(next_token + 1)) {
        dest->symType = SYM_OPERATOR;
        dest->val = next_token;
        dest->len = 1;
    }
    else {
        dest->symType = SYM_OPERAND;
        dest->val = next_token;
        dest->len = strlen(dest->val);
    }
    return dest->len;
}