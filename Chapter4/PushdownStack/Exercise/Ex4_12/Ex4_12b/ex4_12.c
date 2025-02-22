/**
 * @file ex4_11b.c
 * @author Felix Lempriere
 * @brief This program uses a stack to convert infix
 * expressions to postfix expressions. 
 * 
 * To convert (A + B) to the postfix A B +, we ignore
 * the left parenthesis, convert A to postfix, save the
 * + on the stack convert B to postfix, then, on encountering
 * the right parenthesis, pop the stack and output the +.
 * 
 * This version updates Ex4.11 to support the negation operator
 * and square root as well as doubles.
 * 
 * @version 0.1
 * @date 2024-12-28
 * 
 * @copyright Copyright (c) 2024
 * 
 * @remark Like with the previous program we provide some modifications
 * for usability. 
 * 
 */

#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include "Item.h"
#include "stack.h"

int main(int argc, char* argv[argc]) {
    if (!(argc == 2)) {
        fprintf(stderr, "Error: Usage ./%s expr\n", argv[0]);
        return EXIT_FAILURE;
    }
    char* expr = argv[1];
    size_t len = strlen(expr);
    STACKinit(len);
    for (size_t i = 0; i < len; i++) {
        while (isblank(expr[i])) i++;
        if (expr[i] == ')') {
            ITEMshow(STACKpop());
        }
        else if (expr[i] == '(') {
            continue;
        } 
        else {
            // if not bracket, extract Item
            Item new;
            size_t nR = ITEMfromStr(expr[i], &new);
            if (!nR) {
                fprintf("Error: invalid symbol %c in expression\n", expr[i]);
                return EXIT_FAILURE;
            }
            if (new.symType == SYM_OPERATOR) {
                STACKpush(new);
            }
            else {
                ITEMshow(new);
            }
        }
    }
    printf("\n");
    return EXIT_SUCCESS;
}