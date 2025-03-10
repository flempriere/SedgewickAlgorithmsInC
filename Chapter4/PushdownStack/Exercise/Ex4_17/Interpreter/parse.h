/**
 * @file parse.h
 * @author Felix Lempriere
 * @brief Contains functions to handle parsing the mathematical expressions
 * for the interpreter.
 * 
 * @version 0.1
 * @date 2025-03-10
 * 
 * @copyright Copyright (c) 2025
 * 
 */

 #pragma once

 #include <stdio.h>
 #include <tgmath.h>

 #include "Token.h"
 #include "Operator.h"
 #include "NumericToken.h"
 #include "Number.h"
 #include "stack.h"

 /**
  * @brief Number of variables supported
  * 
  */
 #define N_VARS 26

 /**
  * @brief Global array to store the value of the variables
  * 
  */
 static Number var_values[N_VARS];

 /**
  * @brief Global array to track if a variable has been assigned to
  * 
  */
 static bool var_assigned[N_VARS];
 #define GET_IDX_FROM_VAR(A) ((A) - 'a')


 bool getNumberfromNumericToken(NumericToken src, Number* dest) {
    if (src.type == NUMERICTOKEN_LITERAL) {
        *dest = src.value.number;
    }
    else if (src.type == NUMERICTOKEN_VARIABLE) {
        size_t idx = GET_IDX_FROM_VAR(src.value.variable);
        if (!var_assigned[idx]) {
            fprintf(stderr, "A value has not been assigned to variable %c\n", src.value.variable);
            return false;
        }
        else {
            *dest = var_values[idx];
        }
    }
    return true;
 }

/**
 * @brief Performs a computation for a given binary operator
 * in the format (n1 op n2) and push the result back onto the stack.
 * 
 * @param op Operator, operator to apply
 * @param n1 Number, first argument for op
 * @param n2 Number, second argument for op
 * @return true if successfully processed else
 * @return false.
 */
bool processBinaryOperator(Operator op, Number n1, Number n2) {
    Number result;
    switch(op) {
        case '+':
            result = n1 + n2;
            break;
        case '*':
            result = n1 * n2;
            break;
        case '-':
            result = n1 - n2;
            break;
        case '/':
            if (NUMBEReq(n2, 0)) {
                fprintf(stderr, "Error: invalid value encountered in divide\n");
                return false;
            }
            result = n1 / n2;
            break;
        default:
            fprintf(stderr, "Error: invalid operator %c encountered\n", op);
            return false;
    }
    STACKoperandStackPush(MAKE_TOKEN_FROM_NUMBER(result));
    return true;
}

/**
 * @brief Performs a computation for a given unary operator
 * and push the result back onto the stack.
 * 
 * @param op Operator, operator to apply
 * @param n Number, argument for op
 * 
 * @return true if successfully processed else
 * @return false.
 */
bool processUnaryOperator(Operator op, Number n) {
    Number result;
    switch(op) {
        case '~':
            result = -n;
            break;
        case '$':
            if (n < 0) {
                fprintf(stderr, "Error: invalid value encounted in sqrt\n");
                return false;
            }
            result = sqrt(n);
            break;
        default:
            fprintf(stderr, "Invalid operator %c encountered\n", op);
            return false;
    }
    STACKoperandStackPush(MAKE_TOKEN_FROM_NUMBER(result));
    return true;
}

/**
 * @brief Process an operator, performing variable lookup if required.
 * (not yet implemented). The result is pushed back to the stack.
 * 
 * @param op Operator to process
 * @return true if successfully processed, else
 * @return false 
 */
bool processOperator(Operator op) {
    if (IS_BINARY_OPERATOR(op)) {
        Number n2, n1;
        if (!getNumberfromNumericToken(STACKoperandStackPop(), &n2)) return false;
        if (!getNumberfromNumericToken(STACKoperandStackPop(), &n1)) return false;
        return processBinaryOperator(op, n1, n2);
    }
    else if (IS_UNARY_OPERATOR(op)) {
        Number n;
        if (!getNumberfromNumericToken(STACKoperandStackPop(), &n)) return false;
        return processUnaryOperator(op, n);
    }
    else if (op == '=') {
        Number n;
        if (!getNumberfromNumericToken(STACKoperandStackPop(), &n)) return false;
        NumericToken tok = STACKoperandStackPop();

        if (tok.type != NUMERICTOKEN_VARIABLE) {
            fprintf(stderr, "Error: must assign to a variable\n");
            return false;
        }
        size_t idx = GET_IDX_FROM_VAR(tok.value.variable);
        var_assigned[idx] = true;
        var_values[idx] = n;
        return true;
    }
    else {
        fprintf(stderr, "Error: invalid operator %c encountered\n", op);
        return false;
    }
}

/**
 * @brief Process a token extracted from an input stream.
 * 
 * @param token 
 * @return true 
 * @return false 
 */
bool processToken(Token token) {
    if (token.type == TOKEN_LEFT_BRACKET) return true;
    else if (token.type == TOKEN_RIGHT_BRACKET) {
        return processOperator(STACKoperatorStackPop());
    }
    else if (token.type == TOKEN_OPERATOR) {
        STACKoperatorStackPush(token.value.operator);
    }
    else if (token.type == TOKEN_OPERAND) {
        STACKoperandStackPush(token.value.number);
    }
    else {
        fprintf(stderr, "Error: invalid token type encountered\n");
        return false;
    }
    return true;
}