/**
 * @file Token.h
 * @author Felix Lempriere
 * @brief Extends the Token.h implementation of Exercise 4.11 to support
 * negation and square root. Unary negation is converted to ~.
 * 
 * @version 0.1
 * @date 2025-03-03
 * 
 * @copyright Copyright (c) 2025
 * 
 */
#pragma once

#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>
#include "Item.h"


 /**
  * @brief enum to classify a token as either an operator or an
  * operand.
  * 
  * Similar to the enum used in Program 4.2 but we extend to support brackets
  */
typedef enum e_TokenType {
    TOKEN_OPERATOR,
    TOKEN_OPERAND,
    TOKEN_LEFT_BRACKET,
    TOKEN_RIGHT_BRACKET
} e_TokenType;

 /**
  * @brief struct type to store a token.
  * A token contains a enum indicating if the token is an operator or
  * operand and then a string containing the value;
  */
typedef struct Token {
    e_TokenType type;
    Item token;
} Token;

/**
 * @brief Determine if two tokens are equal
 * 
 * @param A first token
 * @param B second token
 * @return true if equal else
 * @return false 
 */
#define TOKENeq(A, B) (((A).type == (B).type) && ITEMeq((A).token, (B).token))

/**
 * @brief Prints out a token
 * 
 * @param A token to print
 * 
 */
#define TOKENshow(A) ITEMshow((A).token)

/**
 * @brief Checks if a char is an operator
 * 
 * @param A char to check.
 * 
 * @return true if symbol is an operator else
 * @return false.
 */
#define IS_OPERATOR(A) ((A) == '+' || (A) == '*' || (A) == '-' || (A) == '/'    \
    || (A) == '$')                                                              \

/**
 * @brief Checks if a char is a bracket
 * 
 * @param A char to check.
 * 
 * @return true if symbol is a bracket else
 * @return false.
 */
#define IS_BRACKET(A) ((A) == '(' || (A) == ')')

/**
 * @brief Checks if a char is valid as a starting symbol
 * for a positive numerical Item.
 * 
 * @param A char to check.
 * 
 * @return true if symbol could be the start of a positive numerical item else
 * @return false
 */
#define IS_POSITIVE_NUM_START(A) (isdigit(A) || ((A) == '.'))

 /**
  * @brief Extracts an Item from a string
  * 
  * @param src string to extract item from.
  * @param dest pointer to Item to store extracted item.
  * @return size_t number of chars read on success else
  * @return 0.
  */
static inline size_t TOKENfromStr(char* src, Token* dest) {

    static e_TokenType prev_token = TOKEN_LEFT_BRACKET;

    char* cur = src;
    while(isblank(*cur)) cur++;
    if (!cur) return 0; //entirely blank string

    if (IS_OPERATOR(*cur) || IS_BRACKET(*cur)) {

        if (IS_OPERATOR(*cur)) {
            if (*cur == '-') {
                //if previous token is not ) or operand, then token is negation
                if (!(prev_token == TOKEN_OPERAND || prev_token == TOKEN_RIGHT_BRACKET)) {
                    *cur = '~'; //change symbol
                }
            }
            dest->type = TOKEN_OPERATOR;
        }
        else if (*cur == '(') {
            dest->type = TOKEN_LEFT_BRACKET;
        }
        else {
            dest->type = TOKEN_RIGHT_BRACKET; //Must be a right bracket
        }
        //extract operator or bracket as string
        strcpy(dest->token, (char [2]) {*cur, '\0'});
        cur++;
        prev_token = dest->type;
        return (size_t) (cur - src); 
    }
    else if (IS_POSITIVE_NUM_START(*cur)) {

        //determine length of number
        char* end;
        strtod(cur, &end);
        size_t len = (size_t) (end - cur);

        memcpy(dest->token, cur, len);
        dest->token[len] = '\0';
        dest->type = TOKEN_OPERAND;

        prev_token = dest->type;
        return (size_t) (end - src);
    }
    else {
        return 0;
    }
}

