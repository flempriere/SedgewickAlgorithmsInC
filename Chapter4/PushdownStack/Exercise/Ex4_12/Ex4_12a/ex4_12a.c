/**
 * @file ex4_12a.c
 * @author Felix Lempriere
 * @brief Pushdown stack client reads any postfix expression
 * limited to multiplication or addition of integers, then
 * evaluates the expression and prints the computed result.
 * 
 * When we encounter operands, we push them on the stack;
 * when we encounter operators we pop the top two entries
 * from the stack and push the result of applying the operator
 * to them.
 * 
 * Extends program 4_11 to support unary negation (~), square root ($) and
 * floating point.
 * 
 * @version 0.1
 * @date 2024-12-27
 * 
 * @copyright Copyright (c) 2024
 * 
 * @remark We handle unary negation by introducing the a new symbol
 * ~ to represent negation.
 */

#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <tgmath.h>
#include "Item.h"
#include "stack.h"

/**
 * @brief A simple calculator to compute command line
 * expressions written in postfix with integers and the
 * + and * operators.
 * 
 * @param argv[1] a postfix expression to evaluate with
 * all operands and operators seperated by at least one
 * blank.
 * 
 * @return EXIT_SUCCESS on successful completion, else
 * @return EXIT_FAILURE 
 */
int main(int argc, char* argv[argc]) {
    
    if (!(argc == 2)) {
        fprintf(stderr, "Error: Usage, %s expression\n", argv[0]);
        return EXIT_FAILURE;
    }
    char* expr = argv[1];
    size_t len = strlen(expr);

    STACKinit(len);
    for (size_t i = 0; i < len; i++) {
        while (i < len && isblank(expr[i])) i++;
        if (expr[i] == '+') {
            STACKpush(STACKpop() + STACKpop());
        }
        else if (expr[i] == '*') {
            STACKpush(STACKpop() * STACKpop());
        }
        else if (expr[i] == '-') {
            Item operand2 = STACKpop();
            STACKpush(STACKpop() - operand2);
        }
        else if (expr[i] == '/') {
            Item operand2 = STACKpop();
            if (eq(operand2, 0)) {
                fprintf(stderr, "Error: invalid value encountered in divide\n");
                return EXIT_FAILURE;
            }
            STACKpush(STACKpop() / operand2);
        }

        else if (expr[i] == '~') {
            STACKpush(-STACKpop());
        }
        else if (expr[i] == '$') {
            STACKpush(sqrt(STACKpop()));
        }
        else if (isdigit(expr[i])) {
            Item val;
            size_t n_read = ITEMfromStr(&expr[i], &val);
            if (n_read) STACKpush(val);
            i += (n_read);
        }
        else {
            fprintf(stderr, "Invalid symbol: %c encountered in stream\n"
                , expr[i]);
            return EXIT_FAILURE;
        }
    }
    ITEMshow(STACKpop());
    printf("\n");
    
    return EXIT_SUCCESS;
}
