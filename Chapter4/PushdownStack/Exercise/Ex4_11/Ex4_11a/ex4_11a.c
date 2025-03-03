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
            if (token.value.operator == '+') {
                STACKpush(STACKpop() + STACKpop());
            }
            else if (token.value.operator == '*') {
                STACKpush(STACKpop() * STACKpop());
            }
            else if (token.value.operator == '/') {
                Item term2 = STACKpop();
                STACKpush(STACKpop() / term2);
            }
            else if (token.value.operator == '-') {
                Item term2 = STACKpop();
                STACKpush(STACKpop() - term2); 
            }
            else {
                fprintf(stderr, "Error: Unknown operator %c encountered\n",
                    token.value.operator);
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