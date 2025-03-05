/**
 * @file infix2postfix.c
 * 
 * @brief This program uses a pushdown stack client to convert infix to postfix.
 * 
 * In this casee, the stack contains characters --- we assume that Item is
 * defined to support char*, to convert (A+B) to the postfix form AB+, we ignore
 * the left parenthesis, convert A to postfix, save the + on the stack, convert
 * B to postfix, then, on encountering the right parenthesis, pop the stack
 * and output the +.
 * 
 * @version 0.1
 * @date 2025-03-03
 * 
 * @copyright Copyright (c) 2025
 * 
 */

#include <stdio.h>
#include <string.h>
#include "Token.h"
#include "Item.h"
#include "stack.h"

int main(int argc, char* argv[argc]) {

    if (!(argc == 2)) {
        fprintf(stderr, "Error: Usage %s \"expr\"\n", argv[0]);
        return EXIT_FAILURE;
    }

    char* expr = argv[1];
    size_t len = strlen(expr);
    STACKinit(len);

    Token token;
    token.token = malloc((len+1)*sizeof(typeof(*(token.token))));

    for (size_t nRead = TOKENfromStr(expr, &token); expr && nRead;
        expr += nRead, nRead = TOKENfromStr(expr, &token)) {

        if (token.type == TOKEN_LEFT_BRACKET) continue;
        else if (token.type == TOKEN_RIGHT_BRACKET) {
            Item element = STACKpop();
            ITEMshow(element);
            printf(" ");
            free(element);
        }
        else if (token.type == TOKEN_OPERATOR) {
            Item tok = malloc((strlen(token.token) + 1)*sizeof(typeof(*(token.token))));
            strcpy(tok, token.token);
            STACKpush(tok);
        }
        else if (token.type == TOKEN_OPERAND) {
            TOKENshow(token);
            printf(" ");
        }
        else {
            fprintf(stderr, "Error: Unknown token identified\n");
            return EXIT_FAILURE;
        }
    }
    if (expr && *expr != '\0') {
        //Non-null expr implies we failed a parse
        fprintf(stderr, "Error: invalid token %c encounted in stream\n", *expr);
        return EXIT_FAILURE;
    }
    printf("\n");
    return EXIT_SUCCESS;
}