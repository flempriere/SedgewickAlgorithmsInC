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
        Number n2 = STACKoperandStackPop().value.number;
        Number n1 = STACKoperandStackPop().value.number;
        return processBinaryOperator(op, n1, n2);
    }
    else if (IS_UNARY_OPERATOR(op)) {
        Number n = STACKoperandStackPop().value.number;
        return processUnaryOperator(op, n);
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