/**
 * @file ex4_11a.c
 * 
 * @brief Extends Program 4.2 to support subtraction and divide.
 * 
 * @version 0.1
 * @date 2025-03-02
 * 
 * @copyright Copyright (c) 2025
 * 
 */

 #include <stdio.h>
 #include "Item.h"
 #include "Token.h"
 #include "stack.h"
 #include <string.h>

 /**
  * @brief Postfix expression evaluator that supports positive integers,
  * +, -, *, /.
  * 
  * @param argc Number of arguments.
  * @param argv[1] expression to evaluate. 
  * @return EXIT_SUCCESS else
  * @return EXIT_FAILURE 
  */
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
            if (operator == '+') {
                STACKpush(STACKpop() + STACKpop());
            }
            else if (operator == '*') {
                STACKpush(STACKpop() * STACKpop());
            }
            else if (operator == '/') {
                Item term2 = STACKpop();
                if (ITEMeq(term2, 0)) {
                    fprintf(stderr, "Error: invalid value encountered in divide\n");
                    return EXIT_FAILURE;
                }
                STACKpush(STACKpop() / term2);
            }
            else if (operator == '-') {
                Item term2 = STACKpop();
                Item term1 = STACKpop();
                if (term2 > term1) {
                    fprintf(stderr, "Error: operation results in a negative integer\n");
                    return EXIT_FAILURE;
                }
                STACKpush(term1 - term2); 
            }
            else {
                fprintf(stderr, "Error: Unknown operator %c encountered\n", operator);
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