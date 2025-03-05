/**
 * @file postfix_eval.c
 * 
 * @brief This pushdown stack client reads any postfix expression involving
 * multiplication and addition of integers, then evaluates the expression and
 * prints the computed result.
 * 
 * When we encounter operands, we push them on the stack; when we encounter
 * operators we pop the top two entries from the stack and push the result
 * of applying the operator to them. The order in which the two STACKpop()
 * operations are performed in the expression is unspecified.
 * 
 * @version 0.1
 * @date 2025-03-02
 * 
 * @copyright Copyright (c) 2025
 * 
 */

 #include <stdio.h>
 #include <string.h>
 #include "Item.h"
 #include "Token.h"
 #include "stack.h"

 int main(int argc, char* argv[argc]) {

    if (!(argc == 2)) {
        fprintf(stderr, "Error: Usage %s \"expr\"\n", argv[0]);
        return EXIT_FAILURE;
    }
    char* expr = argv[1];
    STACKinit(strlen(expr));

    Token token;
    for (size_t nRead = TOKENfromStr(expr, &token); expr && nRead; 
        expr += nRead, nRead = TOKENfromStr(expr, &token)) {

        if (token.type == TOKEN_OPERATOR) {
            char operator = token.value.operator;
            if (operator == '+') STACKpush(STACKpop() + STACKpop());
            else if (operator == '*') STACKpush(STACKpop() * STACKpop());
            else {
                fprintf(stderr, "Error: invalid operator %c encountered\n", operator);
                return EXIT_FAILURE;
            }

        }
        else if (token.type == TOKEN_OPERAND) {
            STACKpush(token.value.number);
        }
        else {
            fprintf(stderr, "Error: invalid token type encountered\n");
            return EXIT_FAILURE;
        }
    }
    if (expr && *expr != '\0') {
        //Non-null expr implies we failed a parse
        fprintf(stderr, "Error: invalid token %c encounted in stream\n", *expr);
        return EXIT_FAILURE;
    }
    ITEMshow(STACKpop()); //last value is the result
    printf("\n");
    return EXIT_SUCCESS;
 }