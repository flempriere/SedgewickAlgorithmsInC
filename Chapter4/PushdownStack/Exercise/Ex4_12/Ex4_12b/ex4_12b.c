/**
 * @file Ex4_12b.c
 * 
 * @brief Extends Exercise 4.11b to support negation and square root.
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
     token.token = malloc((len+1)*sizeof(typeof(*(token.token)))); //avoiding VLA

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
             Item tok = strdup(token.token); //strdup ported from POSIX in C23
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