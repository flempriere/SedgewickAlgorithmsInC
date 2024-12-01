/**
 * @file ex3_57.c
 * @author Felix Lempriere
 * @brief Exercise 3.57
 * 
 * Write a program that checks whether a given string is
 * a palindrome, ignoring blanks.
 * @version 0.1
 * @date 2024-12-01
 * 
 * @copyright Copyright (c) 2024
 * 
 */
#include <stdlib.h>
#include <ctype.h>
#include <stdio.h>


/**
 * @brief Checks whether a given string is
 * a palindrome, ignoring blanks.
 * 
 * @param argv[1] string to analyse 
 * @return EXIT_SUCCESS on successful completion else EXIT_FAILURE
 */
int main(int argc, char* argv[argc+1]) {

    if (argc != 2) {
        fprintf(stderr, "Error: Usage %s input_string\n", argv[0]);
        return EXIT_FAILURE;
    }
    char *head = argv[1];
    char *tail = head;

    //find end then walk back
    while (*tail) tail++;
    tail--;
    while(isblank(*head)) head++;
    while(isblank(*tail)) tail--;

    bool palindrome = true;
    while((tail - head) > 0) {
        if (*tail != *head) {
            palindrome = !palindrome;
            break;
        }
        head++;
        while(isblank(*head)) head++;
        tail--;
        while(isblank(*tail)) tail--;
    }

    printf("%s is%s a palindrome\n", argv[1]
        ,(palindrome) ? "" : " not");

    return EXIT_SUCCESS;
}