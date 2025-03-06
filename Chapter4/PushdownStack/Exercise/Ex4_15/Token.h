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
#define TOKENeq(A, B) (A.type == B.type && ITEMeq(A.token, B.token))

/**
 * @brief Prints out a token
 * 
 * @param A token to print
 * 
 */
#define TOKENshow(A) ITEMshow(A.token)

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
    else if (isdigit(*cur) || (*cur == '.')) {

        //calculate length of number
        char* end;
        strtod(cur, &end);
        size_t len = (size_t) (end - cur);
        memcpy(dest->token, cur, len);
        dest->token[len] = '\0';
        dest->type = TOKEN_TERM;
        return (size_t) (end - src);
    }
    else {
        return 0;
    }
}

