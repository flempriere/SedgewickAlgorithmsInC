/**
 * @file NumericToken.h
 * @author Felix Lempriere
 * @brief Wraps our floating point numeric item in a ITEM interface supporting
 * either literal numbers or a variable.
 * 
 * @version 0.1
 * @date 2025-03-10
 * 
 * @copyright Copyright (c) 2025
 * 
 */

 #pragma once
 
 #include <stdio.h>
 #include <ctype.h>
 #include "Number.h"

/**
 * @brief Enum to indicate if a numeric token is a variable or a literal
 * 
 */
 typedef enum e_NumericToken {
    NUMERICTOKEN_LITERAL,
    NUMERICTOKEN_VARIABLE
 } e_NumericToken;

 /**
  * @brief Union type holding the value of a NumericToken
  * 
  */
 typedef union NumericTokenValue {
    char variable;
    Number number;
 } NumericTokenValue;

 /**
  * @brief Struct to wrap a NumericTokenValue union with an enum to indicate
  * the correct field to access.
  * 
  */
 typedef struct NumericToken {
    e_NumericToken type;
    NumericTokenValue value;
 } NumericToken;

 /**
  * @brief Makes a NumericToken from a provided Number.
  * 
  * @param A Number to convert to Token
  * @return NumericToken
  * 
  */
 #define MAKE_TOKEN_FROM_NUMBER(A) (NumericToken) {.type = NUMERICTOKEN_LITERAL,    \
    .value = (NumericTokenValue) {.number = A}}                                     \


  /**
  * @brief Test for equality of two numerictypes.
  * 
  * @param A 
  * @param B 
  * @return true if equal else
  * @return false 
  */
 static inline bool NUMERICTOKENeq(NumericToken A, NumericToken B) {
    if (A.type == B.type) {
        switch (A.type) {
            case NUMERICTOKEN_LITERAL:
                return NUMBEReq(A.value.number, B.value.number);
            case NUMERICTOKEN_VARIABLE:
                return (A.value.variable == B.value.variable);
            default:
                return false; //invalid type encountered
        }
    }
    else {
        return false;
    }
 }

 /**
  * @brief Prints the value of a NumericToken
  * 
  * @param A NumericToken to print.
  */
 static inline void NUMERICTOKENshow(NumericToken A) {
    if (A.type == NUMERICTOKEN_LITERAL) NUMBERshow(A.value.number);
    else if (A.type == NUMERICTOKEN_VARIABLE) printf("%c", A.value.variable);
 }

 /**
 * @brief Extracts an Operator from a string
 * 
 * @param src string to extract the number from
 * @param dest pointer to Number to store extracted number
 * @return size_t number of chars read if successful else
 * @return 0
 */
 static inline size_t NUMERICTOKENfromStr(char* src, NumericToken* dest) {
    char* cur = src;
    while (isblank(*cur)) cur++;

    if (islower(*cur)) {
        dest->type = NUMERICTOKEN_VARIABLE;
        dest->value.variable = *cur++;
        return (size_t) (cur - src);
    }
    else {
        size_t len = NUMBERfromStr(cur, &(dest->value.number));
        if (!len) {
            fprintf(stderr, "Error: invalid character encountered while extracting number\n");
            return 0;
        }
        cur += len;
        return (size_t) (cur - src);
    }
 }