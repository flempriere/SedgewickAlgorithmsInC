/**
 * @file ex3_17.c
 * @author Felix Lempriere
 * @brief Solution to Exercise 3-17.
 *
 * Count the number of different (positive) integers less than 1000 that appear
 * in an input stream.
 *
 * @date 2025-04-07
 * @version 0.1
 *
 * @copyright Copyright (c) 2025
 */

#include "MacroLibrary/Defaultfgets.h"
#include "MacroLibrary/NumberParse.h"
#include "MacroLibrary/Utility.h"

#include <stdio.h>
#include <stdlib.h>

/**
 * @brief Maximum length of a line
 *
 */
constexpr size_t MAXLINE = 5u;

/**
 * @brief Largest valid input number
 *
 */
constexpr size_t MAX_NUM = 1000u;

/**
 * @brief Counts the number of different
 * integers less than 1000 that appear in
 * an input stream.
 *
 * Prints out the counts for all non-zero entries
 * after end of input
 *
 * @return EXIT_SUCCESS
 */
int main(int argc, char* argv[argc + 1]) {
    char line[MAXLINE];
    size_t a[MAX_NUM] = {};

    while (FGETS(line)) {
        size_t i;
        if (!NUMPARSE(&i, line) || i > MAX_NUM) continue;
        a[i]++;
    }
    for (register size_t i = 0; i < MAX_NUM; i++) {
        if (a[i]) printf("%4zu:%4zu\n", i, a[i]);
    }
    return read_reached_feof(stdin) ? EXIT_SUCCESS : EXIT_FAILURE;
}