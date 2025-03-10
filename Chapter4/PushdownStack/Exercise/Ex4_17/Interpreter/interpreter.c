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
        
        if (!processToken(token)) {
            fprintf(stderr, "Error encountered in token stream\n");
            return EXIT_FAILURE;
        }
    }
    if (expr && *expr != '\0') {
        //Non-null expr implies we failed a parse
        fprintf(stderr, "Error: invalid character %c encounted in stream\n", *expr);
        return EXIT_FAILURE;
    }
    NUMERICTOKENshow(STACKoperandStackPop());
    printf("\n");
    return EXIT_SUCCESS; 
 }