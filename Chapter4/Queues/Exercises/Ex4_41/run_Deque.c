/**
 * @file run_Deque.c
 * @author Felix Lempriere
 * @brief Reads in a sequence of upper and lower case letters, +, and *,
 * signs and runs the result through a Deque assuming upper case means
 * put at beginning, a lower case means put at end, + means get from
 * the beginning and * means get from the end.
 *
 * @version 0.1
 * @date 2025-03-13
 * 
 * @copyright Copyright (c) 2025
 * 
 */

 #include <ctype.h>
 #include <stdlib.h>
 #include <string.h>
 #include <stdio.h>
 #include "AsciiItem.h"
 #include "Deque_v2.h"

 /**
  * @brief Reads in a sequence of upper and lower case letters, +, and *,
  * signs and runs the result through a Deque assuming upper case means
  * put at beginning, a lower case means put at end, + means get from
  * the beginning and * means get from the end.
  * 
  * @param argc number of arguments.
  * @param argv[1] sequence to run through a Deque. 
  * @return EXIT_SUCCESS on successful run else
  * @return EXIT_FAILURE
  */
 int main(int argc, char* argv[argc]) {
    if (argc != 2) {
        fprintf(stderr, "Error: Usage %s sequence\n", argv[0]);
        return EXIT_FAILURE;
    }
    char* expr = argv[1];
    DEQUEinit(strlen(expr));
    for (char c = *expr++; c != '\0'; c = *expr++) {
        printf("%c\t", c);
        if (isupper(c)) {
            DEQUEput(c, DEQUE_eBEGINNING);
            printf(" \t");
            DEQUEdump();
        }
        else if (islower(c)) {
            DEQUEput(c, DEQUE_eEND);
            printf(" \t");
            DEQUEdump();
        }
        else if (c == '+') {
            Item dest;
            if (DEQUEget(&dest, DEQUE_eBEGINNING)) {
                printf("%c\t", dest);
                DEQUEdump();
            }
        }
        else if (c == '*') {
            Item dest;
            if (DEQUEget(&dest, DEQUE_eEND)) {
                printf("%c\t", dest);
                DEQUEdump();
            }
        }
        else {
            fprintf(stderr, "Error: invalid character encountered");
        }
        printf("\n");
    }
    return EXIT_SUCCESS;
 }