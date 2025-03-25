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

#include "../../../../MacroLibrary/Generic.h"

#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>

/**
 * @brief Maximum size of the text string
 *
 */
constexpr size_t N = 10000u;

/**
 * @brief Finds the length of the largest subsequence of blanks
 *
 * @return EXIT_SUCCESS on successful exit, else EXIT_FAILURE
 */
int main(int argc, char* argv[argc + 1]) {
    char a[N] = {};
    register int t;

    // read in string and track size.
    register size_t i = 0;
    for (; i < N - 1; a[i] = (char) t, i++) {
        if ((t = getchar()) == EOF) break;
    }
    a[i] = '\0';
    register const char* b = a;    // pointer to scan a

    register size_t len = 0;        // longest substring
    register size_t cur_len = 0;    //

    for (register size_t j = i; *b && j > 0;) {
        if (isblank(*b)) {
            if (!isblank(*(b + len))) {
                // if b + len not also blank, then can't be the longest blank
                // substring.
                b += (len + 1);
                j -= (len + 1);
            } else {
                while(isblank(*b++)) { //count all blanks.
                    j--;
                    cur_len++;
                }
                len = MAX(len, cur_len);
                cur_len = 0;
            }
        } else if (*b != '\0') {    // not blank but not terminal
            // if cur + len + 1 not blank, longest blank can
            // be is len - 1
            if (!isblank(*(b + len + 1))) {
                b += len + 1;
                j -= len + 1;
            } else {
                b++;
                j--;
            }
        }
        if (j <= len + 1) break;    // not enough characters left
    }
    printf("Longest blank subsequence: %zu\n", len);

    return EXIT_SUCCESS;
}
