/**
 * @file ex4_16.c
 * @author Felix Lempriere
 * @brief Reworks Ex4.16 to use the double stack ADT from Ex4.24. This requires
 * us to wrap Operators and Numbers together in a pair which we use the Item
 * interface for.
 *
 * We use the lower stack for numbers and the upper stack for operators.
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
 #include "Item.h"
 #include "doubleStack.h"

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
    if(!STACKinit(len)) {
        return EXIT_FAILURE;
    }

    Token token;
    for (size_t nRead = TOKENfromStr(expr, &token); expr && nRead;
        expr += nRead, nRead = TOKENfromStr(expr, &token)) {

        if (token.type == TOKEN_LEFT_BRACKET) continue;
        else if (token.type == TOKEN_RIGHT_BRACKET) {
            Item opItem;
            if(!STACKupperPop(&opItem)) continue;
            Operator op = opItem.operator;
            Item term2Item;
            Item term1Item;
            if (!STACKlowerPop(&term2Item)) continue;
            Number term2 = term2Item.number;
            Number term1;

            switch(op) {
                case '+':
                    if (!STACKlowerPop(&term1Item)) continue;
                    term1 = term1Item.number;
                    STACKlowerPush(itemFromNumber(term1 + term2));
                    break;
                case '*':
                    if (!STACKlowerPop(&term1Item)) continue;
                    term1 = term1Item.number;
                    STACKlowerPush(itemFromNumber(term1 * term2));
                    break;
                case '-':
                    if (!STACKlowerPop(&term1Item)) continue;
                    term1 = term1Item.number;
                    STACKlowerPush(itemFromNumber(term1 - term2));
                    break;
                case '/':
                    if (!STACKlowerPop(&term1Item)) continue;
                    term1 = term1Item.number;
                    if (NUMBEReq(term2, 0)) {
                        fprintf(stderr, "Error: invalid value encountered in /\n");
                        return EXIT_FAILURE;
                    }
                    STACKlowerPush(itemFromNumber(term1 / term2));
                    break;
                case '~':
                    STACKlowerPush(itemFromNumber(-term2));
                    break;
                case '$':
                    if (term2 < 0) {
                        fprintf(stderr, "Error: invalid value encountered in square root\n");
                        return EXIT_FAILURE;
                    }
                    STACKlowerPush(itemFromNumber(sqrt(term2)));
                    break;
                default:
                    fprintf(stderr, "Error: unknown operator encountered on stack\n");
                    return EXIT_FAILURE;
            }
        }
        else if (token.type == TOKEN_OPERATOR) {
            STACKupperPush(itemFromOperator(token.value.operator));
        }
        else if (token.type == TOKEN_OPERAND) {
            STACKlowerPush(itemFromNumber(token.value.number));
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
    Item result;
    if(!STACKlowerPop(&result)) {
        fprintf(stderr, "Final expression empty\n");
        return EXIT_FAILURE;
    }
    NUMBERshow(result.number);
    printf("\n");
    return EXIT_SUCCESS; 
 }
