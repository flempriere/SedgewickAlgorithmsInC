/*
Exercise 3.17

Count the number of different (positive) integers less than 1000 that appear
in an input stream.

*/

#include <stddef.h>
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

    while (fgets(line, sizeof(line), stdin) != NULL) {
        register size_t i = strtoull(line, nullptr, 0);
        if (i > MAX_NUM) continue;
        a[i]++;
    }
    for (register size_t i = 0; i < MAX_NUM; i++) {
        if (a[i]) printf("%4zu:%4zu\n", i, a[i]);
    }
    return EXIT_SUCCESS;
}