/**
 * @file interpreter.c
 * @author Felix Lempriere
 * @brief Interpretor for a mathematical language consisting of infix variable
 * assignment statements, where a variable is any lowercase character, e.g.
 * (x = 2) is a valid assignment, (X = 2) is not. Followed by regular infix
 * expressions.
 * @version 0.1
 * @date 2025-03-10
 * 
 * @copyright Copyright (c) 2025
 * 
 */

 #include <stdio.h>
 #include <stdlib.h>
 #include <string.h>
 #include <tgmath.h>

 #include "stack.h"
 #include "Token.h"
 #include "parse.h"
 #include "NumericToken.h"

 #define MAX_LINE_SIZE 1000


 int main(int argc, char* argv[argc]) {

    char buf[MAX_LINE_SIZE]; //buffer to read line into
    STACKoperandStackInit(MAX_LINE_SIZE);
    STACKoperatorStackInit(MAX_LINE_SIZE);

    char* expr;
    while((expr = fgets(buf, sizeof(buf), stdin)) != nullptr) {
        expr[strlen(expr) - 1] = '\0'; //remove trailing newline

        //extract token
        Token token;
        for (size_t nRead = TOKENfromStr(expr, &token); expr && nRead;
            expr += nRead, nRead = TOKENfromStr(expr, &token)) {

            //process token
            if (!processToken(token)) {
                STACKoperandStackClear();
                STACKoperatorStackClear();
            }
        }
        if (expr && *expr != '\0') {
            //Non-null expr implies we failed a parse
            fprintf(stderr, "Error: invalid character %c encounted in stream\n", *expr);
            STACKoperandStackClear();
            STACKoperatorStackClear();
        }
        if (!STACKoperandStackEmpty()) {
            NUMERICTOKENshow(STACKoperandStackPop());
            printf("\n");
        }
    }
    return EXIT_SUCCESS; 
 }