/**
 * @file Token.h
 * @author Felix Lempriere
 * @brief Tokeniser for Exercise 4.15, works similar to the tokeniser for
 * Program 4.3 and its derivatives.
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
    TOKEN_BINARY_OPERATOR,
    TOKEN_UNARY_OPERATOR,
    TOKEN_TERM
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
 * @brief Check if a char is a binary operator
 * 
 * @param A char to check
 * 
 * @return true if A is a binary operator else
 * @return false.
 */
#define IS_BINARY_OPERATOR(A) ((A) == '+' || (A) == '*' || (A) == '-' || (A) == '/')

/**
 * @brief Check if a char is an unary operator
 * 
 * @param A char to check
 * 
 * @return true if A is a unary operator else
 * @return false.
 */
#define IS_UNARY_OPERATOR(A) ((A) == '$' || (A) == '~')

/**
 * @brief Check if a char is an operator
 * 
 * @param A char to check.
 * 
 * @return true if A is an operator else
 * @return false
 */
#define IS_OPERATOR(A) (IS_UNARY_OPERATOR(A) || IS_BINARY_OPERATOR(A))

/**
 * @brief Checks if a char is valid as a starting symbol
 * for a positive numerical Item.
 * 
 * @param A char to check
 * 
 * @return true if symbol could be the start of a positive numerical item else
 * @return false
 */
#define IS_POSITIVE_NUM_START(A) (isdigit(A) || ((A) == '.'))


/**
 * @brief Extract an operand from the string src and store it in the
 * Token pointed to by dest.
 * 
 * @param src string to parse
 * @param dest Token*, token to store the result in.
 * @return size_t number of chars read.
 */
static inline size_t TOKENextractOperand(char* src, Token* dest) {
    char* end = src; 
    strtod(src, &end);
    size_t len  = (size_t) (end - src);

    memcpy(dest->token, src, len);
    dest->token[len] = '\0';
    dest->type = TOKEN_TERM;

    return len;
}

/**
 * @brief Extract a token from the string src and store it
 * in the token pointed to by dest. The user is responsible
 * for ensuring dest is large enough to store the extracted
 * token.
 * 
 * 
 * @param src string to extract token from
 * @param dest pointer to token to store extracted token in.
 * @return size_t number of bytes read on sucess, returns 0
 * if an error occurs.
 */
static inline size_t TOKENfromStr(char* src, Token* dest) {

    char* cur = src;
    while(isblank(*cur)) cur++;
    if (!cur) return 0; //entirely blank string

    if (IS_OPERATOR(*cur)) {
        if (IS_BINARY_OPERATOR(*cur)) {
            dest->type = TOKEN_BINARY_OPERATOR;
        }
        else if (IS_UNARY_OPERATOR(*cur)) {
            //is a negative number
            if (*cur == '-' && IS_POSITIVE_NUM_START(*(cur+1))) {
                cur += TOKENextractOperand(cur, dest);
                return (size_t) (cur - src);
            }
            dest->type = TOKEN_UNARY_OPERATOR;
            if (*cur == '~') *cur = '-'; //restore unary negation to - symbol
        }
        else {
            fprintf(stderr, "Error: invalid operator %c encountered\n", *cur);
            return EXIT_FAILURE;
        }
        strcpy(dest->token, ((char [2]) {*cur, '\0'}));
        cur++;
        return (size_t) (cur - src); 
    }
    else if (IS_POSITIVE_NUM_START(*cur)) {
        cur += TOKENextractOperand(cur, dest);
        return (size_t) (cur - src);
    }
    else {
        return 0;
    }
}

