/*
Exercise 3.17

Count the number of different (positive) integers less than 1000 that appear
in an input stream.

*/

#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>

#define MAXLINE 5
#define MAX_NUM 1000

int main(int argc, char* argv[argc + 1]) {

    char line[MAXLINE];
    size_t a[MAX_NUM] = {};

    while (fgets(line, sizeof(line), stdin) != NULL) {
        size_t i = atoi(line);
        if (i > MAX_NUM) continue;
        a[i]++;
    }
    for (size_t i = 0; i < MAX_NUM; i++) {
        printf("%4zu:%4zu\n", i, a[i]);
    }
    return 0;
}