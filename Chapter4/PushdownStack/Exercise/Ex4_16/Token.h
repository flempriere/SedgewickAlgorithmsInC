/**
 * @file Token.h
 * @author Felix Lempriere
 * @brief Tokeniser for Exercise 4.16, works similar to existing tokenisers but
 * now stores either Operators or Operands as distinct types through a union.
 * @version 0.1
 * @date 2025-03-06
 * 
 * @copyright Copyright (c) 2025
 * 
 */
#pragma once

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#include "Operator.h"
#include "Number.h"

/**
 * @brief enum classifying a token, a token is either an
 * TOKEN_OPERATOR, for mathematical operators,
 * TOKEN_LEFT_BRACKET, for left brackets
 * TOKEN_RIGHT_BRACKET, for right brackets
 * TOKEN_OPERAND, for operands.
 */
typedef enum e_TokenType {
    TOKEN_OPERATOR,
    TOKEN_LEFT_BRACKET,
    TOKEN_RIGHT_BRACKET,
    TOKEN_OPERAND
} e_TokenType;

#define IS_BRACKET(A) ((A) == TOKEN_LEFT_BRACKET || (A) == TOKEN_RIGHT_BRACKET)

/**
 * @brief Union to the value of a token, either an Operator, char or Number.
 * 
 */
typedef union TokenValue {
    Operator operator;
    char bracket;
    Number number;
} TokenValue;

/**
 * @brief Token structure containing a e_TokenType enumeration value and a
 * TokenValue value.
 * 
 */
typedef struct Token {
    e_TokenType type;
    TokenValue value;
} Token;

/**
 * @brief Determine if two tokens are equal
 * 
 * @param A first token
 * @param B second token
 * @return true if equal else
 * @return false 
 */
static inline bool TOKENeq(Token A, Token B) {
    if (A.type == B.type) {
        if (A.type == TOKEN_OPERATOR) {
            return (OPERATOReq(A.value.operator, B.value.operator));
        }
        else if (A.type == TOKEN_OPERAND) {
            return (NUMBEReq(A.value.number, B.value.number));
        }
        else if (IS_BRACKET(A.type)) {
            return (A.value.bracket == B.value.bracket);
        }
        else return false; //invalid value encountered
    }
    else return false;
}

/**
 * @brief Prints out a token
 * 
 * @param A token to print
 * 
 */
static inline void TOKENshow(Token A) {
    switch(A.type) {
        case TOKEN_OPERATOR:
            OPERATORshow(A.value.operator);
            break;
        case TOKEN_OPERAND:
            NUMBERshow(A.value.number);
            break;
        case TOKEN_LEFT_BRACKET:
        case TOKEN_RIGHT_BRACKET:
            printf("%c", A.value.bracket);
            break;
    }
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

    static e_TokenType prev_token = TOKEN_LEFT_BRACKET;

    char* cur = src;
    while(isblank(*cur)) cur++;
    if (!(*cur)) return 0; //blank string

    if (IS_OPERATOR(*cur)) {

        if (*cur == '-') {
            if (!(prev_token == TOKEN_OPERAND || prev_token == TOKEN_RIGHT_BRACKET)) {
                *cur = '~'; //change symbol
            }
        }
        dest->type = TOKEN_OPERATOR;
        size_t Oplen = OPERATORfromStr(cur, &(dest->value.operator));
        cur += Oplen;
    }
    else if (*cur == '(' || *cur == ')') {
        dest->type = (*cur == '(') ? TOKEN_LEFT_BRACKET : TOKEN_RIGHT_BRACKET;
        dest->value.bracket = *cur++;
    }
    else {
        dest->type = TOKEN_OPERAND;
        size_t OperandLen = NUMBERfromStr(cur, &(dest->value.number));
        if (!OperandLen) {
            fprintf(stderr, "Error: invalid character %c encountered in token stream\n", *cur);
            return 0;
        }
        cur += OperandLen;
    }
    prev_token = dest->type;
    return (size_t) (cur - src);
}