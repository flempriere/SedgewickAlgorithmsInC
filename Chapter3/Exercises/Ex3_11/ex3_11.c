/*
Program 3.11
    Suppose that a is declared as int a[99], give the array contents after
    the following statements
    for (i = 0; i < 99; i++) a[i] = 98-i;
    for (i = 0; i < 99; i++) a[i] = a[a[i]];
*/

#include <stdio.h>

int main(int argc, char* argv[argc + 1]) {

    int a[99];
    for (size_t i = 0; i < 99; i++) a[i] = 98 - i;
    for (size_t i = 0; i < 99; i++) a[i] = a[a[i]];

    for (size_t i = 0; i < 99; i++) {
        printf("[%zu]", i);
    }
    printf("\n");

    for (size_t i = 0; i < 99; i++) {
        printf("%3d", a[i]);
    }
    printf("\n");
}