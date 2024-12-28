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
 * Updated from the version in Ex4_11b to support negation
 * and the square root operator.
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

typedef union Repr Repr;

struct Symbol {
    e_symbolType symType;
    bool symOrNum;
    Repr val;
};

#define SYM true
#define NUM false

union Repr {
    int symbol;
    double number;
};

/**
 * @brief Determine if two items are equal
 * 
 * @return @true if equal, else
 * @return @false
 */
static inline bool ITEMeq(Item A, Item B) {
    if (A.symType != B.symType) return false;
    if (A.symOrNum == SYM) {
        return A.val.symbol == B.val.symbol;
    }
    else {
        return NUMeq(A.val.number, B.val.number);
    }
}

/**
 * @brief print the value of an ITEM
 * 
 */
#define ITEMshow(A) do {                                            \
    if (A.symOrNum == SYM) {printf("%c", A.val.symbol);}     \
    else NUMshow(A.val.number);                                     \
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
 * underlying floating point type represented in decimal.
 */
static inline size_t ITEMfromStr(char* src, Item* dest) {
    char* cur;
    Item new;
    //operator
    if (*cur == '+' || *cur == '*' || *cur == '-' || *cur == '/') {
        new.symType = SYM_OPERATOR;
        new.symOrNum = SYM;
        //interpret - not followed by a blank as a negation
        if (*cur == '-' && (*(cur+1) && !isblank(*(cur+1)))) {
            new.val.symbol = '!';
            cur++;
        }
        else {
            new.val.symbol = *cur++;
        }
    }
    //any variable must be a single letter
    else if (isalpha(*cur)) {
        if (*(cur+1) || isblank(*(cur+1)) || *(cur+1) == '\n') {
            new.symType = SYM_OPERAND;
            new.symOrNum = SYM;
            new.val.symbol = *cur++;
        }
    }
    //extract number
    else if (isnum(*cur)) {
        Number val;
        size_t n_read = NUMfromStr(cur, &val);
        if (n_read) {
            cur += n_read;
            new.symType = SYM_OPERAND;
            new.symOrNum = NUM;
            new.val.number = val;
        }
    }
    size_t n_read = (size_t) (cur - src);
    if (n_read) {
        dest->symType = new.symType;
        dest->symOrNum = NUM;
        dest->val = new.val;
    }
    return n_read;
}