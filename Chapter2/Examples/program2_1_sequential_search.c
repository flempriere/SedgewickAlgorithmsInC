/*
    Program 2.1 Sequential Search

    Checks if a number v is in an array indexed from l to r by scanning
    the array from l to r until v is found or the array is exhausted.

    returns the index of v if found, else SIZE_MAX
 */
#include <stddef.h>
#include <stdint.h>
#include <stdio.h>

#define N 10

size_t search(int v, size_t l, size_t r, int a[r+1]);

int main(int argc, char* argv[argc + 1]) {
    int a[N] = {0,9,1,8,2,7,3,6,4,5};
    for (int i = 0; i <= N; i++) {
        size_t idx = search(i, 0, N-1, a);
        if (idx != SIZE_MAX) {
            printf("v: %d, i: %zu, a[i]: %d\n", i, idx, a[idx]);
        } else {
            printf("v: %d, i: NOT_FOUND\n", i);
        }
    }
}

size_t search(int v, size_t l, size_t r, int a[r+1]) {
    for (; l <= r; l++) {if (v == a[l]) return l;}
    return SIZE_MAX;
}