/**
 * @file ex3_60.c
 * @author Felix Lempriere
 * @brief Write a program that replaces substrings of more
 * than one blank in a given string by exactly one blank;
 * @version 0.1
 * @date 2024-12-01
 * 
 * @copyright Copyright (c) 2024
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

/**
 * @brief Replaces substrings of blanks by a single blank.
 * 
 * We scan backwards from the end of the string, this
 * has an O(n) cost compared to scanning forward, but this
 * means if there are successive long blank substrings each
 * will only be copied when it is reduced to one blank and
 * we don't need to duplicate the string.
 * 
 * @param argc 
 * @param argv 
 * @return int 
 */
int main(int argc, char* argv[argc+1]) {

    if (argc != 2) {
        fprintf(stderr, "Error: Usage %s input_string\n", argv[0]);
        return EXIT_FAILURE;
    }

    char * p = argv[1];

    //move p to the end
    while (*p) p++;
    p--;

    //scan backwards, this reduces the number of copies
    //performed for successive long blanks
    printf("Input string: %s\n", argv[1]);
    while (p != argv[0]) {
        if (isblank(*p)) {
            /* Find end of blank substring
            copy next section forward */
            char* probe = p - 1;
            while(probe != argv[0] && isblank(*probe)) probe--;
            strcpy(probe+1, p);
        }
        p--;
    }
    printf("Condensed string: %s\n", argv[1]);
    return EXIT_SUCCESS;
}