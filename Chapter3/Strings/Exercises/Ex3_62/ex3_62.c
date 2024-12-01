/**
 * @file ex3_62.c
 * @author Felix Lempriere
 * @brief Write an efficient program that finds the length
 * of the longest blank substring in a given string, Examining
 * as few characters in the string as possible.
 * 
 * Hint: Your program should get faster as the length of the
 * sequence of blanks increases
 * 
 * @version 0.1
 * @date 2024-12-01
 * 
 * @copyright Copyright (c) 2024
 */

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

/**
 * @brief Maximum size of the text string
 * 
 */
#define N 10000

/**
 * @brief Returns the minimum of two numbers
 * 
 */
#define MIN(x, y) ((x) <= (y)) ? (x) : (y)

/**
 * @brief Returns the maximum of two numbers
 * 
 */
#define MAX(x, y) ((x) >= (y)) ? (x) : (y)

/**
 * @brief Finds the length of the largest subsequence of blanks
 * 
 * @return EXIT_SUCCESS on successful exit, else EXIT_FAILURE
 */
int main(int argc, char* argv[argc+1]) {

    char a[N];
    int t;

    //read in string
    size_t i = 0;
    for (; i < N - 1; a[i] = (char) t, i++) {
        if ((t = getchar()) == EOF) break;
    }
    a[i] = '\0';
    char* b = a;

    size_t len = 0;//longest substring
    size_t cur_len = 0;//
    

    for (size_t j = i; *b && j > 0;) {
        if (isblank(*b)) {
            //if start of blank and len-th char not blank
            //can't be the new longest
            if (!cur_len && !isblank(*(b+len))) {
                b += len;
                j -= len;
            } else {
                //count the blank region
                while(isblank(*b)) {
                    b++;
                    j--;
                    cur_len++;
                }
                len = MAX(len, cur_len);
                cur_len = 0;
            }
        } else if (*b) { //not blank but not terminal
            //if cur + len not blank, longest blank can
            //be is len - 1
            if (!isblank(*(b+len + 1))) {
                b += len + 1;
                j -= len + 1;
            } else {
                b++;
                j--;
            }
        }
        if (j <= len + 1) break; //not enough characters left
    }
    printf("Longest blank subsequence: %zu\n", len);

    return EXIT_SUCCESS;
}
