/**
 * @file ex4_16.c
 * @author Felix Lempriere
 * @brief Combines Program 4.2 and Program 4.2 into the one program utilising
 * two stacks (one of operands and the other of operators).
 * 
 * 
 * @version 0.1
 * @date 2025-03-06
 * 
 * @copyright Copyright (c) 2025
 * 
 */

 #include <stdio.h>
 #include <stdlib.h>
 #include <tgmath.h>

 #include "Token.h"
 #include "Number.h"
 #include "Operator.h"
 #include "stack.h"

 /**
  * @brief Combines Programs 4.2 and Programs 4.3 into a program that can
  * process and evaluate fully brackets infix expressions.
  * 
  * @param argc 
  * @param argv 
  * @return int 
  */
 int main(int argc, char* argv[argc]) {
    if (!(argc == 2)) {
        fprintf(stderr, "Error: Usage %s \"expr\"\n", argv[0]);
        return EXIT_FAILURE;
    }

    char* expr = argv[1];
    size_t len = strlen(expr);
    STACKoperandStackInit(len);
    STACKoperatorStackInit(len);

    Token token;
    for (size_t nRead = TOKENfromStr(expr, &token); expr && nRead;
        expr += nRead, nRead = TOKENfromStr(expr, &token)) {

        if (token.type == TOKEN_LEFT_BRACKET) continue;
        else if (token.type == TOKEN_RIGHT_BRACKET) {
            Operator op = STACKoperatorStackPop();
            Number term2;
            switch(op) {
                case '+':
                    STACKoperandStackPush(STACKoperandStackPop() + STACKoperandStackPop());
                    break;
                case '*':
                    STACKoperandStackPush(STACKoperandStackPop() * STACKoperandStackPop());
                    break;
                case '-':
                    term2 = STACKoperandStackPop();
                    STACKoperandStackPush(STACKoperandStackPop() - term2);
                    break;
                case '/':
                    term2 = STACKoperandStackPop();
                    if (NUMBEReq(term2, 0)) {
                        fprintf(stderr, "Error: invalid value encountered in /\n");
                        return EXIT_FAILURE;
                    }
                    STACKoperandStackPush(STACKoperandStackPop() / term2);
                    break;
                case '~':
                    STACKoperandStackPush(-STACKoperandStackPop());
                    break;
                case '$':
                    Number term = STACKoperandStackPop();
                    if (term < 0) {
                        fprintf(stderr, "Error: invalid value encountered in square root\n");
                        return EXIT_FAILURE;
                    }
                    STACKoperandStackPush(sqrt(term));
                    break;
                default:
                    fprintf(stderr, "Error: unknown operator encountered on stack\n");
                    return EXIT_FAILURE;
            }
        }
        else if (token.type == TOKEN_OPERATOR) {
            STACKoperatorStackPush(token.value.operator);
        }
        else if (token.type == TOKEN_OPERAND) {
            STACKoperandStackPush(token.value.number);
        }
        else {
            fprintf(stderr, "Error: invalid token encountered in stream\n");
            return EXIT_FAILURE;
        }
    }
    if (expr && *expr != '\0') {
        //Non-null expr implies we failed a parse
        fprintf(stderr, "Error: invalid character %c encounted in stream\n", *expr);
        return EXIT_FAILURE;
    }
    NUMBERshow(STACKoperandStackPop());
    printf("\n");
    return EXIT_SUCCESS; 
 }