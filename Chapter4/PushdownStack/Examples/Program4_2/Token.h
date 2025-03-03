/**
 * @file Token.h
 * @author Felix Lempriere
 * @brief This Item is used to represent a token in a mathematical
 * postfix expression.
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
#include "Item.h"

 /**
  * @brief enum to classify a token as either an operator or an
  * operand.
  */
 typedef enum e_TokenType {TOKEN_OPERATOR, TOKEN_OPERAND} e_TokenType;

 /**
  * @brief Union type to store either an operator symbol or
  * a numeric value.
  */
 typedef union TokenValue {
    char operator;
    Item number;
 } TokenValue;

 /**
  * @brief struct type to store a token.
  * A token contains a enum indicating if the token is an operator or
  * operand and then a union containing the value.
  */
 typedef struct Token  {
    e_TokenType type;
    TokenValue value;
 } Token;

 /**
  * @brief Compare two Items for equality
  * 
  * @param A first Item
  * @param B second Item
  * @return true if equal else
  * @return false 
  */
 static inline bool TOKENeq(Token A, Token B) {
    if (A.type == B.type) {
        switch(A.type) {
            case TOKEN_OPERATOR:
                return (A.value.operator == B.value.operator);
            case TOKEN_OPERAND:
                return (A.value.number == B.value.number);
        }   
    }
    return false;
 }

 /**
  * @brief Extracts an Item from a string
  * 
  * @param src string to extract item from.
  * @param dest pointer to Item to store extracted item.
  * @return size_t number of chars read on success else
  * @return 0.
  */
 static inline size_t TOKENfromStr(char* src, Token* dest) {

    char* cur = src;
    while (isblank(*cur)) cur++; //move over blanks
    if (!cur) return 0; //purely blank string

    if (*cur == '+' || *cur == '*') { //extract operator
        dest->type = TOKEN_OPERATOR;
        dest->value.operator = *cur++;
        return (size_t) (cur - src);
    }
    else if (isdigit(*cur)) {
        dest->type = TOKEN_OPERAND;
        size_t num_len = ITEMfromStr(cur, &(dest->value.number));
        return (size_t) (cur - src) + num_len;
    }
    else {
        return 0;
    }
 }

