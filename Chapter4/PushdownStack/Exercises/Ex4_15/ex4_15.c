/**
 * @file ex4_15.c
 * @author Felix Lempriere
 * @brief Converts a postfix expression to an infix expression
 * @version 0.1
 * @date 2025-03-06
 * 
 * @copyright Copyright (c) 2025
 * 
 */

 #include <stdio.h>
 #include <string.h>
 #include "Token.h"
 #include "Item.h"
 #include "stack.h"

 /**
  * @brief Number of characters need to wrap a term in
  * a left bracket, right bracket, the operator symbol and a null symbol.
  * 
  */
 #define N_CHARS_TO_WRAP_TERM 4

 /**
  * @brief Uses a stack to convert a postfix expression into an infix expression.
  * 
  * @param argc int, number of arguments
  * @param argv[1], char*, postfix expression to convert.
  * 
  * @return EXIT_SUCCESS on success else,
  * @return EXIT_FAILURE
  */
 int main(int argc, char* argv[argc]) {

    if (!(argc == 2)) {
        fprintf(stderr, "Error: Usage %s \"expr\"\n", argv[0]);
        return EXIT_FAILURE;
    }

    char* expr = argv[1];
    size_t len = strlen(expr);
    STACKinit(len);

    //if we have x y + -> (x+y)
    // x y + 2 - -> ((x+y)-2)
    //if we have x ~ -> (-x), so 3*len should be enough memory
    Token token;
    token.token = (malloc((3*len + 1) * sizeof(typeof(*(token.token))))); //avoiding VLA

    for (size_t nRead = TOKENfromStr(expr, &token); expr && nRead; 
        expr += nRead, nRead = TOKENfromStr(expr, &token)) {
        
        if (token.type == TOKEN_TERM) {
            Item term = strdup(token.token); //Ported from Posix in C23
            STACKpush(term);
        }
        else if (token.type == TOKEN_BINARY_OPERATOR || token.type == TOKEN_UNARY_OPERATOR) {
            
            bool isBinary = (token.type == TOKEN_BINARY_OPERATOR);

            Item termAfterOp = STACKpop();
            size_t newTermLength = strlen(termAfterOp) + N_CHARS_TO_WRAP_TERM;

            Item termBeforeOp;
            if (isBinary) {
                termBeforeOp = STACKpop();
                newTermLength += strlen(termBeforeOp);
            }

            Item newTerm = malloc((newTermLength + 1)*sizeof(typeof(*(token.token))));


            strcpy(newTerm, "(");
            if (isBinary) strcat(newTerm, termBeforeOp);
            strcat(newTerm, token.token);
            strcat(newTerm, termAfterOp);
            strcat(newTerm, ")");
            STACKpush(newTerm);

            free(termAfterOp);
            if (isBinary) free(termBeforeOp);
        }
        else {
            fprintf(stderr, "Error: Invalid token type encountered in stream\n");
            return EXIT_FAILURE;
        }
    }
    if (expr && '\0') {
        fprintf(stderr, "Error invalid symbol %c found in tokeniser\n", *expr);
        return EXIT_FAILURE;
    }
    ITEMshow(STACKpop());
    printf("\n");
    return EXIT_SUCCESS;
 }