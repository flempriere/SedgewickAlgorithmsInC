/**
 * @file Token.h
 * @author Felix Lempriere
 * @brief This Token is used to represent a token in a mathematical
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
  * @brief Prints out the value of a token
  * 
  * @param A token to print
  */
 static inline void TOKENshow(Token A) {
    switch(A.type) {
        case TOKEN_OPERATOR:
            printf("%c", A.value.operator);
            break;
        case TOKEN_OPERAND:
            ITEMshow(A.value.number);
            break;
    }
 }

 /**
  * @brief Extracts an Operator from a string and stores it in the token
  * 
  * @param src string to extract item from.
  * @param dest pointer to Token to store extracted operator.
  * @return size_t number of chars read on success else
  * @return 0.
  */
 static inline size_t TOKENExtractOperator(char* src, Token* dest) {

    char* cur = src;
    dest->type = TOKEN_OPERATOR;
    dest->value.operator = *cur++;
    return (size_t) (cur - src);
 }

/**
  * @brief Extracts an Item from a string and stores it in the token
  * 
  * @param src string to extract item from.
  * @param dest pointer to Token to store extracted item.
  * @return size_t number of chars read on success else
  * @return 0.
  */
 static inline size_t TOKENExtractItem(char* src, Token* dest) {
    dest->type = TOKEN_OPERAND;
    size_t num_len = ITEMfromStr(src, &(dest->value.number));
    return num_len;
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

    if (*cur == '+' || *cur == '*' || *cur == '/'
        || *cur == '$' || *cur == '~') { //extract operator
        cur += TOKENExtractOperator(cur, dest);
        return (size_t) (cur - src);
    }
    else if (*cur == '-') {
        if (isdigit(*(cur+1)) || *(cur + 1) == '.') {
            size_t num_len = TOKENExtractItem(cur, dest);
            return (size_t) (cur - src) + num_len;
        }
        else {
            cur += TOKENExtractOperator(cur, dest);
            return (size_t) (cur - src);
        }
    }
    else if (isdigit(*cur) || *cur == '.') {
        size_t num_len = TOKENExtractItem(cur, dest);
        return (size_t) (cur - src) + num_len;
    }
    else {
        return 0;
    }
 }

